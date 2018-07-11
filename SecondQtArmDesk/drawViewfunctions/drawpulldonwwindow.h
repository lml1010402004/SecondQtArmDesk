#ifndef DRAWPULLDONWWINDOW_H
#define DRAWPULLDONWWINDOW_H
#include<QPainter>
#include<QRect>
#include<QPixmap>
#include<QLineF>
#include<QBrush>
#include<QList>
#include"applications.h"



class drawpulldonwwindow
{
public:
    drawpulldonwwindow();

    void drawSettingShoutcutItem(QPainter *painter);
    void drawCloseIcon(QPainter *painter);

    void drawShutcutArea(QPainter *painter);
    void drawgrayArea(QPainter *painter,int al);

    void drawShortcutIcons(QPainter *painter,QList<QString> pathlist);
    void drawLightShoutcutAndProgressBar(QPainter *painter,QString path,int light_volume);



private:
    QRect rect;
    QPixmap pixmap;
    QLineF line;


};

#endif // DRAWPULLDONWWINDOW_H
