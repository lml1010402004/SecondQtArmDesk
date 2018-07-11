#ifndef SETTINGUSBTRANSFER_H
#define SETTINGUSBTRANSFER_H

#include <QMainWindow>
#include<QMouseEvent>
#include<QPaintEvent>
#include<QPaintEvent>
#include"drawViewfunctions/drawsettingusbtransfer.h"
#include"statusbar.h"
#include"statusbar_global.h"
#include<QPainter>
#include"usbservice.h"
#include"database/database.h"
#include"syssettings.h"
#include<QRect>


class settingUSBTransfer : public QMainWindow
{
    Q_OBJECT
public:
    explicit settingUSBTransfer(QWidget *parent = 0);
    ~settingUSBTransfer();
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);

    void init();

private:
    drawSettingUsbTransfer *drawsettingusbtransfer;
    StatusBar *statubar;
    QPainter *painter;
    UsbService *usbservice;
     SysSettings *mysyssetting;
     QRect rect;




signals:
    void showPullDownSignal();
    void backToHomePageSignal();
    void updateTheBookDataSignal();

public slots:
    void backToHomePageSlot();
      void updateTimeAndBatteryValue(QString time,int battery);

};

#endif // SETTINGUSBTRANSFER_H
