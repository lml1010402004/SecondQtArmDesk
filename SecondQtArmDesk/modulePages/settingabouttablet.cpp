#include "settingabouttablet.h"

#include"applications.h"
#include"utils/commonutils.h"
#include<QApplication>

extern QList<QMainWindow*> *mainwindowlist;
extern QString systemtime;
extern int systembatteryvalue;

SettingAboutTablet::SettingAboutTablet(QWidget *parent) : QMainWindow(parent)
{
    mainwindowlist->append(this);
    this->setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    this->setFixedHeight(GLOBAL_SCREEN_FIXED_HEIGHT);
    this->setFixedWidth(GLOBAL_SCREEN_FIXED_WIDTH);

    init();

}

SettingAboutTablet::~SettingAboutTablet()
{
    delete painter,statusbar,drawsettingabouttablet;
    painter= NULL;
    statusbar = NULL;
    drawsettingabouttablet = NULL;
}

void SettingAboutTablet::paintEvent(QPaintEvent *event)
{
    painter = new QPainter(this);

    rect.setRect(0,0,GLOBAL_SCREEN_FIXED_WIDTH,GLOBAL_SCREEN_FIXED_HEIGHT);
    painter->fillRect(rect,QBrush(Qt::white));

    statusbar->drawBattery(painter,systembatteryvalue);
    statusbar->drawPullDownRectangle(painter);
    statusbar->drawSystemTime(painter,systemtime);
    if(mysyssetting->getConnectWifiMac().length()>0)
        statusbar->drawWifiStatus(painter,true);
    drawsettingabouttablet->drawHomeIcon(painter);
    drawsettingabouttablet->drawBackIcon(painter);

    drawsettingabouttablet->drawAboutTableTitle(painter);
    drawsettingabouttablet->drawInfoAboutTablet(painter,"YT101010",commonUtils::GetLocalMac(),QString("8G"),"Yitoa_V2");

}

void SettingAboutTablet::mousePressEvent(QMouseEvent *event)
{
    int x= event->x();
    int y = event->y();
    if(SHOWPULLDOWNWINDOWSIGNAL){
        emit showPullDownSignal();
    }else if(BACKTOMAINPAGE){
        emit backToHomePageSignal();
    }else if(RETURNICONPOSITION){
        this->close();
    }

}

void SettingAboutTablet::init()
{
    mysyssetting = new SysSettings;
    statusbar = new StatusBar(this);
    drawsettingabouttablet = new drawSettingAboutTablet;
    QObject::connect(this,SIGNAL(backToHomePageSignal()),this,SLOT(backToHomePageSlot()));
    QObject::connect(statusbar,SIGNAL(broadcastTimeAndBattery(QString,int)),this,SLOT(updateTimeAndBatteryValue(QString,int)));
}


/**
 * @brief SettingAboutTablet::backToHomePageSlot
 */
void SettingAboutTablet::backToHomePageSlot()
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

void SettingAboutTablet::updateTimeAndBatteryValue(QString time, int battery)
{
    QApplication::setScreenUpdateMode(QApplication::EINK_GL16_MODE);//刷新
    systemtime = time;
    systembatteryvalue = battery;
    this->repaint();

}
