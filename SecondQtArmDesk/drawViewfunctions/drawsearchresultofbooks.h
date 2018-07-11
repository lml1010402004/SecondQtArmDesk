#ifndef DRAWSEARCHRESULTOFBOOKS_H
#define DRAWSEARCHRESULTOFBOOKS_H
#include<QPainter>
#include<QLineF>
#include<QRect>
#include"database/database.h"
#include<QFont>

class drawSearchResultofBooks
{
public:
    drawSearchResultofBooks();

    void drawHomeIcon(QPainter *painter);
    void drawSearchButton(QPainter *painter);
    void drawSearchOutBooks(QPainter *painter,QList<localDirectoryItem> *list);
    void drawBackIcon(QPainter *painter);

private:
    QLine line;
    QRect rect;
    QFont font;

};

#endif // DRAWSEARCHRESULTOFBOOKS_H
