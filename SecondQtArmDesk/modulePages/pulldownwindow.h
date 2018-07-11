#ifndef PULLDOWNWINDOW_H
#define PULLDOWNWINDOW_H

#include <QMainWindow>
#include<QPaintEvent>
#include<QBrush>
#include<QPainter>
#include<QMouseEvent>
#include<QRect>
#include<QList>
#include<QString>
#include <drawViewfunctions/drawpulldonwwindow.h>
#include"applications.h"
#include"statusbar.h"
#include"statusbar_global.h"
#include<QDebug>
#include"modulePages/settings.h"
#include"syssettings.h"



class pullDownWindow : public QMainWindow
{
    Q_OBJECT
public:
    pullDownWindow(QWidget *parent = 0);
    ~pullDownWindow();
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);


    void init();
    void initConnections();

private:

    SysSettings *mysyssetting;

    QBrush brush;
    QPainter *painter;
    QRect rect;
    drawpulldonwwindow *pullwindow;
    StatusBar *statusbar;

    QList<QString> pathlist1;
    Lcd_backlight *mylcd_backlight;
   int light_value;


    int returnLightValue(int progress);





signals:
    void closeShutcutWindowSignal();
    void showSettingModuleSignal();
    void showSearchResultBookSignal();
    void showWifiModuleSignal();


public slots:
    void closeShutcutWindowSlot();
      void updateTimeAndBatteryValue(QString time,int battery);


};

#endif // PULLDOWNWINDOW_H
