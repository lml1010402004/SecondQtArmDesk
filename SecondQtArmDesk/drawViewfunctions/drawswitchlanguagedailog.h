#ifndef DRAWSWITCHLANGUAGEDAILOG_H
#define DRAWSWITCHLANGUAGEDAILOG_H
#include<QPainter>
#include<QRect>
#include<QList>
#include<QString>



class drawSwitchLanguageDailog
{
public:
    drawSwitchLanguageDailog();

    void drawLanguageContent(QPainter *painter,QList<QString> *list);

    void drawRect(QPainter *painter);

private:
    QRect rect;


};

#endif // DRAWSWITCHLANGUAGEDAILOG_H
