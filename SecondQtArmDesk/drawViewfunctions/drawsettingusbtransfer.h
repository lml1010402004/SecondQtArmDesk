#ifndef DRAWSETTINGUSBTRANSFER_H
#define DRAWSETTINGUSBTRANSFER_H

#include<QRect>
#include<QLineF>
#include<QPainter>
#include"drawViewfunctions/drawsettingusbtransfer.h"
#include<QFont>
#include<QObject>

class drawSettingUsbTransfer
{
public:
    drawSettingUsbTransfer();

    void drawHomeIcon(QPainter *painter);
   void drawBackIcon(QPainter *painter);

   void drawUSBTransferButton(QPainter *painter);

   void drawUSBTransferTitle(QPainter *painter);

   void drawStateofUSBConnectedPc(QPainter *painter);
   void drawButtonsOfUSBConnected(QPainter *painetr);

    void init();

private:
    QLineF line;
    QRect rect;
    QFont font;

};

#endif // DRAWSETTINGUSBTRANSFER_H
