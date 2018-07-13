#include "drawbookshelfpageview.h"
#include<QDebug>


extern QString homeiconpath;

static QString back = ":/mypic/pics/back_arrow.png";
static QString backtostart = ":/mypic/pics/back_to_start.png";
static QString forward = ":/mypic/pics/forward.png";
static QString forwardtolast = ":/mypic/pics/forward_to_last.png";

int position1[8] = {0,96,600,96,500,50,30,29};
int position2[4] = {55,110,60,40};
int position3[10] = {120,120,120,12,12,140,120,110,110,60};

QString indexconditionselected = ":/mypic/pics/circlesfilled.png";

extern QString path3;

int position4[] = {66,180,165,180,110,140,66,180,300,180,150,25};

int position5[] = {66,180,165,180,110,140,66,180,300,180,150,25};



int draw_bksp_pos[8] = {150,730,15,18,210,730,15,18};
int draw_bksp_pos1[8] = {370,730,15,18,420,730,15,18};
int drawcurrentpage_position[] = {280,740,50,35};

drawBookshelfPageView::drawBookshelfPageView()
{

}





/**
 * @brief BookShelf::drawHomeButton
 * @param painter
 * @param flag
 */
void drawBookshelfPageView::drawHomeButton(QPainter *painter, bool flag)
{

    line.setLine(position1[0],position1[1],position1[2],position1[3]);
    painter->drawLine(line);
    rect.setX(position1[4]);
    rect.setY(position1[5]);
    rect.setWidth(position1[6]);
    rect.setHeight(position1[7]);
    painter->drawPixmap(rect,homeiconpath);

}



/**
 * @brief BookShelf::drawArrangeTextView
 * @param painter
 * @param str
 */
void drawBookshelfPageView::drawArrangeTextView(QPainter *painter, QString str)
{
    rect.setX(position2[0]);
    rect.setY(position2[1]);
    rect.setWidth(position2[2]);
    rect.setHeight(position2[3]);
    painter->drawText(rect,str);

}



/**
 * @brief BookShelf::drawSelectCondition
 * @param painter
 * @param conditions
 */
void drawBookshelfPageView::drawSelectCondition(QPainter *painter,QList<ConditionItem> *conditionlist,int index)
{
    int size = conditionlist->size();
   for(int i =0;i<size;i++){
      rect.setX(position3[0]+position3[1]*i);
      rect.setY(position3[2]);
      rect.setWidth(position3[3]);
      rect.setHeight(position3[4]);
      if(i==index){
      painter->drawPixmap(rect,indexconditionselected);
      }else{
      painter->drawPixmap(rect,conditionlist->at(i).circle_path);
      }
      rect.setX(position3[5]+position3[6]*i);
      rect.setY(position3[7]);
      rect.setWidth(position3[8]);
      rect.setHeight(position3[9]);
      painter->drawText(rect,conditionlist->at(i).text_str);

   }


}



/**
 * @brief BookShelf::drawNineBooks
 * @param painter
 * @param booklist
 */
