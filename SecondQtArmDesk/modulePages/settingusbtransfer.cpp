#include "settingusbtransfer.h"
#include"applications.h"
#include"database/database.h"
#include<QApplication>



extern QList<QMainWindow*> *mainwindowlist;
const QString TARGETDIREC = "/user/";


extern QString systemtime;
extern int systembatteryvalue;

extern QList<localDirectoryItem> filelist;



settingUSBTransfer::settingUSBTransfer(QWidget *parent) : QMainWindow(parent)
{
    mainwindowlist->append(this);
    this->setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    this->setFixedHeight(GLOBAL_SCREEN_FIXED_HEIGHT);
    this->setFixedWidth(GLOBAL_SCREEN_FIXED_WIDTH);

    init();

}

settingUSBTransfer::~settingUSBTransfer()
{
   delete painter,statubar,drawsettingusbtransfer;
    painter = NULL;
    drawsettingusbtransfer =NULL;
    statubar = NULL;

}

void settingUSBTransfer::mousePressEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();
    if(SHOWPULLDOWNWINDOWSIGNAL){
        emit showPullDownSignal();
    }else if(BACKTOMAINPAGE){
        emit backToHomePageSlot();
    }else if(RETURNICONPOSITION){
        this->close();
    }else if(USBTRANSFERDATA){
        if(!usbservice->isEnabled()){
         usbservice->setEnable(true);

        }


   }else if(USBTRANSFERCHARGE){

    QList<localDirectoryItem> list = Database::getInstance()->getAllFileInTheTargetDirectory(TARGETDIREC);
    qDebug()<<"usbTransfer=list.size()=="<<list.size();
 if(list.size()>0){//保证在打开路径下是有新文件来插入的.
    Database::getInstance()->insertDataToYitoaDataBase(list);
    filelist.clear();
    emit updateTheBookDataSignal();
    }
    usbservice->setEnable(false);
    this->close();
}


}

void settingUSBTransfer::paintEvent(QPaintEvent *event)
{

    painter = new QPainter(this);

    rect.setRect(0,0,GLOBAL_SCREEN_FIXED_WIDTH,GLOBAL_SCREEN_FIXED_HEIGHT);
    painter->fillRect(rect,QBrush(Qt::white));

    statubar->drawBattery(painter,systembatteryvalue);
    statubar->drawPullDownRectangle(painter);
    if(mysyssetting->getConnectWifiMac().length()>0)
    statubar->drawWifiStatus(painter,true);
    statubar->drawSystemTime(painter,systemtime);

    drawsettingusbtransfer->drawHomeIcon(painter);
    drawsettingusbtransfer->drawBackIcon(painter);
    drawsettingusbtransfer->drawUSBTransferButton(painter);

    drawsettingusbtransfer->drawStateofUSBConnectedPc(painter);
    drawsettingusbtransfer->drawUSBTransferTitle(painter);
    drawsettingusbtransfer->drawButtonsOfUSBConnected(painter);

}

void settingUSBTransfer::init()
{
    statubar = new StatusBar(this);
mysyssetting = new SysSettings;

    usbservice = UsbService::getInstance(this);


    drawsettingusbtransfer = new drawSettingUsbTransfer;

    QObject::connect(this,SIGNAL(backToHomePageSignal()),this,SLOT(backToHomePageSlot()));
QObject::connect(statubar,SIGNAL(broadcastTimeAndBattery(QString,int)),this,SLOT(updateTimeAndBatteryValue(QString,int)));
}

/**
 * @brief settingUSBTransfer::backToHomePageSlot
 */
void settingUSBTransfer::backToHomePageSlot()
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

void settingUSBTransfer::updateTimeAndBatteryValue(QString time, int battery)
{
    QApplication::setScreenUpdateMode(QApplication::EINK_GL16_MODE);//刷新
    systemtime = time;
    systembatteryvalue = battery;
    this->repaint();

}

