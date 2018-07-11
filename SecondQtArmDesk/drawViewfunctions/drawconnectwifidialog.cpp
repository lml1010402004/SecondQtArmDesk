#include "drawconnectwifidialog.h"


int draw_con_wifi[8] = {0,0,400,300,150,10,100,40};
int draw_con_wifi1[4] = {20,70,200,40};
int draw_con_wifi2[8] = {40,210,120,40,240,210,120,40};

drawConnectWifiDialog::drawConnectWifiDialog()
{

}

void drawConnectWifiDialog::drawRectAndName(QPainter *painter,QString wifiName)
{
//     this->setGeometry(QRect(100,150,400,300));

   rect.setX(draw_con_wifi[0]);
   rect.setY(draw_con_wifi[1]);
   rect.setWidth(draw_con_wifi[2]);
   rect.setHeight(draw_con_wifi[3]);
   painter->fillRect(rect,Qt::white);
   painter->drawRect(rect);

   rect.setX(draw_con_wifi[4]);
   rect.setY(draw_con_wifi[5]);
   rect.setWidth(draw_con_wifi[6]);
   rect.setHeight(draw_con_wifi[7]);
   painter->drawText(rect,wifiName);

}


void drawConnectWifiDialog::drawInputPassword(QPainter *painter)
{
//     this->setGeometry(QRect(100,150,400,300));
   rect.setX(draw_con_wifi1[0]);
   rect.setY(draw_con_wifi1[1]);
   rect.setWidth(draw_con_wifi1[2]);
   rect.setHeight(draw_con_wifi1[3]);
   painter->drawText(rect,QString("InputPassword"));

//   rect.setX(20);
//   rect.setY(70);
//   rect.setWidth(290);
//   rect.setHeight(40);
//   painter->drawRect(rect);

}



void drawConnectWifiDialog::drawTwoButtons(QPainter *painter)
{

    // this->setGeometry(QRect(100,150,400,300));
    rect.setX(draw_con_wifi2[0]);
    rect.setY(draw_con_wifi2[1]);
    rect.setWidth(draw_con_wifi2[2]);
    rect.setHeight(draw_con_wifi2[3]);
    painter->drawText(rect,QString("Connect"));
    painter->drawRect(rect);

    rect.setX(draw_con_wifi2[4]);
    rect.setY(draw_con_wifi2[5]);
    rect.setWidth(draw_con_wifi2[6]);
    rect.setHeight(draw_con_wifi2[7]);
    painter->drawText(rect,QString("Cancle"));
    painter->drawRect(rect);

}
