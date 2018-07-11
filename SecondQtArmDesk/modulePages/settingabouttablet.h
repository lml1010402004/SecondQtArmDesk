#ifndef SETTINGABOUTTABLET_H
#define SETTINGABOUTTABLET_H

#include <QMainWindow>
#include<QPaintEvent>
#include<QMouseEvent>
#include<QPainter>
#include<statusbar.h>
#include"statusbar_global.h"
#include"drawViewfunctions/drawsettingabouttablet.h"
#include"syssettings.h"
#include<QRect>



class SettingAboutTablet : public QMainWindow
{
    Q_OBJECT
public:
    explicit SettingAboutTablet(QWidget *parent = 0);
    ~SettingAboutTablet();
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void init();

private:

    StatusBar *statusbar;
    QPainter *painter;
    drawSettingAboutTablet *drawsettingabouttablet;
    SysSettings *mysyssetting;
    QRect rect;


signals:
    void showPullDownSignal();
    void backToHomePageSignal();



public slots:
    void backToHomePageSlot();
     void updateTimeAndBatteryValue(QString time,int battery);

};

#endif // SETTINGABOUTTABLET_H
