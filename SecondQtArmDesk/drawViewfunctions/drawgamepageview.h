#ifndef DRAWGAMEPAGEVIEW_H
#define DRAWGAMEPAGEVIEW_H
#include<QPainter>
#include<QLineF>
#include<QRect>

class drawGamePageView
{
public:
    drawGamePageView();
    void drawHomeButton(QPainter *painter);

    void drawGames(QPainter *painter);




private:
    QRect rect;
    QLineF line;
};

#endif // DRAWGAMEPAGEVIEW_H
