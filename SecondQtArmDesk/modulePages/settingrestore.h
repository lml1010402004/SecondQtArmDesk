#ifndef SETTINGRESTORE_H
#define SETTINGRESTORE_H

#include <QMainWindow>
#include<QMouseEvent>
#include<QPaintEvent>
#include<QPainter>
#include"statusbar.h"
#include"statusbar_global.h"
#include"drawViewfunctions/drawsettingrestore.h"
#include"syssettings.h"
#include<QRect>

class settingRestore : public QMainWindow
{
    Q_OBJECT
public:
    explicit settingRestore(QWidget *parent = 0);
    ~settingRestore();
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    void formattingDisk();

    void init();


private:
    SysSettings *mysyssetting;

    drawSettingRestore *drawsettingrestore;
    StatusBar *statusbar;
    QPainter *painter;
    void backToHomePage();
    QRect rect;


signals:
    void showPullDownSignal();
    void backToHomePageSignal();

public slots:
    void backTOHomePageSlot();
      void updateTimeAndBatteryValue(QString time,int battery);

};

#endif // SETTINGRESTORE_H
