#ifndef SETTINGSCREEN_H
#define SETTINGSCREEN_H

#include <QMainWindow>
#include<QPaintEvent>
#include<QMouseEvent>
#include"applications.h"
#include"statusbar.h"
#include"statusbar_global.h"
#include"drawViewfunctions/drawsettingscreen.h"
#include<QPainter>
//#include<dataItem/wallpaperitem.h>
//#include<QList>
#include"syssettings.h"
#include<QRect>


class settingScreen : public QMainWindow
{
    Q_OBJECT
public:
    explicit settingScreen(QWidget *parent = 0);
    ~settingScreen();
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);


    void init();


private:
     SysSettings *mysysseting;
     QRect rect;

    QPainter *painter;
    StatusBar *statusbar_screen;
    drawSettingScreen *drawsettingscreen;
//    QList<WallPaperItem> *list;

    int index_wallpaper;//scope 0,1,2


signals:
    void showPullDownSignal();
    void backToHomePageSignal();

public slots:

    void backToHomePageSlot();
      void updateTimeAndBatteryValue(QString time,int battery);

};

#endif // SETTINGSCREEN_H
