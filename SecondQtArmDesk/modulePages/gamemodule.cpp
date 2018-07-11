#include "gamemodule.h"
#include<QDebug>
#include<QApplication>

extern QList<QMainWindow*> *mainwindowlist;
extern QString systemtime;
extern int systembatteryvalue;

GameModule::GameModule(QWidget *widget):QMainWindow(widget)
{

    this->setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    this->setFixedHeight(GLOBAL_SCREEN_FIXED_HEIGHT);
    this->setFixedWidth(GLOBAL_SCREEN_FIXED_WIDTH);

    init();
    mainwindowlist->append(this);

}


/**
 * @brief GameModule::~GameModule
 * deconstructing the objects.
 */
GameModule::~GameModule()
{
    delete painter,statusbar,drawgamepageview;
    painter = NULL;
    statusbar = NULL;
    drawgamepageview =NULL;


}

/**
 * @brief GameModule::paintEvent
 * @param event
 */
void GameModule::paintEvent(QPaintEvent *event)
{
    painter = new QPainter(this);

    rect.setRect(0,0,GLOBAL_SCREEN_FIXED_WIDTH,GLOBAL_SCREEN_FIXED_HEIGHT);
    painter->fillRect(rect,QBrush(Qt::white));

    statusbar->drawBattery(painter,systembatteryvalue);
    if(mysyssetting->getConnectWifiMac().length()>0)
        statusbar->drawWifiStatus(painter,true);
    statusbar->drawSystemTime(painter,systemtime);
    statusbar->drawPullDownRectangle(painter);

    drawgamepageview->drawHomeButton(painter);
    drawgamepageview->drawGames(painter);

}



/**
 * @brief GameModule::mousePressEvent
 * @param event
 */
void GameModule::mousePressEvent(QMouseEvent *event)
{


}

void GameModule::mouseReleaseEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();
    if(SHOWPULLDOWNWINDOWSIGNAL){
        emit showPulldownWindowSignal();
    }else if(BACKTOMAINPAGE){
        emit backToMainpageSignal();
    }

}

void GameModule::init()
{
    mysyssetting = new SysSettings;
    statusbar = new StatusBar(this);
    drawgamepageview = new drawGamePageView;

    QObject::connect(this,SIGNAL(backToMainpageSignal()),this,SLOT(backToMainpageSlot()));
    QObject::connect(statusbar,SIGNAL(broadcastTimeAndBattery(QString,int)),this,SLOT(updateTimeAndBatteryValue(QString,int)));
}



void GameModule::backToMainpageSlot()
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

void GameModule::updateTimeAndBatteryValue(QString time, int battery)
{
    QApplication::setScreenUpdateMode(QApplication::EINK_GL16_MODE);//刷新
    systemtime = time;
    systembatteryvalue = battery;
    this->repaint();
}
