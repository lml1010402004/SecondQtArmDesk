#include "drawswitchlanguagedailog.h"

drawSwitchLanguageDailog::drawSwitchLanguageDailog()
{

}


int draw_set_lan[9] = {150,5,70,150,70,1,1,299,399};
void drawSwitchLanguageDailog::drawLanguageContent(QPainter *painter,QList<QString> *list)
{
    int size = list->size();
    for(int i =0;i<size;i++){
         rect.setX(draw_set_lan[0]);
         rect.setY(draw_set_lan[1]+draw_set_lan[2]*i);
         rect.setWidth(draw_set_lan[3]);
         rect.setHeight(draw_set_lan[4]);
         painter->drawText(rect,list->at(i));
    }


}

void drawSwitchLanguageDailog::drawRect(QPainter *painter)
{
    rect.setX(draw_set_lan[5]);
    rect.setY(draw_set_lan[6]);
    rect.setWidth(draw_set_lan[7]);
    rect.setHeight(draw_set_lan[8]);
    painter->drawRect(rect);

}
