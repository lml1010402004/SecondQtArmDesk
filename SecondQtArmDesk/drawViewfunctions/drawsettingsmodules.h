#ifndef DRAWSETTINGSMODULES_H
#define DRAWSETTINGSMODULES_H
#include<QPainter>
#include<QList>
#include<QLineF>
#include<QRect>
#include<QFont>
#include<QString>
#include<QObject>

class drawSettingsModules
{
public:
    drawSettingsModules();
    ~drawSettingsModules();
    void drawHomeIconOnSettingPage(QPainter *painter,QString iconpath);
    void drawSystemSettingText(QPainter *painter ,QString text);

    void drawSettingsItems(QPainter *painter);

private:
    QLineF line;
    QRect rect;
    QFont font;

};

#endif // DRAWSETTINGSMODULES_H
