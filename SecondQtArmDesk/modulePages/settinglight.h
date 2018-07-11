#ifndef SETTINGLIGHT_H
#define SETTINGLIGHT_H

#include <QDialog>
#include<QPainter>
#include<QPaintEvent>
#include<QMouseEvent>
#include<QMainWindow>
#include"applications.h"
#include"statusbar.h"
#include"statusbar_global.h"
#include"drawViewfunctions/drawsettinglight.h"
#include"syssettings.h"
#include<QDebug>
#include<QRect>

class pullDownWindow;

class SettingLight : public QMainWindow
{
    Q_OBJECT
public:
    explicit SettingLight(QWidget *parent = 0);
    ~SettingLight();
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    int returnLightValue(int progress);



private:

    void init();
    void initConnections();

private:

     SysSettings *mysysseting;

    QPainter *painter;
    StatusBar *statusbarlight;
    drawSettingLight *drawsettinglight;
    pullDownWindow* mypullwindows;
    Lcd_backlight *mylcd_backlight;
    QRect rect;
    int light_value;


signals:
    void backToHomePageSignal();
    void showPullDownSignal();

public slots:
    void backToHomePageSlot();
    void showPullDownSlot();
     void updateTimeAndBatteryValue(QString time,int battery);
};

#endif // SETTINGLIGHT_H
