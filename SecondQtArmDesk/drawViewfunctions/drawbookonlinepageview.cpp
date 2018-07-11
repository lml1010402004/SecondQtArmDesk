#include "drawbookonlinepageview.h"

extern QString homeiconpath;

int line_position[8] = {0,96,600,96,500,50,30,29};

QString book_online = ":/mypic/pics/book_online.png";

drawBookOnlinePageView::drawBookOnlinePageView()
{

}

/**
 * @brief drawBookOnlinePageView::drawHomeButton
 * @param painter
 * @param flag
 */
void drawBookOnlinePageView::drawHomeButton(QPainter *painter, bool flag)
{

    line.setLine(line_position[0],line_position[1],line_position[2],line_position[3]);
    painter->drawLine(line);
    rect.setX(line_position[4]);
    rect.setY(line_position[5]);
    rect.setWidth(line_position[6]);
    rect.setHeight(line_position[7]);
    painter->drawPixmap(rect,homeiconpath);
}

void drawBookOnlinePageView::drawBookOnline(QPainter *painter)
{  rect.setX(30);
    rect.setY(96);
    rect.setWidth(540);
    rect.setHeight(680);
    painter->drawPixmap(rect,book_online);

}

