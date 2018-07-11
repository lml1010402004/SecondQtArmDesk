#ifndef CONNECTWIFIDIALOG_H
#define CONNECTWIFIDIALOG_H

#include <QWidget>
#include<QDialog>
#include<QRect>
#include<QPaintEvent>
#include<QPainter>
#include<QMouseEvent>
#include"drawViewfunctions/drawconnectwifidialog.h"
#include<QLineEdit>
#include<QString>

class connectWifiDialog : public QDialog
{
    Q_OBJECT
public:
    connectWifiDialog(QWidget *widget=0);
~connectWifiDialog();
    QPainter *painter;
    QRect rect;
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);

    void init();


signals:
    void connectWifiSignal(QString password);

public slots:



private:
    drawConnectWifiDialog *drawconnectwifidialog;
    QLineEdit *mylineedit;

};

#endif // CONNECTWIFIDIALOG_H
