#include "drawsettingsmodules.h"
#include"dataItem/systemitems.h"

//xywh means x position,y position,width ,height.
int items_xywh[8][4] = {
                    {50,170,500,70},
                    {50,240,500,70},
                    {50,310,500,70},
                    {50,380,500,70},
                    {50,450,500,70},
                    {50,520,500,70},
                    {50,590,500,70},
                    {50,660,500,70}
                     };

int item_text_xywh[8][4] = {
                    {70,200,200,40},
                    {70,270,200,40},
                    {70,340,200,40},
                    {70,410,200,40},
                    {70,480,200,40},
                    {70,550,200,40},
                    {70,620,200,40},
                    {70,690,200,40}
};


int item_icon_xywh[8][4] = {
                     {480,180,50,50},
                     {480,250,50,50},
                     {480,320,50,50},
                     {480,390,50,50},
                     {480,460,50,50},
                     {480,530,50,50},
                     {480,600,50,50},
                     {480,670,50,50}
};

QString item_icon_paths[] = {
               ":/mypic/pics/light_icon.png",
               ":/mypic/pics/screen_icon.png",
               ":/mypic/pics/network_icon.png",
               ":/mypic/pics/USB_icon.png",
               ":/mypic/pics/Date_time_icon.png",
               ":/mypic/pics/language_keyboard_icon.png",
               ":/mypic/pics/Restore_icon.png",
               ":/mypic/pics/About_tablet_icon.png"
};

QList<SystemItems*> *systemitemlist;
SystemItems *item;




drawSettingsModules::drawSettingsModules()
{
   systemitemlist = new QList<SystemItems*>;


   for(int i=0;i<8;i++){
         item = new SystemItems;
         item->setItem_x(items_xywh[i][0]);
         item->setItem_y(items_xywh[i][1]);
         item->setItem_width(items_xywh[i][2]);
         item->setItem_height(items_xywh[i][3]);

         item->setItem_text_x(item_text_xywh[i][0]);
         item->setItem_text_y(item_text_xywh[i][1]);
         item->setItem_text_width(item_text_xywh[i][2]);
         item->setItem_text_height(item_text_xywh[i][3]);

//         item->setItem_text_text(item_text_text[i]);

         item->setItem_icon_x(item_icon_xywh[i][0]);
         item->setItem_icon_y(item_icon_xywh[i][1]);
         item->setItem_icon_width(item_icon_xywh[i][2]);
         item->setItem_icon_height(item_icon_xywh[i][3]);
         item->setItem_icon_path(item_icon_paths[i]);
         systemitemlist->append(item);

   }

}

drawSettingsModules::~drawSettingsModules()
{
  delete systemitemlist,item,line,rect;
    systemitemlist = NULL;
    item = NULL;

}
/**
 * @brief drawSettingsModules::drawHomeIconOnSettingPage
 * @param painter
 * @param iconpath
 */
void drawSettingsModules::drawHomeIconOnSettingPage(QPainter *painter, QString iconpath)
{
    line.setLine(0,96,600,96);
    painter->drawLine(line);
    rect.setX(500);
    rect.setY(50);
    rect.setWidth(30);
    rect.setHeight(29);
    painter->drawPixmap(rect,iconpath);

}


/**
 * @brief drawSettingsModules::drawSystemSettingText
 * @param painter
 * @param text
 */
void drawSettingsModules::drawSystemSettingText(QPainter *painter, QString text)
{
  rect.setX(175);
  rect.setY(120);
  rect.setWidth(250);
  rect.setHeight(60);
  font.setPixelSize(30);
  painter->setFont(font);
  painter->drawText(rect,text);

}

QString item_text_text[8] ={QObject::tr("Light"),QObject::tr("Screen"),
                   QObject::tr("NetWork"),QObject::tr("USB_transfer"),
                   QObject::tr("DateAndTime"),QObject::tr("Language"),
                   QObject::tr("Restore"),QObject::tr("About_tablet")};
/**
 * @brief drawSettingsModules::drawSettingsItems
 * @param painter
 * @param pathlist
 */
void drawSettingsModules::drawSettingsItems(QPainter *painter)
{
    font.setPixelSize(20);
    painter->setFont(font);
    for(int i=0;i<8;i++){
      rect.setX(systemitemlist->at(i)->getItem_x());
      rect.setY(systemitemlist->at(i)->getItem_y());
      rect.setWidth(systemitemlist->at(i)->getItem_width());
      rect.setHeight(systemitemlist->at(i)->getItem_height());
      painter->drawRect(rect);
      rect.setX(systemitemlist->at(i)->getItem_text_x());
      rect.setY(systemitemlist->at(i)->getItem_text_y());
      rect.setWidth(systemitemlist->at(i)->getItem_text_width());
      rect.setHeight(systemitemlist->at(i)->getItem_text_height());


      switch (i) {
      case 0:
           painter->drawText(rect,QObject::tr("Light"));
          break;
      case 1:
           painter->drawText(rect,QObject::tr("Screen"));
          break;
      case 2:
           painter->drawText(rect,QObject::tr("NetWork"));
          break;
      case 3:
           painter->drawText(rect,QObject::tr("USB_transfer"));
          break;
      case 4:
           painter->drawText(rect,QObject::tr("DateAndTime"));
          break;
      case 5:
           painter->drawText(rect,QObject::tr("Language"));
          break;
      case 6:
           painter->drawText(rect,QObject::tr("Restore"));
          break;
      case 7:
           painter->drawText(rect,QObject::tr("About_tablet"));
          break;
      default:
          break;
      }

      rect.setX(systemitemlist->at(i)->getItem_icon_x());
      rect.setY(systemitemlist->at(i)->getItem_icon_y());
      rect.setWidth(systemitemlist->at(i)->getItem_icon_width());
      rect.setHeight(systemitemlist->at(i)->getItem_item_height());
      painter->drawPixmap(rect,systemitemlist->at(i)->getItem_icon_path());
    }

}




