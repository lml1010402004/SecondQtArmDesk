#include "drawdateandhour.h"

int draw_con_wifi22[8] = {40,210,120,40,240,210,120,40};
drawDateAndHour::drawDateAndHour()
{

}

void drawDateAndHour::drawConfirmAndCancleButton(QPainter *painter)
{
    rect.setX(draw_con_wifi22[0]);
    rect.setY(draw_con_wifi22[1]);
    rect.setWidth(draw_con_wifi22[2]);
    rect.setHeight(draw_con_wifi22[3]);
    painter->drawText(rect,QString("    Set"));
    painter->drawRect(rect);

    rect.setX(draw_con_wifi22[4]);
    rect.setY(draw_con_wifi22[5]);
    rect.setWidth(draw_con_wifi22[6]);
    rect.setHeight(draw_con_wifi22[7]);
    painter->drawText(rect,QString("  Cancle"));
    painter->drawRect(rect);


}

void drawDateAndHour::drawLeftInputArea(QPainter *painter)
{
    rect.setX(45);
    rect.setY(116);
    rect.setWidth(120);
    rect.setHeight(40);
    painter->drawRect(rect);

}

void drawDateAndHour::drawRightInputArea(QPainter *painter)
{
    rect.setX(245);
    rect.setY(116);
    rect.setWidth(120);
    rect.setHeight(40);
    painter->drawRect(rect);

}
