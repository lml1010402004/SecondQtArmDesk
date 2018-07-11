#ifndef DRAWBOOKSHELFPAGEVIEW_H
#define DRAWBOOKSHELFPAGEVIEW_H

#include<QPainter>
#include<dataItem/bookinfoitem.h>
#include<QString>
#include<QRect>
#include<dataItem/conditionitem.h>
#include<QLine>
#include"database/database.h"
#include<QFont>

class drawBookshelfPageView
{


   private:
     QRect rect;
     QLine line;
     QFont font;


public:
    drawBookshelfPageView();


    void drawHomeButton(QPainter *painter, bool flag);
    void drawArrangeTextView(QPainter *painter,QString str);
    void drawSelectCondition(QPainter *painter,QList<ConditionItem> *conditionlist,int index);
    void drawNineBooks(QPainter *painter,QList<localDirectoryItem> *booklist);

    void drawTheFirstAndLastPageIcon(QPainter *painter);
    void drawTheNextAndEndPageIcon(QPainter *painter);
    void drawCurrentPageAndTotalPages(QPainter *painter,int currnetPage,int totalPages);


};

#endif // DRAWBOOKSHELFPAGEVIEW_H
