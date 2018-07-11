#include "drawmainpageview.h"
#include<QDebug>


QString homeiconpath = ":/mypic/pics/homeicon.png";

QString nextpage_path = ":/mypic/pics/nextpage_rectangle.png";
QString lastpage_path = ":/mypic/pics/lastpage_rectangle.png";
QString booklibray_path=":/mypic/pics/book_library.png";
QString bookcity = ":/mypic/pics/bookcity.png";
QString gamepath = ":/mypic/pics/game.png";

QString cover_group[3] = {":/mypic/pics/txt_cover.png",":/mypic/pics/pdf_cover.png",":/mypic/pics/epub_cover.png"};



drawMainPageView::drawMainPageView()
{

}


/**
 * @brief drawMainPageView::drawCurrentBookTitle
 * @param painter
 * @param bookTitle
 */
void drawMainPageView::drawCurrentBookTitle(QPainter *painter, QString bookTitle)
{
    font.setPointSize(TWICESIZEFONT-8);
    rect.setX(MAINPAGEBOOKTITLE_X);
    rect.setY(MAINPAGEBOOKTITLE_Y);
    rect.setWidth(MAINPAGEBOOKTITLE_WIDTH);
    rect.setHeight(MAINPAGEBOOKTITLE_HEIGHT);
    painter->setFont(font);
    painter->drawText(rect,bookTitle.split(".")[0]);

}

/**
 * @brief drawMainPageView::drawCurrentBookCover
 * @param painter
 */
void drawMainPageView::drawCurrentBookCover(QPainter *painter,QString bookCover)
{

   font.setPointSize(NORMALSIZEOFFONT);
   rect.setX(MAINPAGEBOOKCOVER_X);
   rect.setY(MAINPAGEBOOKCOVER_Y);
   rect.setWidth(MAINPAGEBOOKCOVER_WIDTH);
   rect.setHeight(MAINPAGEBOOKCOVER_HEIGHT);
   painter->drawRect(rect);

   QFileInfo *tempFile = new QFileInfo(bookCover+".jpg");
   if(tempFile->exists()){

   painter->drawPixmap(rect,bookCover+".jpg");
   }else{
    QFileInfo *tempFile1 = new QFileInfo(bookCover);

     if(tempFile1->suffix().endsWith("txt")){
        painter->drawPixmap(rect,cover_group[0]);
     }else if(tempFile1->suffix().endsWith("pdf")){
        painter->drawPixmap(rect,cover_group[2]);
     }else if(tempFile1->suffix().endsWith("epub")){
        painter->drawPixmap(rect,cover_group[1]);
     }

   }


}


/**
 * @brief drawMainPageView::drawCurrentBookAuthor
 * @param painter
 */
void drawMainPageView::drawCurrentBookAuthor(QPainter *painter,QString bookAuthor)
{
    font.setPointSize(NORMALSIZEOFFONT);
    rect.setX(MAINPAGEBOOKAUTHOR_X);
    rect.setY(MAINPAGEBOOKAUTHOR_Y);
    rect.setWidth(MAINPAGEBOOKAUTHOR_WIDTH);
    rect.setHeight(MAINPAGEBOOKAUTHOR_HEIGT);
    painter->setFont(font);
    painter->drawText(rect,QObject::tr("Author:")+bookAuthor);

}



/**
 * @brief drawMainPageView::drawCurrentBookBrefContent
 * @param painter
 */
void drawMainPageView::drawCurrentBookBrefContent(QPainter *painter,QString brefContent)
{
    font.setPointSize(NORMALSIZEOFFONT);
    rect.setX(MAINPAGEBOOKBREFCONTENT_X);
    rect.setY(MAINPAGEBOOKBREFCONTENT_Y);
    rect.setWidth(MAINPAGEBOOKBREFCONTENT_WIDTH);
    rect.setHeight(MAINPAGEBOOKBREFCONTENT_HEIGHT);
    painter->setFont(font);
    painter->drawText(rect,QObject::tr("       Bref:")+brefContent);


}

void drawMainPageView::drawCurrentBookProgress(QPainter *painter, int percentage)
{
    font.setPointSize(NORMALSIZEOFFONT);
    rect.setX(MAINPAGEBOOKPROGRESS_X);
    rect.setY(MAINPAGEBOOKPROGRESS_Y);
    rect.setWidth(MAINPAGEBOOKPROGRESS_WIDTH);
    rect.setHeight(MAINPAGEBOOKPROGRESS_HEIGHT);
    painter->setFont(font);
    painter->drawText(rect,QObject::tr("Progress:")+QString::number(percentage));

}


int draw_main_page1[10] = {95,150,450,110,150,110,150,610,110,80};
/**
 * three books we set each page.
 *  @brief drawMainPageView::drawBooksOfCurrentPage
 * @param painter
 */
