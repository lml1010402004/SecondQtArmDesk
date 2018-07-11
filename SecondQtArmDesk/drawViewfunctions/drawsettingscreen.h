#ifndef DRAWSETTINGSCREEN_H
#define DRAWSETTINGSCREEN_H
#include<QPaintEvent>
#include<QPainter>
#include<QLineF>
#include<QRect>
#include"dataItem/wallpaperitem.h"


class drawSettingScreen
{
public:
    drawSettingScreen();
    ~drawSettingScreen();

    void drawHomeIcon(QPainter *paitner);
     void drawBackIcon(QPainter *painter);
     void drawWallPapaerItem(QPainter *painter,int index);



private:
    QLineF line;
    QRect rect;



};

#endif // DRAWSETTINGSCREEN_H
