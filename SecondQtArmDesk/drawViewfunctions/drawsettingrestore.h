#ifndef DRAWSETTINGRESTORE_H
#define DRAWSETTINGRESTORE_H

#include<QRect>
#include<QLineF>
#include<QPainter>
#include<drawViewfunctions/drawsettingrestore.h>
#include<QFont>
#include<QObject>



class drawSettingRestore
{
public:
    drawSettingRestore();
    ~drawSettingRestore();

    void drawHomeIcon(QPainter *painter);
    void drawBackIcon(QPainter *painter);
    void drawRestoreTitle(QPainter *painter);
    void drawRestoreButton(QPainter *painter);

    void init();

private:
    QLineF line;
    QRect rect;
    QFont font;





};

#endif // DRAWSETTINGRESTORE_H
