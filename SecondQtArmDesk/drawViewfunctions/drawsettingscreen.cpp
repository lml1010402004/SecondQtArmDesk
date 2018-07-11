#include "drawsettingscreen.h"
#include<QString>

extern QString homeiconpath;

extern QString BACKLASTSTEPICON;

QString pathgroup[3] = {":/mypic/pics/sleep_bg2.png",":/mypic/pics/sleep_bg3.png",":/mypic/pics/sleep_bg4.png"};
QString checkbox_true=":/mypic/pics/checkbox_true.png";
QString checkbox_false =":/mypic/pics/checkbox_false.png";


int draw_set_scr[8] = {0,96,600,96,500,50,30,29};

int draw_set_src1[8] = {15,50,15,28,65,45,65,85};
int draw_set_src2[10] = {45,170,120,140,200,45,170,340,20,20};

drawSettingScreen::drawSettingScreen()
{

}


void drawSettingScreen::drawHomeIcon(QPainter *paitner)
{
    line.setLine(draw_set_scr[0],draw_set_scr[1],draw_set_scr[2],draw_set_scr[3]);
    paitner->drawLine(line);
    rect.setX(draw_set_scr[4]);
    rect.setY(draw_set_scr[5]);
    rect.setWidth(draw_set_scr[6]);
    rect.setHeight(draw_set_scr[7]);
    paitner->drawPixmap(rect,homeiconpath);

}


void drawSettingScreen::drawBackIcon(QPainter *painter)
{
    rect.setX(draw_set_src1[0]);
    rect.setY(draw_set_src1[1]);
    rect.setWidth(draw_set_src1[2]);
    rect.setHeight(draw_set_src1[3]);
    line.setLine(draw_set_src1[4],draw_set_src1[5],draw_set_src1[6],draw_set_src1[7]);
    painter->drawLine(line);
    painter->drawPixmap(rect,BACKLASTSTEPICON);


}



void drawSettingScreen::drawWallPapaerItem(QPainter *painter,int index)
{

     for(int i=0;i<3;i++){
      rect.setX(draw_set_src2[0]+draw_set_src2[1]*i);
      rect.setY(draw_set_src2[2]);
      rect.setWidth(draw_set_src2[3]);
      rect.setHeight(draw_set_src2[4]);
      painter->drawPixmap(rect,pathgroup[i]);
      rect.setX(draw_set_src2[5]+draw_set_src2[6]*i);
      rect.setY(draw_set_src2[7]);
      rect.setHeight(draw_set_src2[8]);
      rect.setWidth(draw_set_src2[9]);
      if(index==i){
           painter->drawPixmap(rect,checkbox_true);
      }else{
           painter->drawPixmap(rect,checkbox_false);
      }

    }
}
