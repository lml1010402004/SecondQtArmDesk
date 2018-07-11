#include "settingrestore.h"
#include"applications.h"
#include<QApplication>

extern QList<QMainWindow*> *mainwindowlist;


extern QString systemtime;
extern int systembatteryvalue;

settingRestore::settingRestore(QWidget *parent) : QMainWindow(parent)
{
    mainwindowlist->append(this);
    this->setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    this->setFixedHeight(GLOBAL_SCREEN_FIXED_HEIGHT);
    this->setFixedWidth(GLOBAL_SCREEN_FIXED_WIDTH);

    init();


}

settingRestore::~settingRestore()
{
    delete painter,drawsettingrestore,statusbar;
    painter = NULL;
    drawsettingrestore = NULL;
    statusbar = NULL;

}

void settingRestore::mousePressEvent(QMouseEvent *event)
{
   int x= event->x();
   int y = event->y();
   if(SHOWPULLDOWNWINDOWSIGNAL){
     emit showPullDownSignal();
  }else if(RETURNICONPOSITION){
       this->close();
   }else if(RESTOREBUTTON){
       formattingDisk();
   }else if(BACKTOMAINPAGE){
      backToHomePage();
   }
}

/**
 * @brief settingScreen::backToHomePageSlot
 */
void settingRestore::backToHomePage()
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

void settingRestore::paintEvent(QPaintEvent *event)
{
    painter = new QPainter(this);
    rect.setRect(0,0,GLOBAL_SCREEN_FIXED_WIDTH,GLOBAL_SCREEN_FIXED_HEIGHT);
    painter->fillRect(rect,QBrush(Qt::white));

    statusbar->drawBattery(painter,systembatteryvalue);
    statusbar->drawPullDownRectangle(painter);
    statusbar->drawSystemTime(painter,systemtime);
    if(mysyssetting->getConnectWifiMac().length()>0)
    statusbar->drawWifiStatus(painter,true);

    drawsettingrestore->drawHomeIcon(painter);
    drawsettingrestore->drawBackIcon(painter);
    drawsettingrestore->drawRestoreButton(painter);
    drawsettingrestore->drawRestoreTitle(painter);


}

void settingRestore::init()
{
    mysyssetting = new SysSettings;
    statusbar = new StatusBar(this);
    drawsettingrestore = new drawSettingRestore;

    QObject::connect(this,SIGNAL(backToHomePageSignal()),this,SLOT(backTOHomePageSlot()));
QObject::connect(statusbar,SIGNAL(broadcastTimeAndBattery(QString,int)),this,SLOT(updateTimeAndBatteryValue(QString,int)));

}

/**
 * @brief settingRestore::backTOHomePageSlot
 */
void settingRestore::backTOHomePageSlot()
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

void settingRestore::updateTimeAndBatteryValue(QString time, int battery)
{

    QApplication::setScreenUpdateMode(QApplication::EINK_GL16_MODE);//刷新
    systemtime = time;
    systembatteryvalue = battery;
    this->repaint();

}


/**
  格式化磁盘
 * @brief settingRestore::formattingDisk
 */
void settingRestore::formattingDisk()
{
    system("umount /user");
    sleep(1);
    system("mkfs.vfat /dev/block/by-name/UDISK");
    sleep(1);
    system("reboot");

}
