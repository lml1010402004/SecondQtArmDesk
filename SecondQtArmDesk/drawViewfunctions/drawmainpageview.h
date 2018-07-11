#ifndef DRAWMAINPAGEVIEW_H
#define DRAWMAINPAGEVIEW_H
#include<QPainter>
#include<QString>
#include<QRect>
#include<QFont>
#include<QList>
#include<dataItem/bookinfoitem.h>
#include"database/database.h"

#define MAINPAGEBOOKCOVER_X 52
#define MAINPAGEBOOKCOVER_Y 87
#define MAINPAGEBOOKCOVER_WIDTH 160
#define MAINPAGEBOOKCOVER_HEIGHT 210

#define MAINPAGEBOOKTITLE_X 270
#define MAINPAGEBOOKTITLE_Y 100
#define MAINPAGEBOOKTITLE_WIDTH 300
#define MAINPAGEBOOKTITLE_HEIGHT 80

#define MAINPAGEBOOKAUTHOR_X 290
#define MAINPAGEBOOKAUTHOR_Y 154
#define MAINPAGEBOOKAUTHOR_WIDTH 250
#define MAINPAGEBOOKAUTHOR_HEIGT 30

#define MAINPAGEBOOKPROGRESS_X 270
#define MAINPAGEBOOKPROGRESS_Y 180
#define MAINPAGEBOOKPROGRESS_WIDTH 200
#define MAINPAGEBOOKPROGRESS_HEIGHT 30


#define MAINPAGEBOOKBREFCONTENT_X 270
#define MAINPAGEBOOKBREFCONTENT_Y 210
#define MAINPAGEBOOKBREFCONTENT_WIDTH 280
#define MAINPAGEBOOKBREFCONTENT_HEIGHT 120

#define NORMALSIZEOFFONT 10
#define TWICESIZEFONT 20




class drawMainPageView
{
public:
    drawMainPageView();
    ~drawMainPageView();

    void drawCurrentBookTitle(QPainter *painter,QString bookTitle);
    void drawCurrentBookCover(QPainter *painter,QString bookCoverPath);
    void drawCurrentBookAuthor(QPainter *painter,QString bookAuthor);
    void drawCurrentBookBrefContent(QPainter *painter,QString bookbrefContent);
    void drawCurrentBookProgress(QPainter *painter,int percentage);

    void drawThreeBooksOfCurrentPage(QPainter *painter,QList<localDirectoryItem> *booklist);



    void drawLastPage(QPainter *painter,int index);
    void drawNextPage(QPainter *painter,int index);
    void drawTextView(QPainter *painter);
    void drawThreeModulesonBottom(QPainter *painter,int index);





private:
    QRect rect;
    QFont font;



};

#endif // DRAWMAINPAGEVIEW_H
