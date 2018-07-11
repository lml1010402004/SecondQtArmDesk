#ifndef SETDATEANDHOUR_H
#define SETDATEANDHOUR_H

#include <QMainWindow>
#include<QLineEdit>
#include<drawViewfunctions/drawdateandhour.h>
#include<QPaintEvent>
#include<QMouseEvent>
#include<QPainter>
#include<statusbar.h>
#include<statusbar_global.h>

class setDateAndHour : public QMainWindow
{
    Q_OBJECT
public:
    explicit setDateAndHour(QWidget *parent = 0);
    ~setDateAndHour();

    void init();
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);


private:

    QLineEdit *mylineedit1;
    QLineEdit *mylineedit2;
    drawDateAndHour *drawdateandhour;
    QPainter *painter;


    void setDateandHourIntoSystem(QString date);



signals:
  void updateTimeRightnowSignal();

public slots:
};

#endif // SETDATEANDHOUR_H
