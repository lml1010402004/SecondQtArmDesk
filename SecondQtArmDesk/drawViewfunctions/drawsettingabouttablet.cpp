#include "drawsettingabouttablet.h"

extern QString homeiconpath;
extern QString BACKLASTSTEPICON;

int draw_setting_tab1[8] = {0,96,600,96,500,50,30,29};

int draw_settting_tab2[8] = {15,50,15,28,65,45,65,85};
int draw_setting_tab3[4] = {200,130,200,60};
int draw_setting_tab4[16] = {40,210,60,40,400,210,120,40,40,300,60,40,400,300,160,40};
int draw_setting_tab5[16] = {40,390,200,40,400,390,120,40,40,480,200,40,400,480,120,40};


drawSettingAboutTablet::drawSettingAboutTablet()
{
   init();
}

drawSettingAboutTablet::~drawSettingAboutTablet()
{

}


void drawSettingAboutTablet::drawHomeIcon(QPainter *painter)
{
    line.setLine(draw_setting_tab1[0],draw_setting_tab1[1],draw_setting_tab1[2],draw_setting_tab1[3]);
    painter->drawLine(line);
    rect.setX(draw_setting_tab1[4]);
    rect.setY(draw_setting_tab1[5]);
    rect.setWidth(draw_setting_tab1[6]);
    rect.setHeight(draw_setting_tab1[7]);
    painter->drawPixmap(rect,homeiconpath);

}

void drawSettingAboutTablet::drawBackIcon(QPainter *painter)
{
    rect.setX(draw_settting_tab2[0]);
    rect.setY(draw_settting_tab2[1]);
    rect.setWidth(draw_settting_tab2[2]);
    rect.setHeight(draw_settting_tab2[3]);
    painter->drawPixmap(rect,BACKLASTSTEPICON);
    line.setLine(draw_settting_tab2[4],draw_settting_tab2[5],draw_settting_tab2[6],draw_settting_tab2[7]);
    painter->drawLine(line);

}



void drawSettingAboutTablet::drawAboutTableTitle(QPainter *painter)
{
    rect.setX(draw_setting_tab3[0]);
    rect.setY(draw_setting_tab3[1]);
    rect.setWidth(draw_setting_tab3[2]);
    rect.setHeight(draw_setting_tab3[3]);
    painter->drawText(rect,QString("About_Tablet"));
}



void drawSettingAboutTablet::drawInfoAboutTablet(QPainter *painter,QString SN,QString MAC,QString storage,QString VersionInfo)
{
   rect.setX(draw_setting_tab4[0]);
   rect.setY(draw_setting_tab4[1]);
   rect.setWidth(draw_setting_tab4[2]);
   rect.setHeight(draw_setting_tab4[3]);
   painter->drawText(rect,QString("SN"));
   rect.setX(draw_setting_tab4[4]);
   rect.setY(draw_setting_tab4[5]);
   rect.setWidth(draw_setting_tab4[6]);
   rect.setHeight(draw_setting_tab4[7]);
   painter->drawText(rect,SN);

   rect.setX(draw_setting_tab4[8]);
   rect.setY(draw_setting_tab4[9]);
   rect.setWidth(draw_setting_tab4[10]);
   rect.setHeight(draw_setting_tab4[11]);
   painter->drawText(rect,QString("MAC"));
   rect.setX(draw_setting_tab4[12]);
   rect.setY(draw_setting_tab4[13]);
   rect.setWidth(draw_setting_tab4[14]);
   rect.setHeight(draw_setting_tab4[15]);
   painter->drawText(rect,MAC);

   rect.setX(draw_setting_tab5[0]);
   rect.setY(draw_setting_tab5[1]);
   rect.setWidth(draw_setting_tab5[2]);
   rect.setHeight(draw_setting_tab5[3]);
   painter->drawText(rect,QString("STORAGE"));
   rect.setX(draw_setting_tab5[4]);
   rect.setY(draw_setting_tab5[5]);
   rect.setWidth(draw_setting_tab5[6]);
   rect.setHeight(draw_setting_tab5[7]);
   painter->drawText(rect,storage);

   rect.setX(draw_setting_tab5[8]);
   rect.setY(draw_setting_tab5[9]);
   rect.setWidth(draw_setting_tab5[10]);
   rect.setHeight(draw_setting_tab5[11]);
   painter->drawText(rect,QString("VersionInfo"));
   rect.setX(draw_setting_tab5[12]);
   rect.setY(draw_setting_tab5[13]);
   rect.setWidth(draw_setting_tab5[14]);
   rect.setHeight(draw_setting_tab5[15]);
   painter->drawText(rect,VersionInfo);


}

void drawSettingAboutTablet::init()
{


}
