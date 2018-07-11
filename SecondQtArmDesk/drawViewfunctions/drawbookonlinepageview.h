#ifndef DRAWBOOKONLINEPAGEVIEW_H
#define DRAWBOOKONLINEPAGEVIEW_H
#include<QPainter>
#include<QLineF>
#include<QRect>
#include"applications.h"

class drawBookOnlinePageView
{
public:
    drawBookOnlinePageView();

     void drawHomeButton(QPainter *painter, bool flag);
     void drawBookOnline(QPainter *painter);



private :
     QLineF line;
     QRect rect;

};

#endif // DRAWBOOKONLINEPAGEVIEW_H
