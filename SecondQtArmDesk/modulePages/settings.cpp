#include "settings.h"

#include<QDebug>
#include<QApplication>

extern QString homeiconpath;
extern QList<QMainWindow*> *mainwindowlist;

extern  bool flag_inside_setting;

extern QString systemtime;
extern int systembatteryvalue;

Settings::Settings(QWidget *parent) : QMainWindow(parent)
{
    mainwindowlist->append(this);
    this->setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    this->setFixedHeight(GLOBAL_SCREEN_FIXED_HEIGHT);
    this->setFixedWidth(GLOBAL_SCREEN_FIXED_WIDTH);
    init();

}

/**
 * @brief Settings::~Settings
 */
Settings::~Settings()
{
  delete mydrawsettingmodules,mystatusbar,painter;
    mydrawsettingmodules = NULL;
    mystatusbar = NULL;
    painter =NULL;
}

/**
 * @brief Settings::init
 */
void Settings::init()
{
mysyssetting = new SysSettings;
 mystatusbar = new StatusBar(this);
 mydrawsettingmodules = new drawSettingsModules;

flag_inside_setting = true;
 initConnections();

}

/**
 * @brief Settings::initConnections
 */
void Settings::initConnections()
{
    QObject::connect(this,SIGNAL(backToMainPageSignal()),this,SLOT(backToMainPageSlot()));
QObject::connect(mystatusbar,SIGNAL(broadcastTimeAndBattery(QString,int)),this,SLOT(updateTimeAndBatteryValue(QString,int)));
}





/**
 * @brief Settings::mousePressEvent
 * @param event
 */
void Settings::mousePressEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();
    if(BACKTOMAINPAGE){
       emit backToMainPageSignal();
    }else if(SHOWSETTINGLIGHTITEM){

       emit showLightPageSignal();
       qDebug()<<"light...";
    }else if(SHOWPULLDOWNWINDOWSIGNAL){

       emit showPullDownWindowSignal_setting();
    }else if(SHOWSETTINGSCREENITEM){
       emit showSettingScreenSignal();
         qDebug()<<"screen...";
    }else if(SHOWSETTINGNETWORKITEM){
       emit showSettingNetWorkSignal();
         qDebug()<<"network...";
    }else if(SHOWSETTINGUSBTRANSFREITEM){
       emit showSettingUSBtransferSignal();
         qDebug()<<"usb...";
    }else if(SHOWSETTINGDATEITEM){
       emit showSettingDateSignal();
        qDebug()<<"date...";
    }else if(SHOWSETTINGLANGUAGEITEM){
       emit showSettingLanguageSignal();
        qDebug()<<"language...";
    }else if(SHOWSETTINGRESTOREITEM){
       emit showSettingRestoreSignal();
        qDebug()<<"restore...";
    }else if(SHOWSETTINGABOUTTABLET){
       emit showSettingAboutTabletSignal();
        qDebug()<<"abouttablet...";
    }
}


/**
 * @brief Settings::paintEvent
 * @param event
 */
void Settings::paintEvent(QPaintEvent *event)
{
    painter = new QPainter(this);
    rect.setRect(0,0,GLOBAL_SCREEN_FIXED_WIDTH,GLOBAL_SCREEN_FIXED_HEIGHT);
    painter->fillRect(rect,QBrush(Qt::white));
    mystatusbar->drawBattery(painter,systembatteryvalue);
    mystatusbar->drawSystemTime(painter,systemtime);
    if(mysyssetting->getConnectWifiMac().length()>0)
    mystatusbar->drawWifiStatus(painter,true);
    mystatusbar->drawPullDownRectangle(painter);

    mydrawsettingmodules->drawHomeIconOnSettingPage(painter,homeiconpath);
    mydrawsettingmodules->drawSystemSettingText(painter,QString("SystemSetting"));

    mydrawsettingmodules->drawSettingsItems(painter);

}



void Settings::backToMainPageSlot()
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

void Settings::updateTimeAndBatteryValue(QString time, int battery)
{

    QApplication::setScreenUpdateMode(QApplication::EINK_GL16_MODE);//刷新
    systemtime = time;
    systembatteryvalue = battery;
    this->repaint();
}
