#include "drawsettinglight.h"

extern QString homeiconpath;

extern QString ellipsepath;

QString light_icon = ":/mypic/pics/light_icon.png";
QString BACKLASTSTEPICON =":/mypic/pics/return_icon.png";


int draw_set_lig[8] = {0,96,600,96,500,50,30,29};
int draw_set_lig1[12] = {50,230,50,50,130,250,530,250,130,240,20,20};
int draw_set_lig2[4] = {200,130,200,60};
int draw_set_lig3[8] = {15,50,15,28,65,45,65,85};

drawSettingLight::drawSettingLight()
{

}



/**
 * @brief drawSettingLight::drawHomeButton
 * @param painter
 */
void drawSettingLight::drawHomeButton(QPainter *painter)
{

    line.setLine(draw_set_lig[0],draw_set_lig[1],draw_set_lig[2],draw_set_lig[3]);
    painter->drawLine(line);
    rect.setX(draw_set_lig[4]);
    rect.setY(draw_set_lig[5]);
    rect.setWidth(draw_set_lig[6]);
    rect.setHeight(draw_set_lig[7]);
    painter->drawPixmap(rect,homeiconpath);

}



/**
 * @brief drawSettingLight::drawProgressBar
 * @param paitner
 * @param value
 * according the inputed value to draw the UI.
 */
void drawSettingLight::drawProgressBar(QPainter *paitner, int value)
{

  rect.setX(draw_set_lig1[0]);
  rect.setY(draw_set_lig1[1]);
  rect.setWidth(draw_set_lig1[2]);
  rect.setHeight(draw_set_lig1[3]);
  paitner->drawPixmap(rect,light_icon);

  line.setLine(draw_set_lig1[4],draw_set_lig1[5],draw_set_lig1[6],draw_set_lig1[7]);
  paitner->drawLine(line);

  int x = draw_set_lig1[8]+value*4;
  rect.setX(x+20);
  rect.setY(draw_set_lig1[9]);
  rect.setWidth(draw_set_lig1[10]);
  rect.setHeight(draw_set_lig1[11]);
  paitner->drawPixmap(rect,ellipsepath);

}


void drawSettingLight::drawLightTitle(QPainter *painter)
{
    rect.setX(draw_set_lig2[0]);
    rect.setY(draw_set_lig2[1]);
    rect.setWidth(draw_set_lig2[2]);
    rect.setHeight(draw_set_lig2[3]);
    painter->drawText(rect,QString("light_title"));

}



/**
 * @brief drawSettingLight::drawBackIcon
 * @param painter
 */
void drawSettingLight::drawBackIcon(QPainter *painter)
{
    rect.setX(draw_set_lig3[0]);
    rect.setY(draw_set_lig3[1]);
    rect.setWidth(draw_set_lig3[2]);
    rect.setHeight(draw_set_lig3[3]);
    painter->drawPixmap(rect,BACKLASTSTEPICON);
    line.setLine(draw_set_lig3[4],draw_set_lig3[5],draw_set_lig3[6],draw_set_lig3[7]);
    painter->drawLine(line);


}
