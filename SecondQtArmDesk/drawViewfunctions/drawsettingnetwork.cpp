#include "drawsettingnetwork.h"

extern QString homeiconpath;
extern QString BACKLASTSTEPICON;

extern QString nextpage_path;
extern QString lastpage_path;


QString OPEN_PATH2 =":/mypic/pics/open_wifi.png";
QString CLOSE_PATH1 = ":/mypic/pics/close.png";
QString WIFI1_ICON=":/mypic/pics/wifi1_icon.png";


int draw_set_net[8] = {0,96,600,96,500,50,30,29};
int draw_set_net1[8] = {15,50,15,28,65,45,65,85};

int draw_set_net2[5] = {210,120,180,40,15};
int draw_set_net3[8]= {50,180,80,40,490,180,44,23};

int draw_set_net4[8] = {210,240,180,40,50,290,550,290};


int draw_set_net5[16] = {100,300,80,60,50,170,320,80,200,60,20,430,320,80,100,60};
int draw_set_net6[12] = {120,680,36,36,280,680,40,40,420,680,36,36};

drawSettingNetwork::drawSettingNetwork()
{
    init();

}

drawSettingNetwork::~drawSettingNetwork()
{
delete mysyssetting;
    mysyssetting = NULL;

}



void drawSettingNetwork::drawHomeIcon(QPainter *painter)
{
    line.setLine(draw_set_net[0],draw_set_net[1],draw_set_net[2],draw_set_net[3]);
    painter->drawLine(line);
    rect.setX(draw_set_net[4]);
    rect.setY(draw_set_net[5]);
    rect.setWidth(draw_set_net[6]);
    rect.setHeight(draw_set_net[7]);
    painter->drawPixmap(rect,homeiconpath);


}




/**
 * @brief drawSettingNetwork::drawBackIcon
 * @param painter
 */
void drawSettingNetwork::drawBackIcon(QPainter *painter)
{

    rect.setX(draw_set_net1[0]);
    rect.setY(draw_set_net1[1]);
    rect.setWidth(draw_set_net1[2]);
    rect.setHeight(draw_set_net1[3]);
    painter->drawPixmap(rect,BACKLASTSTEPICON);
    line.setLine(draw_set_net1[4],draw_set_net1[5],draw_set_net1[6],draw_set_net1[7]);
    painter->drawLine(line);

}


/**
 * @brief drawSettingNetwork::drawWifiTitle
 * @param painter
 */
void drawSettingNetwork::drawWifiTitle(QPainter *painter)
{
   rect.setX(draw_set_net2[0]);
   rect.setY(draw_set_net2[1]);
   rect.setWidth(draw_set_net2[2]);
   rect.setHeight(draw_set_net2[3]);
   font.setPointSize(draw_set_net2[4]);
   painter->setFont(font);
   painter->drawText(rect,QString("WifiSetting"));

}



/**
 * @brief drawSettingNetwork::drawWifiSwitch
 * @param painter
 */
void drawSettingNetwork::drawWifiSwitch(QPainter *painter,bool flag)
{
    rect.setX(draw_set_net3[0]);
    rect.setY(draw_set_net3[1]);
    rect.setWidth(draw_set_net3[2]);
    rect.setHeight(draw_set_net3[3]);
    painter->drawText(rect,QString("WIFI"));


    rect.setX(draw_set_net3[4]);
    rect.setY(draw_set_net3[5]);
    rect.setWidth(draw_set_net3[6]);
    rect.setHeight(draw_set_net3[7]);
    if(flag){
        painter->drawPixmap(rect,OPEN_PATH2);
    }else{
        painter->drawPixmap(rect,CLOSE_PATH1);
    }

}


/**
 * @brief drawSettingNetwork::drawWifiSerachText
 * @param painter
 */
void drawSettingNetwork::drawWifiSerachText(QPainter *painter)
{
  rect.setX(draw_set_net4[0]);
  rect.setY(draw_set_net4[1]);
  rect.setWidth(draw_set_net4[2]);
  rect.setHeight(draw_set_net4[3]);
  painter->drawText(rect,QString("SearchResult"));

  line.setLine(draw_set_net4[4],draw_set_net4[5],draw_set_net4[6],draw_set_net4[7]);
  painter->drawLine(line);


}