void drawBookshelfPageView::drawNineBooks(QPainter *painter, QList<localDirectoryItem> *booklist)
{
    int size = booklist->size();
    int rows = 0;
    int columsoflastrow = size%3;
    if(size%3!=0){
        rows = size/3+1;
    }else{
        rows = size/3;
    }

for(int i=0;i<rows;i++){
    if(i!=rows-1||columsoflastrow==0){
        for(int j=0;j<3;j++){
            rect.setX(position4[0]+position4[1]*j);
            rect.setY(position4[2]+position4[3]*i);
            rect.setWidth(position4[4]);
            rect.setHeight(position4[5]);
            painter->drawRect(rect);
            rect.setX(position4[0]+position4[1]*j+1);
            rect.setY(position4[2]+position4[3]*i+1);
            rect.setWidth(position4[4]-1);
            rect.setHeight(position4[5]-1);
            QString cover_path = booklist->at(i*3+j).file_path+".jpg";
            QFileInfo *info = new QFileInfo(cover_path);
            if(info->exists()){
              painter->drawPixmap(rect,cover_path);
            }else{
                painter->drawPixmap(rect,path3);
            }


            rect.setX(position4[6]+position4[7]*j);
            rect.setY(position4[8]+position4[9]*i);
            rect.setWidth(position4[10]);
            rect.setHeight(position4[11]);
            font.setPointSize(10);
            painter->setFont(font);
            QString temp = booklist->at(i*3+j).file_name.split("-").at(0);
            painter->drawText(rect,temp);
        }

    }else{
        for(int k=0;k<columsoflastrow;k++){
            rect.setX(position5[0]+position5[1]*k);
            rect.setY(position5[2]+position5[3]*i);
            rect.setWidth(position5[4]);
            rect.setHeight(position5[5]);
            painter->drawRect(rect);
            rect.setX(position5[0]+position5[1]*k+1);
            rect.setY(position5[2]+position5[3]*i+1);
            rect.setWidth(position5[4]-1);
            rect.setHeight(position5[5]-1);
            QString cover_path = booklist->at(i*3+k).file_path+".jpg";
            QFileInfo *info = new QFileInfo(cover_path);
            if(info->exists()){
              painter->drawPixmap(rect,cover_path);
            }else{
              painter->drawPixmap(rect,path3);
            }
            rect.setX(position5[6]+position5[7]*k);
            rect.setY(position5[8]+position5[9]*i);
            rect.setWidth(position5[10]);
            rect.setHeight(position5[11]);
            font.setPointSize(10);
            painter->setFont(font);
            QString temp = booklist->at(i*3+k).file_name.split("-").at(0);
            painter->drawText(rect,temp);
        }
    }
 }

}



/**
 * @brief BookShelf::drawTheFirstAndLastPageIcon
 * @param painter
 */
void drawBookshelfPageView::drawTheFirstAndLastPageIcon(QPainter *painter)
{
        rect.setX(draw_bksp_pos[0]);
        rect.setY(draw_bksp_pos[1]);
        rect.setWidth(draw_bksp_pos[2]);
        rect.setHeight(draw_bksp_pos[3]);
        painter->drawPixmap(rect,backtostart);
        rect.setX(draw_bksp_pos[4]);
        rect.setY(draw_bksp_pos[5]);
        rect.setWidth(draw_bksp_pos[6]);
        rect.setHeight(draw_bksp_pos[7]);
        painter->drawPixmap(rect,back);

}



/**
 * @brief BookShelf::drawTheNextAndEndPageIcon
 * @param painter
 */
void drawBookshelfPageView::drawTheNextAndEndPageIcon(QPainter *painter)
{
rect.setX(draw_bksp_pos1[0]);
rect.setY(draw_bksp_pos1[1]);
rect.setWidth(draw_bksp_pos1[2]);
rect.setHeight(draw_bksp_pos1[3]);
painter->drawPixmap(rect,forward);
rect.setX(draw_bksp_pos1[4]);
rect.setY(draw_bksp_pos1[5]);
rect.setWidth(draw_bksp_pos1[6]);
rect.setHeight(draw_bksp_pos1[7]);
painter->drawPixmap(rect,forwardtolast);


}


/**
 * @brief drawBookshelfPageView::drawCurrentPageAndTotalPages
 * @param painter
 * @param currnetPage
 * @param totalPages
 */
void drawBookshelfPageView::drawCurrentPageAndTotalPages(QPainter *painter, int currnetPage, int totalPages)
{
    if(totalPages>0){
    rect.setX(drawcurrentpage_position[0]);
    rect.setY(drawcurrentpage_position[1]);
    rect.setWidth(drawcurrentpage_position[2]);
    rect.setHeight(drawcurrentpage_position[3]);
    painter->drawText(rect,QString::number(currnetPage)+"/"+QString::number(totalPages));
    }

}
