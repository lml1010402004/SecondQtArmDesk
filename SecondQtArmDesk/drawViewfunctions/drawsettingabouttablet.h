#ifndef DRAWSETTINGABOUTTABLET_H
#define DRAWSETTINGABOUTTABLET_H

#include<QRect>
#include<QLineF>
#include<QPainter>
#include"drawViewfunctions/drawsettingabouttablet.h"


class drawSettingAboutTablet
{
public:
    drawSettingAboutTablet();
    ~drawSettingAboutTablet();

    void drawHomeIcon(QPainter *painter);
    void drawBackIcon(QPainter *painter);

    void drawAboutTableTitle(QPainter *painter);
    void drawInfoAboutTablet(QPainter *painter,QString SN,QString MAC,QString storage,QString VersionInfo);

    void init();

private:
    QRect rect;
    QLineF line;


};

#endif // DRAWSETTINGABOUTTABLET_H
