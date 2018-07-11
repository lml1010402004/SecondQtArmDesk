#ifndef SEARCHRESULTOFBOOK_H
#define SEARCHRESULTOFBOOK_H

#include <QMainWindow>
#include"statusbar.h"
#include"statusbar_global.h"
#include<QPaintEvent>
#include<QMouseEvent>
#include<QPainter>
#include"drawViewfunctions/drawsearchresultofbooks.h"
#include<QRect>
#include<QList>
#include"database/database.h"
#include<QLineEdit>

class searchResultofBook : public QMainWindow
{
    Q_OBJECT
public:
    explicit searchResultofBook(QWidget *parent = 0);
    void init();
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent* event);


private :
    StatusBar *mystatusbar;
    QPainter *painter;
    drawSearchResultofBooks *drawsearchresultbooks;
    void backToHomePage();
    QLineEdit * mylineedit;
    QList<localDirectoryItem> *searchoutresultbooklist;


    QRect rect;

signals:
    void showPullDownSignal();
    void searchBooksSignal(QString str);


public slots:
    void getSearchOutBookList(QString str);
      void updateTimeAndBatteryValue(QString time,int battery);



};

#endif // SEARCHRESULTOFBOOK_H
