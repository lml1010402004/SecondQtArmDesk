#include "settingdateandtime.h"
#include"applications.h"
#include<QApplication>
#include<QDebug>


extern QList<QMainWindow*> *mainwindowlist;


extern QString systemtime;
extern int systembatteryvalue;


int dateorTime = -1 ;

settingDateAndTime::settingDateAndTime(QWidget *parent) : QMainWindow(parent)
{
    mainwindowlist->append(this);
    this->setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    this->setFixedHeight(GLOBAL_SCREEN_FIXED_HEIGHT);
    this->setFixedWidth(GLOBAL_SCREEN_FIXED_WIDTH);


    init();
}

settingDateAndTime::~settingDateAndTime()
{
    delete painter,statusbar,drawsettingdateandtime;
    painter =NULL;
    statusbar = NULL;
    drawsettingdateandtime = NULL;
}

void settingDateAndTime::paintEvent(QPaintEvent *event)
{
    painter = new QPainter(this);

    rect.setRect(0,0,GLOBAL_SCREEN_FIXED_WIDTH,GLOBAL_SCREEN_FIXED_HEIGHT);
    painter->fillRect(rect,QBrush(Qt::white));

    statusbar->drawBattery(painter,systembatteryvalue);
    statusbar->drawPullDownRectangle(painter);
    statusbar->drawSystemTime(painter,systemtime);
    if(mysyssetting->getConnectWifiMac().length()>0)
        statusbar->drawWifiStatus(painter,true);

    drawsettingdateandtime->drawHomeIcon(painter);
    drawsettingdateandtime->drawBackIcon(painter);
    drawsettingdateandtime->drawDateAndTimeTitle(painter);
    drawsettingdateandtime->drawDateAndTimeItems(painter,mydatemodel);


}

void settingDateAndTime::mousePressEvent(QMouseEvent *event)
{
    int x= event->x();
    int y = event->y();
    if(SHOWPULLDOWNWINDOWSIGNAL){
        emit showPullDownSignal();
    }else if(BACKTOMAINPAGE){
        emit backToHomePageSignal();
    }else if(RETURNICONPOSITION){
        this->close();
    }else if(SETDATEANDHOUR_DATE){
        setdateandhour->show();
        dateorTime =0;
    }else if(SETDATEANDHOUR_HOUR){
        setdateandhour->show();
        dateorTime = 1;
    }
}

void settingDateAndTime::init()
{

    setdateandhour = new setDateAndHour(this);
    mysyssetting = new SysSettings;
    drawsettingdateandtime = new drawSettingDateAndTime;
    statusbar = new StatusBar(this);
    mydatemodel = new dateModel;

    mydatemodel->setTimezone("China");
    mydatemodel->setAutotime(true);
    QStringList list = systemtime.split(" ");
    mydatemodel->setDate(list.at(0));
    mydatemodel->setTimehour(list.at(1));

    QObject::connect(this,SIGNAL(backToHomePageSignal()),this,SLOT(backToHomePageSlot()));
    QObject::connect(statusbar,SIGNAL(broadcastTimeAndBattery(QString,int)),this,SLOT(updateTimeAndBatteryValue(QString,int)));
    QObject::connect(setdateandhour,SIGNAL(updateTimeRightnowSignal()),this,SLOT(updateTimeRightNow()));
    QObject::connect(this,SIGNAL(udpateTimeSignal()),statusbar,SLOT(updateTimeRightNowSlot()));
}



void settingDateAndTime::backToHomePageSlot()
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

void settingDateAndTime::updateTimeAndBatteryValue(QString time, int battery)
{
//    QApplication::setScreenUpdateMode(QApplication::EINK_GL16_MODE);//刷新
    systemtime = time;
    systembatteryvalue = battery;
    mydatemodel->setTimezone("China");
    mydatemodel->setAutotime(true);
    QStringList list = systemtime.split(" ");
    mydatemodel->setDate(list.at(0));
    mydatemodel->setTimehour(list.at(1));
    this->repaint();
}

void settingDateAndTime::updateTimeRightNow()
{
  emit udpateTimeSignal();
    qDebug()<<"settingDateAndTime";
     qDebug()<<"settingDateAndTime";
      qDebug()<<"settingDateAndTime";
}
