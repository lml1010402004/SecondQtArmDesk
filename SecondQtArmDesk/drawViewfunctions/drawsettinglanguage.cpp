#include "drawsettinglanguage.h"

extern QString homeiconpath;

extern  QString BACKLASTSTEPICON;


int draw_seting_lan[8] = {0,96,600,96,500,50,30,29};

int draw_seting_lan1[8] = {15,50,15,28,65,45,65,85};
int draw_seting_lan2[4] = {200,130,200,60};
int draw_seting_lan3[12] = {30,210,540,60,40,220,120,60,450,220,120,60};
int draw_seting_lan4[12] = {30,280,540,60,40,290,120,60,450,290,120,60};


drawSettingLanguage::drawSettingLanguage()
{
   init();
}

drawSettingLanguage::~drawSettingLanguage()
{

}


void drawSettingLanguage::drawHomeIcon(QPainter *painter)
{
    line.setLine(draw_seting_lan[0],draw_seting_lan[1],draw_seting_lan[2],draw_seting_lan[3]);
    painter->drawLine(line);
    rect.setX(draw_seting_lan[4]);
    rect.setY(draw_seting_lan[5]);
    rect.setWidth(draw_seting_lan[6]);
    rect.setHeight(draw_seting_lan[7]);
    painter->drawPixmap(rect,homeiconpath);




}


/**
 * @brief drawSettingLanguage::drawBackIcon
 * @param painter
 */
void drawSettingLanguage::drawBackIcon(QPainter *painter)
{
    rect.setX(draw_seting_lan1[0]);
    rect.setY(draw_seting_lan1[1]);
    rect.setWidth(draw_seting_lan1[2]);
    rect.setHeight(draw_seting_lan1[3]);
    painter->drawPixmap(rect,BACKLASTSTEPICON);
    line.setLine(draw_seting_lan1[4],draw_seting_lan1[5],draw_seting_lan1[6],draw_seting_lan1[7]);
    painter->drawLine(line);

}




void drawSettingLanguage::drawLanguageTitle(QPainter *painter)
{
    rect.setX(draw_seting_lan2[0]);
    rect.setY(draw_seting_lan2[1]);
    rect.setWidth(draw_seting_lan2[2]);
    rect.setHeight(draw_seting_lan2[3]);
    painter->drawText(rect,QString("Languagekeyboard"));

}



void drawSettingLanguage::drawLanguageItem(QPainter *painter)
{
    rect.setX(draw_seting_lan3[0]);
    rect.setY(draw_seting_lan3[1]);
    rect.setWidth(draw_seting_lan3[2]);
    rect.setHeight(draw_seting_lan3[3]);
    painter->drawRect(rect);
    rect.setX(draw_seting_lan3[4]);
    rect.setY(draw_seting_lan3[5]);
    rect.setWidth(draw_seting_lan3[6]);
    rect.setHeight(draw_seting_lan3[7]);
    painter->drawText(rect,QString("Language"));

    rect.setX(draw_seting_lan3[8]);
    rect.setY(draw_seting_lan3[9]);
    rect.setWidth(draw_seting_lan3[10]);
    rect.setHeight(draw_seting_lan3[11]);
    painter->drawText(rect,QString("English"));

}



void drawSettingLanguage::drawKeyBoardItem(QPainter *painter)
{
    rect.setX(draw_seting_lan4[0]);
    rect.setY(draw_seting_lan4[1]);
    rect.setWidth(draw_seting_lan4[2]);
    rect.setHeight(draw_seting_lan4[3]);
    painter->drawRect(rect);
    rect.setX(draw_seting_lan4[4]);
    rect.setY(draw_seting_lan4[5]);
    rect.setWidth(draw_seting_lan4[6]);
    rect.setHeight(draw_seting_lan4[7]);
    painter->drawText(rect,QString("KeyBoard"));

    rect.setX(draw_seting_lan4[8]);
    rect.setY(draw_seting_lan4[9]);
    rect.setWidth(draw_seting_lan4[10]);
    rect.setHeight(draw_seting_lan4[11]);
    painter->drawText(rect,QString("English"));


}

void drawSettingLanguage::init()
{

}
