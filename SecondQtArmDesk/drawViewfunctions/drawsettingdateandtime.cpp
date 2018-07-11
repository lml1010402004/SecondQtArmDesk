#include "drawsettingdateandtime.h"
extern QString homeiconpath;
extern QString BACKLASTSTEPICON;
QString switch_close = ":/mypic/pics/close.png";
QString switch_open = ":/mypic/pics/open_wifi.png";

drawSettingDateAndTime::drawSettingDateAndTime()
{
  init();
}


int draw_setting_date0[8] = {0,96,600,96,500,50,30,29};
void drawSettingDateAndTime::drawHomeIcon(QPainter *painter)
{

    line.setLine(draw_setting_date0[0],draw_setting_date0[1],draw_setting_date0[2],draw_setting_date0[3]);
    painter->drawLine(line);
    rect.setX(draw_setting_date0[4]);
    rect.setY(draw_setting_date0[5]);
    rect.setWidth(draw_setting_date0[6]);
    rect.setHeight(draw_setting_date0[7]);
    painter->drawPixmap(rect,homeiconpath);

}

int draw_setting_date1[8] = {15,50,15,28,65,45,65,85};
/**
 * @brief drawSettingDateAndTime::drawBackIcon
 * @param painter
 */
void drawSettingDateAndTime::drawBackIcon(QPainter *painter)
{
    rect.setX(draw_setting_date1[0]);
    rect.setY(draw_setting_date1[1]);
    rect.setWidth(draw_setting_date1[2]);
    rect.setHeight(draw_setting_date1[3]);
    painter->drawPixmap(rect,BACKLASTSTEPICON);
    line.setLine(draw_setting_date1[4],draw_setting_date1[5],draw_setting_date1[6],draw_setting_date1[7]);
    painter->drawLine(line);
}


int draw_seting_date2[8] = {200,130,200,60,50,195,550,195};
/**
 * @brief drawSettingDateAndTime::drawDateAndTimeTitle
 * @param painter
 */
void drawSettingDateAndTime::drawDateAndTimeTitle(QPainter *painter)
{
    rect.setX(draw_seting_date2[0]);
    rect.setY(draw_seting_date2[1]);
    rect.setWidth(draw_seting_date2[2]);
    rect.setHeight(draw_seting_date2[3]);
    painter->drawText(rect,QString("DateAndTime"));
    line.setLine(draw_seting_date2[4],draw_seting_date2[5],draw_seting_date2[6],draw_seting_date2[7]);
    painter->drawLine(line);

}


int draw_seting_date3[16] = {60,210,160,40,460,210,160,40,60,260,160,40,460,260,160,40};
int draw_seting_date4[16] = {60,310,160,40,460,310,160,40,60,360,160,40,460,360,80,35};
/**
 * @brief drawSettingDateAndTime::drawDateAndTimeItems
 * @param painter
 */
void drawSettingDateAndTime::drawDateAndTimeItems(QPainter *painter,dateModel *date)
{

   rect.setX(draw_seting_date3[0]);
   rect.setY(draw_seting_date3[1]);
   rect.setWidth(draw_seting_date3[2]);
   rect.setHeight(draw_seting_date3[3]);
   painter->drawText(rect,QString("TimeZone"));
   rect.setX(draw_seting_date3[4]);
   rect.setY(draw_seting_date3[5]);
   rect.setWidth(draw_seting_date3[6]);
   rect.setHeight(draw_seting_date3[7]);
   painter->drawText(rect,QString("China"));

   rect.setX(draw_seting_date3[8]);
   rect.setY(draw_seting_date3[9]);
   rect.setWidth(draw_seting_date3[10]);
   rect.setHeight(draw_seting_date3[11]);
   painter->drawText(rect,QString("Date"));
   rect.setX(draw_seting_date3[12]);
   rect.setY(draw_seting_date3[13]);
   rect.setWidth(draw_seting_date3[14]);
   rect.setHeight(draw_seting_date3[15]);
   painter->drawText(rect,date->getDate());

   rect.setX(draw_seting_date4[0]);
   rect.setY(draw_seting_date4[1]);
   rect.setWidth(draw_seting_date4[2]);
   rect.setHeight(draw_seting_date4[3]);
   painter->drawText(rect,QString("Time"));
   rect.setX(draw_seting_date4[4]);
   rect.setY(draw_seting_date4[5]);
   rect.setWidth(draw_seting_date4[6]);
   rect.setHeight(draw_seting_date4[7]);
   painter->drawText(rect,date->getTimehour());

   rect.setX(draw_seting_date4[8]);
   rect.setY(draw_seting_date4[9]);
   rect.setWidth(draw_seting_date4[10]);
   rect.setHeight(draw_seting_date4[11]);
   painter->drawText(rect,QString("AutoTime"));
   rect.setX(draw_seting_date4[12]);
   rect.setY(draw_seting_date4[13]);
   rect.setWidth(draw_seting_date4[14]);
   rect.setHeight(draw_seting_date4[15]);
   painter->drawPixmap(rect,switch_open);

}

void drawSettingDateAndTime::init()
{


}
