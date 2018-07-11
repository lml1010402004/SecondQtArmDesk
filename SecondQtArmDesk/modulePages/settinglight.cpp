#include "settinglight.h"
//#include"modulePages/pulldownwindow.h"
#include"applications.h"
#include<QApplication>


extern QList<QMainWindow*> *mainwindowlist;
extern int light_value;

extern QString systemtime;
extern int systembatteryvalue;


SettingLight::SettingLight(QWidget *parent) : QMainWindow(parent)
{
   mainwindowlist->append(this);
   this->setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
   this->setFixedHeight(GLOBAL_SCREEN_FIXED_HEIGHT);
   this->setFixedWidth(GLOBAL_SCREEN_FIXED_WIDTH);

   init();

}

SettingLight::~SettingLight()
{
    delete statusbarlight,drawsettinglight,painter;
    statusbarlight = NULL;
    drawsettinglight = NULL;
    painter = NULL;
}



/**
 * @brief SettingLight::mousePressEvent
 * @param event
 */
void SettingLight::mousePressEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();
    if(BACKTOMAINPAGE){
        emit backToHomePageSignal();
    }else if(SHOWPULLDOWNWINDOWSIGNAL){
        emit showPullDownSignal();
    }else if(RETURNICONPOSITION){
         this->close();
    }else if(ADJUSTLIGHTPROGRESSBARSETTING){
        light_value = returnLightValue(x);
        mylcd_backlight->enableLight();
        mylcd_backlight->setLight(light_value);
        QApplication::setScreenUpdateMode(QApplication::EINK_GC16_LOCAL_MODE);//刷新
    }

}


/**
  input progress on the bar ,output the value of the light.
 * @brief pullDownWindow::returnLightValue
 * @param progress
 * @return
 */
int SettingLight::returnLightValue(int progress)
{

    int tempValue = (progress-130)/4;
    if((progress-130)%4!=0){
        tempValue++;
    }
    return tempValue;
}



/**
 * @brief SettingLight::paintEvent
 * @param event
 */
void SettingLight::paintEvent(QPaintEvent *event)
{
    painter = new QPainter(this);
    rect.setRect(0,0,GLOBAL_SCREEN_FIXED_WIDTH,GLOBAL_SCREEN_FIXED_HEIGHT);
    painter->fillRect(rect,QBrush(Qt::white));

    statusbarlight->drawBattery(painter,systembatteryvalue);
    if(mysysseting->getConnectWifiMac().length()>0)
    statusbarlight->drawWifiStatus(painter,true);
    statusbarlight->drawSystemTime(painter,systemtime);
    statusbarlight->drawPullDownRectangle(painter);
    drawsettinglight->drawHomeButton(painter);
    drawsettinglight->drawProgressBar(painter,light_value);
    drawsettinglight->drawLightTitle(painter);
    drawsettinglight->drawBackIcon(painter);

}

void SettingLight::mouseMoveEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();
    if(ADJUSTLIGHTPROGRESSBARSETTING){
        light_value = returnLightValue(x);
           mylcd_backlight->setLight(light_value);
        QApplication::setScreenUpdateMode(QApplication::EINK_GC16_LOCAL_MODE);//刷新
    }

}

void SettingLight::mouseReleaseEvent(QMouseEvent *event)
{

    rect.setX(130);
    rect.setY(240);
    rect.setWidth(400);
    rect.setHeight(20);
    repaint(rect);
}

void SettingLight::init()
{
    mysysseting = new SysSettings;
    statusbarlight = new StatusBar(this);
    drawsettinglight = new drawSettingLight;

    mylcd_backlight = new Lcd_backlight;

    initConnections();

}

void SettingLight::initConnections()
{
  QObject::connect(this,SIGNAL(backToHomePageSignal()),this,SLOT(backToHomePageSlot()));
//  QObject::connect(this,SIGNAL(showPullDownSignal()),this,SLOT(showPullDownSlot()));
QObject::connect(statusbarlight,SIGNAL(broadcastTimeAndBattery(QString,int)),this,SLOT(updateTimeAndBatteryValue(QString,int)));
}


/**
 * @brief SettingLight::backToHomePageSlot
 */
void SettingLight::backToHomePageSlot()
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



/**
 * @brief SettingLight::showPullDownSlot
 */
void SettingLight::showPullDownSlot()
{
    // mypullwindows->show();
}

void SettingLight::updateTimeAndBatteryValue(QString time, int battery)
{
    QApplication::setScreenUpdateMode(QApplication::EINK_GL16_MODE);//刷新
    systemtime = time;
    systembatteryvalue = battery;
    this->repaint();
}

