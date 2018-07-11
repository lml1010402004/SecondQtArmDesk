#ifndef SWITCHLANGUAGEDIALOG_H
#define SWITCHLANGUAGEDIALOG_H

#include <QObject>
#include<QDialog>
#include<QPainter>
#include<QPaintEvent>
#include<QMouseEvent>
#include"drawViewfunctions/drawswitchlanguagedailog.h"
#include<QList>
#include<QString>
#include<QTranslator>

class switchLanguageDialog : public QDialog
{
public:
    switchLanguageDialog(QWidget *parent);

    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void init();

    int getIndexFromGeograh(int x,int y);

private:
    QPainter *painter;
    drawSwitchLanguageDailog *myswitchlanguagedialog;
    QList<QString> *list;





};

#endif // SWITCHLANGUAGEDIALOG_H
