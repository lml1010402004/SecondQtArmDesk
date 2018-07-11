#include "settingnetwork.h"
#include"applications.h"
#include<QDebug>
#include<QApplication>

extern QList<QMainWindow*> *mainwindowlist;

extern QString systemtime;
extern int systembatteryvalue;


settingNetWork::settingNetWork(QWidget *parent) : QMainWindow(parent)
{

    mainwindowlist->append(this);
    this->setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    this->setFixedHeight(GLOBAL_SCREEN_FIXED_HEIGHT);
    this->setFixedWidth(GLOBAL_SCREEN_FIXED_WIDTH);

    init();

}

settingNetWork::~settingNetWork()
{
    delete painter,statusbar,drawsettingnetwork;
    painter =NULL;
    statusbar = NULL;
    drawsettingnetwork = NULL;

}

void settingNetWork::mousePressEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();
    if(SHOWPULLDOWNWINDOWSIGNAL){
        emit showPullDownSignal();
    }else if(BACKTOMAINPAGE){
        emit backToHomePageSignal();
    }else if(RETURNICONPOSITION){
        this->close();
        if(connectwifidialog!=NULL){
            connectwifidialog->close();
        }
    }else if(SWITCH_WIFI){
        wifi_state = !wifi_state;
        if(wifi_state){
            if(mywifiservice->isEnabled()){
                mywifiservice->doScan();
                mywifiservice->refreshWifiList();


            }else{
                mywifiservice->setEnable(true);
            }
        }else{
            mywifiservice->setEnable(false);
            wifilist->clear();
            mysyssetting->setConnectWifiMac("");
        }
        repaint();
    }else if(WIFINEXTPAGE){
        if(wifiCurrentPage<wifiTotalPages){
            wifiCurrentPage++;
        }
        repaint();
    }else if(WIFILASTPAGE){
        if(wifiCurrentPage>1){
            wifiCurrentPage--;
        }
        repaint();
    }else if(WIFIITEM1){

        int index0 = (wifiCurrentPage-1)*4;
        if(wifilist->size()>index0){
            targetWifiMac = wifilist->at(index0)->WIFI_MAC;
            indexForPosition =index0;
            connectwifidialog->show();
        }

    }else if(WIFIITEM2){

        int index2 = (wifiCurrentPage-1)*4;
        if(wifilist->size()>index2+1){
            targetWifiMac = wifilist->at(index2+1)->WIFI_MAC;
            indexForPosition=index2+1;
            connectwifidialog->show();
        }

    }else if(WIFIITEM3){

        int index1 = (wifiCurrentPage-1)*4;
        if(wifilist->size()>index1+2){
            targetWifiMac = wifilist->at(index1+2)->WIFI_MAC;
            indexForPosition=index1+2;
            connectwifidialog->show();
        }

    }else if(WIFIITEM4){

        int index = (wifiCurrentPage-1)*4;
        if(wifilist->size()>index+3){
            targetWifiMac = wifilist->at(index+3)->WIFI_MAC;
            indexForPosition=index+3;
            connectwifidialog->show();
        }

    }

}

void settingNetWork::paintEvent(QPaintEvent *event)
{
    painter = new QPainter(this);

    rect.setRect(0,0,GLOBAL_SCREEN_FIXED_WIDTH,GLOBAL_SCREEN_FIXED_HEIGHT);
    painter->fillRect(rect,QBrush(Qt::white));

    statusbar->drawBattery(painter,systembatteryvalue);
    statusbar->drawPullDownRectangle(painter);
    statusbar->drawSystemTime(painter,systemtime);
    if(mysyssetting->getConnectWifiMac().length()>2){
        statusbar->drawWifiStatus(painter,true);
    }

    drawsettingnetwork->drawHomeIcon(painter);
    drawsettingnetwork->drawBackIcon(painter);
    drawsettingnetwork->drawWifiTitle(painter);
    drawsettingnetwork->drawWifiSwitch(painter,wifi_state);
    drawsettingnetwork->drawWifiSerachText(painter);

    drawsettingnetwork->drawCurrentWifiItems(painter,wifilist,wifiCurrentPage,wifiTotalPages);

}