void drawMainPageView::drawThreeBooksOfCurrentPage(QPainter *painter,QList<localDirectoryItem> *booklist)
{
//在这里把坐标和大小全部写出来,传进来的书本参数只有两个是我们需要的.
int size = booklist->size();
  if(size>0){
    for(int i=0;i<size;i++){
    rect.setX(draw_main_page1[0]+draw_main_page1[1]*i);
    rect.setY(draw_main_page1[2]);
    rect.setWidth(draw_main_page1[3]);
    rect.setHeight(draw_main_page1[4]);
    localDirectoryItem item = booklist->at(i);
    QString temppath ;
    QFile *tempFile = new QFile(item.file_path+".jpg");
    if(tempFile->exists()){
        temppath = item.file_path+".jpg";
    }else{

        if(item.file_type==0){
         temppath = cover_group[0];
        }else if(item.file_type==1){
            temppath = cover_group[2];
        }else if(item.file_type==2){
            temppath = cover_group[1];
        }
    }

    painter->drawRect(rect);
    painter->drawPixmap(rect,temppath);

    rect.setX(draw_main_page1[5]+draw_main_page1[6]*i);
    rect.setY(draw_main_page1[7]);
    rect.setWidth(draw_main_page1[8]);
    rect.setHeight(draw_main_page1[9]);

    painter->drawText(rect,item.file_name);

  }
}

}


int draw_main_page2[4] = {44,505,16,16};
/**
 * @brief drawMainPageView::drawLastPage
 * @param painter
 */
void drawMainPageView::drawLastPage(QPainter *painter,int index)
{
    rect.setX(draw_main_page2[0]);
    rect.setY(draw_main_page2[1]);
    rect.setWidth(draw_main_page2[2]);
    rect.setHeight(draw_main_page2[3]);
    painter->drawPixmap(rect,lastpage_path);

}


int draw_main_page3[4] = {526,505,16,16};
/**
 * @brief drawMainPageView::drawNextPage
 * @param painter
 */
void drawMainPageView::drawNextPage(QPainter *painter,int index)
{
   rect.setX(draw_main_page3[0]);
   rect.setY(draw_main_page3[1]);
   rect.setWidth(draw_main_page3[2]);
   rect.setHeight(draw_main_page3[3]);
   painter->drawPixmap(rect,nextpage_path);

}


int draw_main_page4[4] = {230,400,200,40};
/**
 * @brief drawMainPageView::drawTextView
 * @param painter
 */
void drawMainPageView::drawTextView(QPainter *painter)
{
    font.setPointSize(TWICESIZEFONT);
    rect.setX(draw_main_page4[0]);
    rect.setY(draw_main_page4[1]);
    rect.setWidth(draw_main_page4[2]);
    rect.setHeight(draw_main_page4[3]);
    painter->drawText(rect,QObject::tr("RecentBooks"));

}


int draw_main_page5[6] = {0,200,400,715,200,1};
int draw_main_page6[12] = {0,715,600,1,79,720,42,39,60,765,120,42};
int draw_main_page7[8] = {289,720,42,39,270,765,120,42};
int draw_main_page8[8] = {479,720,42,39,470,765,120,42};
/**
 * @brief drawMainPageView::drawThreeModulesonBottom
 * @param painter
 */
void drawMainPageView::drawThreeModulesonBottom(QPainter *painter,int index)
{
    if(index>0){
        if(index==1){
        rect.setX(draw_main_page5[0]);
        }else if(index==2){
        rect.setX(draw_main_page5[1]);
        }else if(index==3){
        rect.setX(draw_main_page5[2]);
        }
        rect.setY(draw_main_page5[3]);
        rect.setWidth(draw_main_page5[4]);
        rect.setHeight(draw_main_page5[5]);
        //painter->drawRect(rect);
    }else {
        rect.setX(draw_main_page6[0]);
        rect.setY(draw_main_page6[1]);
        rect.setWidth(draw_main_page6[2]);
        rect.setHeight(draw_main_page6[3]);
       // painter->drawRect(rect);
    }


rect.setX(draw_main_page6[4]);
rect.setY(draw_main_page6[5]);
rect.setWidth(draw_main_page6[6]);
rect.setHeight(draw_main_page6[7]);
painter->drawPixmap(rect,booklibray_path);

rect.setX(draw_main_page6[8]);
rect.setY(draw_main_page6[9]);
rect.setWidth(draw_main_page6[10]);
rect.setHeight(draw_main_page6[11]);
painter->drawText(rect,QObject::tr("BookShelf"));

rect.setX(draw_main_page7[0]);
rect.setY(draw_main_page7[1]);
rect.setWidth(draw_main_page7[2]);
rect.setHeight(draw_main_page7[3]);
painter->drawPixmap(rect,bookcity);

rect.setX(draw_main_page7[4]);
rect.setY(draw_main_page7[5]);
rect.setWidth(draw_main_page7[6]);
rect.setHeight(draw_main_page7[7]);
painter->drawText(rect,QObject::tr("BookCity"));


rect.setX(draw_main_page8[0]);
rect.setY(draw_main_page8[1]);
rect.setWidth(draw_main_page8[2]);
rect.setHeight(draw_main_page8[3]);
painter->drawPixmap(rect,gamepath);

rect.setX(draw_main_page8[4]);
rect.setY(draw_main_page8[5]);
rect.setWidth(draw_main_page8[6]);
rect.setHeight(draw_main_page8[7]);
painter->drawText(rect,QObject::tr("Game"));


}




