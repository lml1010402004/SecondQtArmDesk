#include "drawpulldonwwindow.h"

QString closewindow = ":/mypic/pics/closewindow.png";
QString ellipsepath = ":/mypic/pics/ellipse.png";

int draw_pull_donw1[] = {275,260,40,23};

int draw_pull_donw2[] ={0,0,600,300};

int draw_pull_donw3[4] = {0,300,600,500};

int draw_pull_donw4[5] = {96,156,40,56,58};
int draw_pull_donw5[12] = {96,150,60,60,175,180,475,180,175,170,20,20};

drawpulldonwwindow::drawpulldonwwindow()
{

}


/**
 * @brief drawpulldonwwindow::drawSettingShoutcutItem
 * @param painter
 */
void drawpulldonwwindow::drawSettingShoutcutItem(QPainter *painter)
{
    //draw wifi shortcut



}



/**
 * @brief drawpulldonwwindow::drawcloseWindow
 * @param painter
 */
void drawpulldonwwindow::drawCloseIcon(QPainter *painter)
{

    rect.setX(275);
    rect.setY(260);
    rect.setWidth(27);
    rect.setHeight(12);
    painter->drawPixmap(rect,closewindow);

//    line.setLine(0,295,600,295);
//    painter->drawLine(line);

}

void drawpulldonwwindow::drawShutcutArea(QPainter *painter)
{
    rect.setX(0);
    rect.setY(0);
    rect.setWidth(600);
    rect.setHeight(300);

    QBrush brush(QColor(255,255,255));
       painter->setBrush(brush);
       painter->drawRoundedRect(rect,0,0);

}


void drawpulldonwwindow::drawgrayArea(QPainter *painter,int alpha)
{

    QBrush brush1(QColor(100,100,100,alpha));
    painter->setBrush(brush1);
    rect.setX(draw_pull_donw3[0]);
    rect.setY(draw_pull_donw3[1]);
    rect.setWidth(draw_pull_donw3[2]);
    rect.setHeight(draw_pull_donw3[3]);
    painter->drawRoundedRect(rect,0,0);

}

/**
 * @brief drawpulldonwwindow::drawShortcutIcons
 * @param painter
 * @param pathlist
 */
void drawpulldonwwindow::drawShortcutIcons(QPainter *painter, QList<QString> pathlist)
{
  for(int i=0;i<pathlist.size();i++){
   rect.setX(draw_pull_donw4[0]+draw_pull_donw4[1]*i);
   rect.setY(draw_pull_donw4[2]);
   rect.setWidth(draw_pull_donw4[3]);
   rect.setHeight(draw_pull_donw4[4]);
   painter->drawPixmap(rect,pathlist.at(i));
  }


}


/**
 * @brief drawpulldonwwindow::drawLightShoutcutAndProgressBar
 * @param painter
 * @param path
 * @param light_volume
 */
void drawpulldonwwindow::drawLightShoutcutAndProgressBar(QPainter *painter, QString path, int light_volume)
{
   rect.setX(draw_pull_donw5[0]);
   rect.setY(draw_pull_donw5[1]);
   rect.setWidth(draw_pull_donw5[2]);
   rect.setHeight(draw_pull_donw5[3]);
   painter->drawPixmap(rect,path);


   line.setLine(draw_pull_donw5[4],draw_pull_donw5[5],draw_pull_donw5[6],draw_pull_donw5[7]);
   painter->drawLine(line);
//520-120=400.each step value is 4
int x = draw_pull_donw5[8]+light_volume*3;
rect.setX(x);
rect.setY(draw_pull_donw5[9]);
rect.setWidth(draw_pull_donw5[10]);
rect.setHeight(draw_pull_donw5[11]);
painter->drawPixmap(rect,ellipsepath);



}