void settingNetWork::init()
{
    indexForPosition =-1;
    targetWifiMac = "";
    wifi_state = false;
    wifiCurrentPage = 1;
    wifiTotalPages = 1;
    statusbar = new StatusBar(this);
    drawsettingnetwork = new drawSettingNetwork;
    connectwifidialog = new connectWifiDialog(this);
    mysyssetting = new SysSettings;


    mywifiservice = WifiService::getInstance();


    QObject::connect(this,SIGNAL(backToHomePageSignal()),this,SLOT(backToHomePageSlot()));
    mywifiservice->connect(mywifiservice,SIGNAL(sigStatusChanged(QString)),this,SLOT(wifi_StatusChanged(QString)));
    mywifiservice->connect(mywifiservice,SIGNAL(sigRefreshed(QList<TWifi>)),this,SLOT(wifi_RefreshDone(QList<TWifi>)));
    QObject::connect(connectwifidialog,SIGNAL(connectWifiSignal(QString)),this,SLOT(connectWifiSlot(QString)));
    QObject::connect(statusbar,SIGNAL(broadcastTimeAndBattery(QString,int)),this,SLOT(updateTimeAndBatteryValue(QString,int)));

    //    if(mywifiservice->isEnabled()){
    //        mywifiservice->doScan();
    //    }else{
    //        mywifiservice->setEnable(true);
    //    }
    wifilist = new QList<wifiItem*>;

}

void settingNetWork::backToHomePageSlot()
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

void settingNetWork::wifi_StatusChanged(QString wifiStatus)
{
    qDebug() << "================== wifi_StatusChanged";
    qDebug() << "================== current wifi status: " << wifiStatus;

    if(wifiStatus.indexOf(QString("SCANNING")) != -1)
    {

    }
    else if(wifiStatus.indexOf(QString("ASSOCIATING")) != -1)
    {


    }
    else if( wifiStatus.indexOf(QString("INACTIVE")) != -1)
    {

    }
    else if(wifiStatus.indexOf(QString("WAY_HANDSHAKE")) != -1)
    {

    }
    else if(wifiStatus.indexOf(QString("COMPLETED")) != -1)
    {
        this->repaint();
    }
    else if(wifiStatus.indexOf(QString("CONNECTED")) != -1)
    {
        qDebug()<<"wifi connect successfully!!!";
        mysyssetting->setConnectWifiMac(targetWifiMac);
        this->repaint();

    }
    else if(wifiStatus.indexOf(QString("DISCONNECTED")) != -1)
    {
        qDebug()<<"wifi disconnect successfully!!!";
        mysyssetting->setConnectWifiMac("");
        this->repaint();

    }
    else if(wifiStatus.indexOf(QString("INTERFACE_DISABLED")) != -1)
    {

    }
    else
    {

    }


}


wifiItem *tempitem;
void settingNetWork::wifi_RefreshDone(QList<TWifi> wifi_Lists)
{


    int size = wifi_Lists.length();

    if(size<0){
        return;
    }
    wifilist->clear();
    for(int i=0;i<size;i++){
        tempitem = new wifiItem;
        tempitem->wifi_name = wifi_Lists.at(i).ESSID_NAME;
        tempitem->state_text = wifi_Lists.at(i).ESSID_STATUS;
        tempitem->strength_class = wifi_Lists.at(i).ESSID_SIGNAL;
        tempitem->Encrypt = wifi_Lists.at(i).ESSID_ENCRYP;
        tempitem->WIFI_MAC = wifi_Lists.at(i).ESSID_BSSID;
        wifilist->append(tempitem);
    }
    if(wifilist->size()%4==0){
        wifiTotalPages = wifilist->size()/4;
    }else{
        wifiTotalPages = wifilist->size()/4+1;
    }
    repaint();

}

void settingNetWork::connectWifiSlot(QString password)
{

    connectwifidialog->close();

    if(mywifiservice==NULL){
        return;
    }
    bool flag =  WifiService::getInstance(this)->setCurrentWifi(targetWifiMac,password);
    qDebug()<<"connect wifi is okay or not==="<<flag;
    if(flag){
        mysyssetting->setConnectWifiMac(targetWifiMac);
        this->repaint();
    }else{
        mysyssetting->setConnectWifiMac("");
    }


}

void settingNetWork::updateTimeAndBatteryValue(QString time, int battery)
{
    QApplication::setScreenUpdateMode(QApplication::EINK_GL16_MODE);//刷新
    systemtime = time;
    systembatteryvalue = battery;
    this->repaint();

}
