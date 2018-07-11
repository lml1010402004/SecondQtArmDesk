#ifndef SETTINGS_H
#define SETTINGS_H

#include <QMainWindow>
#include"applications.h"
#include<QMouseEvent>
#include<QPaintEvent>
#include<QPainter>
#include"statusbar.h"
#include"statusbar_global.h"
#include"drawViewfunctions/drawsettingsmodules.h"
#include<QDebug>
#include<modulePages/settinglight.h>
#include<modulePages/pulldownwindow.h>
#include"syssettings.h"
#include<QRect>

class Settings : public QMainWindow
{
    Q_OBJECT
public:
    explicit Settings(QWidget *parent = 0);
    ~Settings();

    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);



    void init();
    void initConnections();

private:
    QRect rect;
     SysSettings *mysyssetting;

    QPainter *painter;
    StatusBar *mystatusbar;
    drawSettingsModules *mydrawsettingmodules;



signals:
    void backToMainPageSignal();

    /** show modules signal**/
    void showLightPageSignal();
    void showSettingScreenSignal();
    void showSettingNetWorkSignal();
    void showSettingUSBtransferSignal();
    void showSettingDateSignal();
    void showSettingLanguageSignal();
    void showSettingRestoreSignal();
    void showSettingAboutTabletSignal();
    /***************************/

    void showPullDownWindowSignal_setting();
    void backToMainPageSignal_Signal();


public slots:
    void backToMainPageSlot();
     void updateTimeAndBatteryValue(QString time,int battery);



};

#endif // SETTINGS_H
