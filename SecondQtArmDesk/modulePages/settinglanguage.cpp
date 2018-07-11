#include "settinglanguage.h"
#include"applications.h"
#include<QApplication>


extern QList<QMainWindow*> *mainwindowlist;

extern QString systemtime;
extern int systembatteryvalue;



settingLanguage::settingLanguage(QWidget *parent) : QMainWindow(parent)
{
    mainwindowlist->append(this);
    this->setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    this->setFixedHeight(GLOBAL_SCREEN_FIXED_HEIGHT);
    this->setFixedWidth(GLOBAL_SCREEN_FIXED_WIDTH);

    init();

}

settingLanguage::~settingLanguage()
{
    delete painter,statusbar,drawsettinglanguage;
    painter = NULL;
    statusbar = NULL;
    drawsettinglanguage = NULL;

}

void settingLanguage::mousePressEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();
    if(SHOWPULLDOWNWINDOWSIGNAL){
        emit showPullDownSignal();
    }else if(BACKTOMAINPAGE){
        emit backToHomePageSlot();
    }else if(RETURNICONPOSITION){
        this->close();
    }else if(SWITCHLANGUAGEITEM){
       myswitchlanguagedialog->show();
    }else if(SWITCHKEYBOARDITEM){

    }

}

void settingLanguage::paintEvent(QPaintEvent *event)
{
    painter= new QPainter(this);

    rect.setRect(0,0,GLOBAL_SCREEN_FIXED_WIDTH,GLOBAL_SCREEN_FIXED_HEIGHT);
    painter->fillRect(rect,QBrush(Qt::white));
    statusbar->drawBattery(painter,systembatteryvalue);
    statusbar->drawPullDownRectangle(painter);
    statusbar->drawSystemTime(painter,systemtime);
    if(mysysseting->getConnectWifiMac().length()>0)
    statusbar->drawWifiStatus(painter,true);

    drawsettinglanguage->drawHomeIcon(painter);
    drawsettinglanguage->drawBackIcon(painter);
    drawsettinglanguage->drawKeyBoardItem(painter);
    drawsettinglanguage->drawLanguageItem(painter);
    drawsettinglanguage->drawLanguageTitle(painter);



}

void settingLanguage::init()
{
    mysysseting = new SysSettings;
    statusbar = new StatusBar(this);
    myswitchlanguagedialog = new switchLanguageDialog(this);
    drawsettinglanguage = new drawSettingLanguage;
    QObject::connect(this,SIGNAL(backToHomePageSignal()),this,SLOT(backToHomePageSlot()));
    QObject::connect(statusbar,SIGNAL(broadcastTimeAndBattery(QString,int)),this,SLOT(updateTimeAndBatteryValue(QString,int)));

}



/**
 * @brief settingLanguage::backToHomePageSlot
 */
void settingLanguage::backToHomePageSlot()
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

void settingLanguage::updateTimeAndBatteryValue(QString time, int battery)
{
    QApplication::setScreenUpdateMode(QApplication::EINK_GL16_MODE);//刷新
    systemtime = time;
    systembatteryvalue = battery;
    this->repaint();

}
