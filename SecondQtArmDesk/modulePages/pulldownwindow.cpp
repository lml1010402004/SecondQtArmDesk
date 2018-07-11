#include "pulldownwindow.h"
#include<QApplication>
#include"applications.h"


QString light_icon1 = ":/mypic/pics/light_icon.png";
QString pathgroup1[3] = {":/mypic/pics/wifi1_icon.png",":/mypic/pics/setting_icon.png",":/mypic/pics/search_icon.png"};

extern QString systemtime;
extern int systembatteryvalue;

extern QList<QMainWindow*> *mainwindowlist;

pullDownWindow::pullDownWindow(QWidget *parent) : QMainWindow(parent)
{
     mainwindowlist->append(this);
     this->setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
     this->setFixedHeight(GLOBAL_SCREEN_FIXED_HEIGHT);
     this->setFixedWidth(GLOBAL_SCREEN_FIXED_WIDTH);
     this->setAttribute(Qt::WA_TranslucentBackground,true);
     init();

     initConnections();

}


/**
 * @brief pullDownWindow::~pullDownWindow
 */
pullDownWindow::~pullDownWindow()
{
 delete painter,pullwindow,statusbar,pathlist1;
    painter = NULL;
    pullwindow = NULL;
    statusbar = NULL;


}


/**
 * @brief pullDownWindow::paintEvent
 * @param event
 */
void pullDownWindow::paintEvent(QPaintEvent *event)
{

    painter = new QPainter(this);

    pullwindow->drawCloseIcon(painter);
    pullwindow->drawgrayArea(painter,100);
    pullwindow->drawShutcutArea(painter);
    pullwindow->drawCloseIcon(painter);

    pullwindow->drawShortcutIcons(painter,pathlist1);
    pullwindow->drawLightShoutcutAndProgressBar(painter,light_icon1,light_value);

    statusbar->drawSystemTime(painter,systemtime);

    if(mysyssetting->getConnectWifiMac().length()>0){
    statusbar->drawWifiStatus(painter,true);
    }
    statusbar->drawBattery(painter,systembatteryvalue);


}


/**
 * @brief pullDownWindow::mousePressEvent
 * @param event
 */
void pullDownWindow::mousePressEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();

    if(CLOSESHUTCUTWINDOWSIGNAL){
       emit closeShutcutWindowSignal();
    }else if(SHOWSETTINGMODULE){
       emit showSettingModuleSignal();
    }else if(ADJUSTLIGHTPROGRESSBAR){
        light_value = returnLightValue(x);
        mylcd_backlight->setLight(light_value);
        QApplication::setScreenUpdateMode(QApplication::EINK_GC16_LOCAL_MODE);//刷新

    }else if(SHOWSEARCHRESULTMODULE){
      emit showSearchResultBookSignal();
    }else if(SHOWWIFIMODULE){
        emit showWifiModuleSignal();
    }

}

void pullDownWindow::mouseMoveEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();
    if(ADJUSTLIGHTPROGRESSBAR){
        light_value = returnLightValue(x);

        QApplication::setScreenUpdateMode(QApplication::EINK_GC16_LOCAL_MODE);//刷新

    }

}

void pullDownWindow::mouseReleaseEvent(QMouseEvent *event)
{

    rect.setX(175);
    rect.setY(170);
    rect.setWidth(300);
    rect.setHeight(20);
    repaint(rect);
    mylcd_backlight->enableLight();
    mylcd_backlight->setLight(light_value);

}



void pullDownWindow::init()
{
    mysyssetting = new SysSettings;


    light_value = 0;

    pathlist1.clear();
  for(int i=0;i<3;i++){
    pathlist1.append(pathgroup1[i]);
  }

    pullwindow = new drawpulldonwwindow;
    statusbar = new StatusBar(this);

    mylcd_backlight = new Lcd_backlight();

}

void pullDownWindow::initConnections()
{
 QObject::connect(this,SIGNAL(closeShutcutWindowSignal()),this,SLOT(closeShutcutWindowSlot()));
 // QObject::connect(this,SIGNAL(showSettingModuleSignal()),this,SLOT(showSettingModuleSlot()));

QObject::connect(statusbar,SIGNAL(broadcastTimeAndBattery(QString,int)),this,SLOT(updateTimeAndBatteryValue(QString,int)));
}

/**
  input progress on the bar ,output the value of the light.
 * @brief pullDownWindow::returnLightValue
 * @param progress
 * @return
 */
int pullDownWindow::returnLightValue(int progress)
{
    //line.setLine(175,180,475,180); progress between 175-475
    int tempValue = (progress-175)/3;
    if((progress-175)%3!=0){
        tempValue++;
    }
    return tempValue;
}


/**
 * @brief pullDownWindow::closeShutcutWindowSlot
 */
void pullDownWindow::closeShutcutWindowSlot()
{
    this->close();
}

void pullDownWindow::updateTimeAndBatteryValue(QString time, int battery)
{
    QApplication::setScreenUpdateMode(QApplication::EINK_GL16_MODE);//刷新
    systemtime = time;
    systembatteryvalue = battery;
    this->repaint();
}


