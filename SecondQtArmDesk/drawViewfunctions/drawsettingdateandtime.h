#ifndef DRAWSETTINGDATEANDTIME_H
#define DRAWSETTINGDATEANDTIME_H


#include<QRect>
#include<QLineF>
#include<QPainter>
#include"drawViewfunctions/drawsettingdateandtime.h"
#include"dataItem/datemodel.h"


class drawSettingDateAndTime
{
public:
    drawSettingDateAndTime();
    ~drawSettingDateAndTime();

    void drawHomeIcon(QPainter *painter);
    void drawBackIcon(QPainter *painter);
    void drawDateAndTimeTitle(QPainter *painter);
    void drawDateAndTimeItems(QPainter *painter,dateModel *date);

    void init();

private :
    QLineF line;
    QRect rect;

};

#endif // DRAWSETTINGDATEANDTIME_H
