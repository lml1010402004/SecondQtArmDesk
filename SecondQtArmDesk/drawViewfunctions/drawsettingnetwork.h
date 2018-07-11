#ifndef DRAWSETTINGNETWORK_H
#define DRAWSETTINGNETWORK_H

#include<QRect>
#include<QLineF>
#include<QPaintEvent>
#include<QPainter>
#include"drawViewfunctions/drawsettingnetwork.h"
#include<QFont>
#include<dataItem/wifiitem.h>
#include<QList>
#include"syssettings.h"

class drawSettingNetwork
{
public:
    drawSettingNetwork();
    ~drawSettingNetwork();

    void drawHomeIcon(QPainter *painter);
    void drawBackIcon(QPainter *painter);
    void drawWifiTitle(QPainter *painter);

    void drawWifiSwitch(QPainter *painter,bool flag);
    void drawWifiSerachText(QPainter *painter);

    void drawCurrentWifiItems(QPainter *painter,QList<wifiItem*> *wifilistitem,int currentPage,int totalPages);

    void drawLastAndNextPage(QPainter *painter,int currentPage,int totalPages);

    void init();

    QList<wifiItem*> getCurrentPageWifiList(QList<wifiItem*> *list,int currentPage,int totalPages);

private:
    QLineF line;
    QRect rect;
    QFont font;
    SysSettings *mysyssetting;



};

#endif // DRAWSETTINGNETWORK_H
