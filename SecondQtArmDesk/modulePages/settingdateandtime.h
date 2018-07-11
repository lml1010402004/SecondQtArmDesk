#ifndef SETTINGDATEANDTIME_H
#define SETTINGDATEANDTIME_H

#include <QMainWindow>
#include<QPaintEvent>
#include<QMouseEvent>
#include<QPainter>
#include"drawViewfunctions/drawsettingdateandtime.h"
#include"statusbar.h"
#include"statusbar_global.h"
#include"dataItem/datemodel.h"
#include"syssettings.h"
#include<QRect>
#include<modulePages/setdateandhour.h>


class settingDateAndTime : public QMainWindow
{
    Q_OBJECT
public:
    explicit settingDateAndTime(QWidget *parent = 0);
    ~settingDateAndTime();
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);

    void init();

private:

    StatusBar *statusbar;
    drawSettingDateAndTime *drawsettingdateandtime;
    QPainter *painter;
    dateModel *mydatemodel;
    SysSettings *mysyssetting;
    QRect rect;
    setDateAndHour *setdateandhour;


signals:
    void showPullDownSignal();
    void backToHomePageSignal();
    void udpateTimeSignal();




public slots:
    void backToHomePageSlot();
     void updateTimeAndBatteryValue(QString time,int battery);
     void updateTimeRightNow();


};

#endif // SETTINGDATEANDTIME_H
