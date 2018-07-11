#include "drawsettingusbtransfer.h"

extern QString homeiconpath;
extern QString BACKLASTSTEPICON;
QString usb_transfer_path = ":/mypic/pics/usb_transfer.png";


int draw_set_trans[8]={0,96,600,96,500,50,30,29};
int draw_set_trans1[8] = {15,50,15,28,65,45,65,85};

int draw_set_trans2[5] ={200,250,200,20,60};
int draw_set_trans3[5] = {175,120,250,40,15};
int draw_set_trans4[5] = {225,350,200,40,15};
int draw_set_trans5[8] = {50,420,200,40,350,420,200,40};
drawSettingUsbTransfer::drawSettingUsbTransfer()
{
    init();

}


void drawSettingUsbTransfer::drawHomeIcon(QPainter *painter)
{
    line.setLine(draw_set_trans[0],draw_set_trans[1],draw_set_trans[2],draw_set_trans[3]);
    painter->drawLine(line);
    rect.setX(draw_set_trans[4]);

    rect.setY(draw_set_trans[5]);
    rect.setWidth(draw_set_trans[6]);
    rect.setHeight(draw_set_trans[7]);
    painter->drawPixmap(rect,homeiconpath);

}




/**
 * @brief drawSettingUsbTransfer::drawBackIcon
 * @param painter
 */
void drawSettingUsbTransfer::drawBackIcon(QPainter *painter)
{
    rect.setX(draw_set_trans1[0]);
    rect.setY(draw_set_trans1[1]);
    rect.setWidth(draw_set_trans1[2]);
    rect.setHeight(draw_set_trans1[3]);
    painter->drawPixmap(rect,BACKLASTSTEPICON);
    line.setLine(draw_set_trans1[4],draw_set_trans1[5],draw_set_trans1[6],draw_set_trans1[7]);
    painter->drawLine(line);

}


/**
 * @brief drawSettingUsbTransfer::drawUSBTransferButton
 * @param painter
 */
void drawSettingUsbTransfer::drawUSBTransferButton(QPainter *painter)
{
     rect.setX(draw_set_trans2[0]);
     rect.setY(draw_set_trans2[1]);
     rect.setWidth(draw_set_trans2[2]);
     font.setPointSize(draw_set_trans2[3]);
     painter->setFont(font);
     rect.setHeight(draw_set_trans2[4]);
     painter->drawPixmap(rect,usb_transfer_path);
}




/**
 * @brief drawSettingUsbTransfer::drawUSBTransferTitle
 * @param painter
 */
void drawSettingUsbTransfer::drawUSBTransferTitle(QPainter *painter)
{
    rect.setX(draw_set_trans3[0]);
    rect.setY(draw_set_trans3[1]);
    rect.setWidth(draw_set_trans3[2]);
    rect.setHeight(draw_set_trans3[3]);
    font.setPointSize(draw_set_trans3[4]);
    painter->setFont(font);
    painter->drawText(rect,QObject::tr("USB_Transfer"));

}



void drawSettingUsbTransfer::drawStateofUSBConnectedPc(QPainter *painter)
{
   rect.setX(draw_set_trans4[0]);
   rect.setY(draw_set_trans4[1]);
   rect.setWidth(draw_set_trans4[2]);
   rect.setHeight(draw_set_trans4[3]);
   font.setPointSize(draw_set_trans4[4]);
   painter->setFont(font);
   painter->drawText(rect,QObject::tr("Connected"));

}



void drawSettingUsbTransfer::drawButtonsOfUSBConnected(QPainter *painetr)
{
  rect.setX(draw_set_trans5[0]);
  rect.setY(draw_set_trans5[1]);
  rect.setWidth(draw_set_trans5[2]);
  rect.setHeight(draw_set_trans5[3]);
  painetr->drawRect(rect);
  painetr->drawText(rect,QObject::tr("Data_Transfer"));

  rect.setX(draw_set_trans5[4]);
  rect.setY(draw_set_trans5[5]);
  rect.setWidth(draw_set_trans5[6]);
  rect.setHeight(draw_set_trans5[7]);
  painetr->drawRect(rect);
  painetr->drawText(rect,QObject::tr("Just_charge"));

}

void drawSettingUsbTransfer::init()
{

}
