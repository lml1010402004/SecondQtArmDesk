#include "settingscreen.h"
#include"applications.h"
#include<QDebug>
#include<QApplication>

extern QList<QMainWindow*> *mainwindowlist;

extern QString systemtime;
extern int systembatteryvalue;

settingScreen::settingScreen(QWidget *parent) : QMainWindow(parent)
{
    mainwindowlist->append(this);
    this->setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    this->setFixedHeight(GLOBAL_SCREEN_FIXED_HEIGHT);
    this->setFixedWidth(GLOBAL_SCREEN_FIXED_WIDTH);

    init();

}


void settingScreen::init()
{
    mysysseting = new SysSettings;
    index_wallpaper =mysysseting->getWallPaper();
   statusbar_screen = new StatusBar(this);
   drawsettingscreen = new drawSettingScreen;

   QObject::connect(this,SIGNAL(backToHomePageSignal()),this,SLOT(backToHomePageSlot()));
QObject::connect(statusbar_screen,SIGNAL(broadcastTimeAndBattery(QString,int)),this,SLOT(updateTimeAndBatteryValue(QString,int)));
}


/**
 * @brief settingScreen::backToHomePageSlot
 */
void settingScreen::backToHomePageSlot()
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

void settingScreen::updateTimeAndBatteryValue(QString time, int battery)
{


    QApplication::setScreenUpdateMode(QApplication::EINK_GL16_MODE);//刷新
    systemtime = time;
    systembatteryvalue = battery;
    this->repaint();

}


settingScreen::~settingScreen()
{
    delete statusbar_screen,painter,drawsettingscreen;
    statusbar_screen = NULL;
    drawsettingscreen = NULL;
    painter = NULL;

}

void settingScreen::mousePressEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();
    if(SHOWPULLDOWNWINDOWSIGNAL){
       emit showPullDownSignal();
    }else if(BACKTOMAINPAGE){
       emit backToHomePageSignal();
    }else if(RETURNICONPOSITION){
        this->close();
    }else if(SELECTINDEXWALLPAPER0){
index_wallpaper = 0;
mysysseting->setWallPaper(0);
qDebug()<<"mysysseting.getWallPaper()=="<<mysysseting->getWallPaper();
repaint();
    }else if(SELECTINDEXWALLPAPER1){
index_wallpaper = 1;
mysysseting->setWallPaper(1);
qDebug()<<"mysysseting.getWallPaper()=="<<mysysseting->getWallPaper();
repaint();
    }else if(SELECTINDEXWALLPAPER2){
index_wallpaper = 2;
mysysseting->setWallPaper(2);
qDebug()<<"mysysseting.getWallPaper()=="<<mysysseting->getWallPaper();
repaint();
    }

}

void settingScreen::paintEvent(QPaintEvent *event)
{

 painter = new QPainter(this);
 rect.setRect(0,0,GLOBAL_SCREEN_FIXED_WIDTH,GLOBAL_SCREEN_FIXED_HEIGHT);
 painter->fillRect(rect,QBrush(Qt::white));


 statusbar_screen->drawBattery(painter,systembatteryvalue);
 statusbar_screen->drawSystemTime(painter,systemtime);
 if(mysysseting->getConnectWifiMac().length()>0)
 statusbar_screen->drawWifiStatus(painter,true);
 statusbar_screen->drawPullDownRectangle(painter);

 drawsettingscreen->drawHomeIcon(painter);

 drawsettingscreen->drawBackIcon(painter);

 drawsettingscreen->drawWallPapaerItem(painter,index_wallpaper);


}