/**
 * @brief drawSettingNetwork::drawCurrentWifiItems
 * @param painter
 * @param currentPage
 */
void drawSettingNetwork::drawCurrentWifiItems(QPainter *painter,QList<wifiItem*> *wifilistitem,int currentPage,int totalPages)
{
  if(wifilistitem->size()<1){
        return;
   }
  int size = wifilistitem->size();

    QList<wifiItem*> templist;

    templist= getCurrentPageWifiList(wifilistitem,currentPage,totalPages);

  for(int i=0;i<templist.size();i++){
     rect.setX(draw_set_net5[0]);
     rect.setY(draw_set_net5[1]+draw_set_net5[2]*i);
     rect.setWidth(draw_set_net5[3]);
     rect.setHeight(draw_set_net5[4]);
     painter->drawPixmap(rect,WIFI1_ICON);
     rect.setX(draw_set_net5[5]);
     rect.setY(draw_set_net5[6]+draw_set_net5[7]*i);
     rect.setWidth(draw_set_net5[8]);
     rect.setHeight(draw_set_net5[9]);
     font.setPixelSize(draw_set_net5[10]);
     painter->setFont(font);
     painter->drawText(rect,templist.at(i)->wifi_name);

     rect.setX(draw_set_net5[11]);
     rect.setY(draw_set_net5[12]+draw_set_net5[13]*i);
     rect.setWidth(draw_set_net5[14]);
     rect.setHeight(draw_set_net5[15]);
     if(wifilistitem->at(i)->WIFI_MAC==mysyssetting->getConnectWifiMac()){
     painter->drawText(rect,QString("Connected"));
     }else{
     painter->drawText(rect,QString("Join"));
     }
  }

  drawLastAndNextPage(painter,currentPage,totalPages);

}




/**
 * @brief drawSettingNetwork::drawLastAndNextPage
 * @param painter
 */
void drawSettingNetwork::drawLastAndNextPage(QPainter *painter,int currentPage,int totalPages)
{

    rect.setX(draw_set_net6[0]);
    rect.setY(draw_set_net6[1]);
    rect.setWidth(draw_set_net6[2]);
    rect.setHeight(draw_set_net6[3]);
    painter->drawPixmap(rect,lastpage_path);

    rect.setX(draw_set_net6[4]);
    rect.setY(draw_set_net6[5]);
    rect.setWidth(draw_set_net6[6]);
    rect.setHeight(draw_set_net6[7]);
    painter->drawText(rect,QString::number(currentPage)+QString("/")+QString::number(totalPages));

    rect.setX(draw_set_net6[8]);
    rect.setY(draw_set_net6[9]);
    rect.setWidth(draw_set_net6[10]);
    rect.setHeight(draw_set_net6[11]);
    painter->drawPixmap(rect,nextpage_path);

}


/**
 * @brief drawSettingNetwork::init
 */
void drawSettingNetwork::init()
{

    mysyssetting = new SysSettings;


}



QList<wifiItem*> drawSettingNetwork::getCurrentPageWifiList(QList<wifiItem*> *list, int currentPage,int totalPages)
{
      QList<wifiItem*> templist ;


        if(currentPage<totalPages){//The data of middle page
         int index =  (currentPage-1)*4;
         for(int i=0;i<4;i++){
              templist.append(list->at(index+i));
         }
        }else if(currentPage==1&&currentPage==totalPages){ //the data of last page
            int tempsize = list->size();
            for(int i=0;i<tempsize;i++){
                templist.append(list->at(i));
            }
        }else if(currentPage>1&&currentPage==totalPages){
                 int tempindex = (totalPages-1)*4;
                 int size = list->size()%4;
                 for(int i=0;i<size;i++){
                  templist.append(list->at(tempindex+i));
                 }
        }
        return templist;
}



