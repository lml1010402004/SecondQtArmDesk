#include "drawsearchresultofbooks.h"

extern QString homeiconpath;

int draw_search_result[8] = {0,96,600,96,500,50,30,29};

extern QString path3;

/**
 * @brief drawSearchResultofBooks::drawHomeIcon
 * @param painter
 */
drawSearchResultofBooks::drawSearchResultofBooks()
{

}

void drawSearchResultofBooks::drawHomeIcon(QPainter *painter)
{
    line.setLine(draw_search_result[0],draw_search_result[1],draw_search_result[2],draw_search_result[3]);
    painter->drawLine(line);
    rect.setX(draw_search_result[4]);
    rect.setY(draw_search_result[5]);
    rect.setWidth(draw_search_result[6]);
    rect.setHeight(draw_search_result[7]);
    painter->drawPixmap(rect,homeiconpath);

}



/**
 * @brief drawSearchResultofBooks::drawSearchButton
 * @param painter
 */
void drawSearchResultofBooks::drawSearchButton(QPainter *painter)
{
  rect.setX(480);
  rect.setY(140);
  rect.setWidth(80);
  rect.setHeight(40);
  painter->drawText(rect,QString("Search"));
  painter->drawRect(rect);

}



int position44[] = {66,180,200,180,110,140,66,180,340,180,150,25};

int position55[] = {66,180,200,180,110,140,66,180,340,180,150,25};
void drawSearchResultofBooks::drawSearchOutBooks(QPainter *painter, QList<localDirectoryItem> *list)
{
    if(list->size()==0)
        return;
    int size = list->size();
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
            rect.setX(position44[0]+position44[1]*j);
            rect.setY(position44[2]+position44[3]*i);
            rect.setWidth(position44[4]);
            rect.setHeight(position44[5]);
            painter->drawRect(rect);

            QString cover_path = list->at(i*3+j).file_path+".jpg";
            QFileInfo *info = new QFileInfo(cover_path);
            if(info->exists()){
              painter->drawPixmap(rect,cover_path);
            }else{
                painter->drawPixmap(rect,path3);
            }


            rect.setX(position44[6]+position44[7]*j);
            rect.setY(position44[8]+position44[9]*i);
            rect.setWidth(position44[10]);
            rect.setHeight(position44[11]);
            font.setPointSize(10);
            painter->setFont(font);
            painter->drawText(rect,list->at(i*3+j).file_name);
        }

    }else{
        for(int k=0;k<columsoflastrow;k++){
            rect.setX(position55[0]+position55[1]*k);
            rect.setY(position55[2]+position55[3]*i);
            rect.setWidth(position55[4]);
            rect.setHeight(position55[5]);
            painter->drawRect(rect);

            QString cover_path = list->at(i*3+k).file_path+".jpg";
            QFileInfo *info = new QFileInfo(cover_path);
            if(info->exists()){
              painter->drawPixmap(rect,cover_path);
            }else{
              painter->drawPixmap(rect,path3);
            }
            rect.setX(position55[6]+position55[7]*k);
            rect.setY(position55[8]+position55[9]*i);
            rect.setWidth(position55[10]);
            rect.setHeight(position55[11]);
            font.setPointSize(10);
            painter->setFont(font);
            painter->drawText(rect,list->at(i*3+k).file_name);
        }
    }
 }


}

extern int draw_settting_tab2[8];
extern QString BACKLASTSTEPICON;
void drawSearchResultofBooks::drawBackIcon(QPainter *painter)
{
    rect.setX(draw_settting_tab2[0]);
    rect.setY(draw_settting_tab2[1]);
    rect.setWidth(draw_settting_tab2[2]);
    rect.setHeight(draw_settting_tab2[3]);
    painter->drawPixmap(rect,BACKLASTSTEPICON);
    line.setLine(draw_settting_tab2[4],draw_settting_tab2[5],draw_settting_tab2[6],draw_settting_tab2[7]);
    painter->drawLine(line);
}
