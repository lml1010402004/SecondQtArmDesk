#ifndef BOOKONLINE_H
#define BOOKONLINE_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include<applications.h>
#include<QPaintEvent>
#include<QMouseEvent>
#include"statusbar.h"
#include"statusbar_global.h"
#include<QPainter>
#include"drawViewfunctions/drawbookonlinepageview.h"
#include"syssettings.h"
#include<QRect>




class BookOnLine:public QMainWindow
{
    Q_OBJECT
public:
    BookOnLine(QWidget *widget=0);
    ~BookOnLine();
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    void init();
    void initConnections();

private :
      SysSettings  *mysyssetting;
      QRect rect;


    QPainter *painter;
    StatusBar *statusbar;
    drawBookOnlinePageView *drawbookonlinepageview;


signals:
    void showPulldownWindowSignal();
    void backToMainpageSignal();

public slots:

    void backToMainpageSlot();
     void updateTimeAndBatteryValue(QString time,int battery);



};

#endif // BOOKONLINE_H
