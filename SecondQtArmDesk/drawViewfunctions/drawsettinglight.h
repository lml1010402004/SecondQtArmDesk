#ifndef DRAWSETTINGLIGHT_H
#define DRAWSETTINGLIGHT_H

#include <QMainWindow>
#include<QPainter>
#include<QRect>
#include<QLineF>
#include<QFont>

class drawSettingLight
{

public:
    explicit drawSettingLight();
    void drawHomeButton(QPainter *painter);

    void drawProgressBar(QPainter *paitner,int value);
    void drawLightTitle(QPainter *painter);
    void drawBackIcon(QPainter *painter);

private:
    QLineF line;
    QRect rect;
    QFont font;

};

#endif // DRAWSETTINGLIGHT_H
