#ifndef DRAWSETTINGLANGUAGE_H
#define DRAWSETTINGLANGUAGE_H
#include<QPainter>
#include<QRect>
#include<QLineF>
#include"drawViewfunctions/drawsettinglanguage.h"

class drawSettingLanguage
{
public:
    drawSettingLanguage();
    ~drawSettingLanguage();

    void drawHomeIcon(QPainter *painter);
    void drawBackIcon(QPainter *painter);

    void drawLanguageTitle(QPainter *painter);
    void drawLanguageItem(QPainter *painter);
    void drawKeyBoardItem(QPainter *painter);


    void init();

private :
    QLineF line;
    QRect rect;


};

#endif // DRAWSETTINGLANGUAGE_H
