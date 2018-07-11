#ifndef DRAWCONNECTWIFIDIALOG_H
#define DRAWCONNECTWIFIDIALOG_H
#include<QPainter>
#include<QRect>


class drawConnectWifiDialog
{
public:
    drawConnectWifiDialog();

    void drawRectAndName(QPainter *painter,QString wifiname);
    void drawInputPassword(QPainter *painter);

    void drawTwoButtons(QPainter *painter);

private:
    QRect rect;


};

#endif // DRAWCONNECTWIFIDIALOG_H
