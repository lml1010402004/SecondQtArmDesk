#ifndef SETTINGNETWORK_H
#define SETTINGNETWORK_H
#include<QMainWindow>
#include<QMouseEvent>
#include<QPaintEvent>
#include<QPainter>
#include"drawViewfunctions/drawsettingnetwork.h"
#include"statusbar.h"
#include"statusbar_global.h"
#include"dataItem/wifiitem.h"
#include<QList>
#include"utils/wifiservice.h"
#include<QString>
#include"modulePages/connectwifidialog.h"
#include"syssettings.h"
#include<QRect>

class settingNetWork : public QMainWindow
{
    Q_OBJECT
public:
    explicit settingNetWork(QWidget *parent = 0);
    ~settingNetWork();
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);

    void init();


private:



    drawSettingNetwork *drawsettingnetwork;
    StatusBar *statusbar;
    QPainter *painter;
    QList<wifiItem*> *wifilist;
    wifiItem* wifiitem;
    bool wifi_state;
    WifiService *mywifiservice;

    int wifiCurrentPage;
    int wifiTotalPages;
    connectWifiDialog *connectwifidialog;
    QString targetWifiMac;

    int indexForPosition;

    QRect rect;




signals:
    void showPullDownSignal();
     void backToHomePageSignal();

public slots:
       void backToHomePageSlot();

       void wifi_StatusChanged(QString wifistatus);
       void wifi_RefreshDone(QList<TWifi> wifi_Lists);
       void connectWifiSlot(QString password);
          void updateTimeAndBatteryValue(QString time,int battery);

};

#endif // SETTINGNETWORK_H
