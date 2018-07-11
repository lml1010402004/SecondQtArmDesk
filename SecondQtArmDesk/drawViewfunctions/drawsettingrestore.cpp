#include "drawsettingrestore.h"

extern QString homeiconpath;
extern QString BACKLASTSTEPICON;



int draw_set_res[8] = {0,96,600,96,500,50,30,29};

int draw_set_res1[8] = {15,50,15,28,65,45,65,85};

int draw_set_res2[5]= {220,130,200,60,20};
int draw_set_res3[8] = {200,300,200,60,250,320,120,40};


drawSettingRestore::drawSettingRestore()
{
 init();
}

drawSettingRestore::~drawSettingRestore()
{

}


/**
 * @brief drawSettingRestore::drawHomeIcon
 * @param painter
 */
void drawSettingRestore::drawHomeIcon(QPainter *painter)
{

    line.setLine(draw_set_res[0],draw_set_res[1],draw_set_res[2],draw_set_res[3]);
    painter->drawLine(line);
    rect.setX(draw_set_res[4]);
    rect.setY(draw_set_res[5]);
    rect.setWidth(draw_set_res[6]);
    rect.setHeight(draw_set_res[7]);
    painter->drawPixmap(rect,homeiconpath);


}


/**
 * @brief drawSettingRestore::drawBackIcon
 * @param painter
 */
void drawSettingRestore::drawBackIcon(QPainter *painter)
{
    rect.setX(draw_set_res1[0]);
    rect.setY(draw_set_res1[1]);
    rect.setWidth(draw_set_res1[2]);
    rect.setHeight(draw_set_res1[3]);
    painter->drawPixmap(rect,BACKLASTSTEPICON);
    line.setLine(draw_set_res1[4],draw_set_res1[5],draw_set_res1[6],draw_set_res1[7]);
    painter->drawLine(line);
}


void drawSettingRestore::drawRestoreTitle(QPainter *painter)
{
    rect.setX(draw_set_res2[0]);
    rect.setY(draw_set_res2[1]);
    rect.setWidth(draw_set_res2[2]);
    rect.setHeight(draw_set_res2[3]);
    font.setPixelSize(draw_set_res2[4]);
    painter->setFont(font);
    painter->drawText(rect,QObject::tr("Restore_Title"));

}



void drawSettingRestore::drawRestoreButton(QPainter *painter)
{
   rect.setX(draw_set_res3[0]);
   rect.setY(draw_set_res3[1]);
   rect.setWidth(draw_set_res3[2]);
   rect.setHeight(draw_set_res3[3]);
   painter->drawRect(rect);
   rect.setX(draw_set_res3[4]);
   rect.setY(draw_set_res3[5]);
   rect.setWidth(draw_set_res3[6]);
   rect.setHeight(draw_set_res3[7]);
   painter->drawText(rect,QObject::tr("restore"));

}

void drawSettingRestore::init()
{

}
