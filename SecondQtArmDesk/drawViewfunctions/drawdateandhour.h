#ifndef DRAWDATEANDHOUR_H
#define DRAWDATEANDHOUR_H
#include<QRect>
#include<QPainter>

class drawDateAndHour
{
public:
    drawDateAndHour();

    void drawConfirmAndCancleButton(QPainter *painter);

    void drawLeftInputArea(QPainter *painter);
    void drawRightInputArea(QPainter *painter);

private:
    QRect rect;

};

#endif // DRAWDATEANDHOUR_H
