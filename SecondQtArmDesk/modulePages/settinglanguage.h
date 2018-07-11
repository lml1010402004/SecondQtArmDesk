#ifndef SETTINGLANGUAGE_H
#define SETTINGLANGUAGE_H

#include <QMainWindow>
#include<QMouseEvent>
#include<QPaintEvent>
#include<QPainter>
#include"statusbar.h"
#include"statusbar_global.h"

#include"drawViewfunctions/drawsettinglanguage.h"
#include"switchlanguagedialog.h"
#include"syssettings.h"
#include<QRect>



class settingLanguage : public QMainWindow
{
    Q_OBJECT
public:
    explicit settingLanguage(QWidget *parent = 0);
    ~settingLanguage();
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);


    void init();



private:
  SysSettings *mysysseting;

    drawSettingLanguage *drawsettinglanguage;
    StatusBar *statusbar;
    QPainter *painter;
    switchLanguageDialog *myswitchlanguagedialog;
    QRect rect;


signals:
    void showPullDownSignal();
    void backToHomePageSignal();

public slots:
    void backToHomePageSlot();
     void updateTimeAndBatteryValue(QString time,int battery);

};

#endif // SETTINGLANGUAGE_H
