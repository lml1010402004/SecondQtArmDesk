#ifndef BOOKSHELF_H
#define BOOKSHELF_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include<QPaintEvent>
#include<QPainter>
#include<statusbar.h>
#include<statusbar_global.h>
#include<applications.h>
#include<drawViewfunctions/drawbookshelfpageview.h>
#include<modulePages/pulldownwindow.h>
#include<dataItem/conditionitem.h>
#include<database/database.h>
#include"utils/commonutils.h"
#include<QProcess>
#include"syssettings.h"
#include<QRect>
#include<QObject>




class BookShelf : public QMainWindow
{
    Q_OBJECT
public:

    explicit BookShelf(QWidget *parent = 0);
    ~BookShelf();
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

    void mouseMoveEvent(QMouseEvent *event);

    int getTheTargetBookIndex(int x_pos ,int y_pos);

private :

    int position_old_x;

    bool move_event;

    QRect rect;
     SysSettings *mysyssetting;

    int show_progress_bar;

    commonUtils * commonutils;
    QProcess *mprocess;

    int index_select;

    StatusBar *statusbar;
    drawBookshelfPageView *drawbookshelf;

    QPainter *painter;
    void init();
    void initConnections();


    QList<QString> list;

    QList<ConditionItem> *conditonsItemlist;
    QList<localDirectoryItem> *currentpagebookinfolist;
    QList<localDirectoryItem> *totalbookinfolist;

    ConditionItem conditionitem;
    localDirectoryItem bookinforitem;


    int current_page;
    int total_pages;
    int getTotalPagesForEachCondition(QList<localDirectoryItem> *list);

    QList<localDirectoryItem>* getCurrentPageBooklist(QList<localDirectoryItem> *list,int currentpage);





signals:
    void backHomePagesignal();
    void showPullWindowSignal();
    void updateDataSignal();
    void openBookSignal(int index);


public slots:
    void backHomePageSlot();
    void updateDataSlot();
    void openBookSlot(int index);
    void processFinisheds();
     void updateTimeAndBatteryValue(QString time,int battery);

};

#endif // BOOKSHELF_H
