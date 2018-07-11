#include "bookonline.h"
#include<QList>
#include<QDebug>
#include<QApplication>

extern QList<QMainWindow*> *mainwindowlist;


extern QString systemtime;
extern int systembatteryvalue;



/**
 * @brief BookOnLine::BookOnLine
 * @param widget
 */
BookOnLine::BookOnLine(QWidget *widget):QMainWindow(widget)
{

    this->setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    this->setFixedHeight(GLOBAL_SCREEN_FIXED_HEIGHT);
    this->setFixedWidth(GLOBAL_SCREEN_FIXED_WIDTH);
    init();
    mainwindowlist->append(this);
}


/**
 * @brief BookOnLine::~BookOnLine
 * deconstructor method for deconstructing the objects.
 */
BookOnLine::~BookOnLine()
{
    delete painter,statusbar,drawbookonlinepageview;
    painter =NULL;
    statusbar = NULL;
    drawbookonlinepageview = NULL;

}

void BookOnLine::paintEvent(QPaintEvent *event)
{
    painter = new QPainter(this);
    rect.setRect(0,0,GLOBAL_SCREEN_FIXED_WIDTH,GLOBAL_SCREEN_FIXED_HEIGHT);
    painter->fillRect(rect,QBrush(Qt::white));

    statusbar->drawBattery(painter,systembatteryvalue);
    statusbar->drawSystemTime(painter,systemtime);
    if(mysyssetting->getConnectWifiMac().length()>0){
    statusbar->drawWifiStatus(painter,true);
    }
    statusbar->drawPullDownRectangle(painter);

    drawbookonlinepageview->drawHomeButton(painter,true);
    drawbookonlinepageview->drawBookOnline(painter);



}

void BookOnLine::mousePressEvent(QMouseEvent *event)
{

}

void BookOnLine::mouseReleaseEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();
    if(SHOWPULLDOWNWINDOWSIGNAL){
        emit showPulldownWindowSignal();
    }else if(BACKTOMAINPAGE){
        emit backToMainpageSignal();
    }

}

/**
 * @brief BookOnLine::init
 */
void BookOnLine::init()
{
    mysyssetting = new SysSettings;
    statusbar = new StatusBar(this);
drawbookonlinepageview = new drawBookOnlinePageView;


    initConnections();
}


/**
 * @brief BookOnLine::initConnections
 */
void BookOnLine::initConnections()
{
    QObject::connect(this,SIGNAL(backToMainpageSignal()),this,SLOT(backToMainpageSlot()));
    QObject::connect(statusbar,SIGNAL(broadcastTimeAndBattery(QString,int)),this,SLOT(updateTimeAndBatteryValue(QString,int)));
    QObject::connect(statusbar,SIGNAL(broadcastTimeAndBattery(QString,int)),this,SLOT(updateTimeAndBatteryValue(QString,int)));
}


/**
 * @brief BookOnLine::backToMainpageSlot
 */
void BookOnLine::backToMainpageSlot()
{

    int size = mainwindowlist->size();
    if(size>0){
        for(int i=0;i<size;i++){
             if(mainwindowlist->at(i)!=NULL){
                 mainwindowlist->at(i)->close();
             }

        }
    }
}

void BookOnLine::updateTimeAndBatteryValue(QString time, int battery)
{

    QApplication::setScreenUpdateMode(QApplication::EINK_GL16_MODE);//刷新
    systemtime = time;
    systembatteryvalue = battery;
    this->repaint();
}
