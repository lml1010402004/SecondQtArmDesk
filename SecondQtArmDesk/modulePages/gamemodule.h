#ifndef GAMEMODULE_H
#define GAMEMODULE_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include<applications.h>
#include<QPaintEvent>
#include<QPainter>
#include<QMouseEvent>
#include<statusbar.h>
#include<statusbar_global.h>
#include"drawViewfunctions/drawgamepageview.h"
#include"syssettings.h"
#include<QRect>



class GameModule:public QMainWindow
{
    Q_OBJECT
public:
    GameModule(QWidget *widget=0);
    ~GameModule();
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    void init();

private :
     SysSettings *mysyssetting;
     QRect rect;

    QPainter *painter;

    StatusBar *statusbar;
    drawGamePageView *drawgamepageview;


signals:
    void showPulldownWindowSignal();
    void backToMainpageSignal();

public slots:
    void backToMainpageSlot();
        void updateTimeAndBatteryValue(QString time,int battery);


};

#endif // GAMEMODULE_H
