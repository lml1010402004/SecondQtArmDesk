#include "drawgamepageview.h"

QString four_game = ":/mypic/pics/four_games.png";
QString one_game = ":/mypic/pics/one_game.png";

extern QString homeiconpath;
drawGamePageView::drawGamePageView()
{

}


int draw_game[8] = {0,96,600,96,500,50,30,29};
/**
 * @brief drawGamePageView::drawHomeButton
 * @param painter
 */
void drawGamePageView::drawHomeButton(QPainter *painter)
{

    line.setLine(draw_game[0],draw_game[1],draw_game[2],draw_game[3]);
    painter->drawLine(line);
    rect.setX(draw_game[4]);
    rect.setY(draw_game[5]);
    rect.setWidth(draw_game[6]);
    rect.setHeight(draw_game[7]);
    painter->drawPixmap(rect,homeiconpath);

}

void drawGamePageView::drawGames(QPainter *painter)
{
    rect.setX(20);
    rect.setY(105);
    rect.setWidth(560);
    rect.setHeight(150);
    painter->drawPixmap(rect,four_game);

    rect.setX(20);
    rect.setY(275);
    rect.setWidth(140);
    rect.setHeight(150);
    painter->drawPixmap(rect,one_game);



}

