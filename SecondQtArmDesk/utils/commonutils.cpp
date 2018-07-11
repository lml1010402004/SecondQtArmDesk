#include "commonutils.h"
#include <sys/statfs.h>
#include<sys/socket.h>
#include <net/if.h>       /* for ifconf */
#include <linux/sockios.h>    /* for net status mask */
#include <netinet/in.h>       /* for sockaddr_in */
#include <sys/types.h>
#include <sys/ioctl.h>
#include <stdio.h>



const QString FBReader_PATH = "/usr/local/FBReader/FBReader";
const QString FBReader_WORK_DIRECTORY = "/usr/local/FBReader";

const QString Loading_path = ":/mypic/pics/loading.png";

commonUtils::commonUtils()
{


}

int commonUtils::getStorageOfDevice()
{

   int storage_total_size=0;
    struct statfs diskInfo;
    statfs("/dev/block/by-name/UDISK", &diskInfo);
    unsigned long long blocksize = diskInfo.f_bsize; //每个block里包含的字节数
    storage_total_size =diskInfo.f_bavail * blocksize/1024;
 return storage_total_size;
}

QString  commonUtils::GetLocalMac()
  {
      int sock_mac;

      struct ifreq ifr_mac;
      char mac_addr[30];

     sock_mac = socket( AF_INET, SOCK_STREAM, 0 );
      if( sock_mac == -1)
    {

         return "";
    }

     memset(&ifr_mac,0,sizeof(ifr_mac));
     strncpy(ifr_mac.ifr_name, "wlan0", sizeof(ifr_mac.ifr_name)-1);

     if( (ioctl( sock_mac, SIOCGIFHWADDR, &ifr_mac)) < 0)
    {
        return "";
     }

     sprintf(mac_addr,"%02x%02x%02x%02x%02x%02x",
             (unsigned char)ifr_mac.ifr_hwaddr.sa_data[0],
             (unsigned char)ifr_mac.ifr_hwaddr.sa_data[1],
             (unsigned char)ifr_mac.ifr_hwaddr.sa_data[2],
             (unsigned char)ifr_mac.ifr_hwaddr.sa_data[3],
             (unsigned char)ifr_mac.ifr_hwaddr.sa_data[4],
             (unsigned char)ifr_mac.ifr_hwaddr.sa_data[5]);

     close(sock_mac );
     return QString( mac_addr);
}


/**
 * @brief commonUtils::getCurrentPageBooks
 * @param list
 * @return
 */
QList<localDirectoryItem>* commonUtils::getCurrentPageBooks(QList<localDirectoryItem> *list,int currentPage,int pagesize)
{
    QList<localDirectoryItem> *templist = new QList<localDirectoryItem>;
    int totalpages =0;
    if(list->size()%pagesize==0){
        totalpages = list->size()/pagesize;
    }else{
        totalpages = list->size()/pagesize+1;
    }

    if(totalpages==0){

    }else if(totalpages==1&&currentPage==1){

        for(int i=0;i<list->size();i++){
            templist->append(list->at(i));
        }

    }else if(totalpages>1&&currentPage==1){
          for(int i=0;i<pagesize;i++){
              templist->append(list->at(i));
          }

    }else if(totalpages>1&&currentPage<totalpages){
             for(int i=0;i<pagesize;i++){
                 templist->append(list->at((currentPage-1)*pagesize+i));
             }

    }else if(totalpages>1&&currentPage==totalpages){
        int temp = list->size()%pagesize;
        for(int i=0;i<temp;i++){
        templist->append(list->at((totalpages-1)*pagesize+i));
        }
    }
    return templist;
}


/**
 * @brief commonUtils::openBookFromFBreader
 * @param bookpath
 */
void commonUtils::openBookFromFBreader(QProcess *mprocess,QString bookpath)
{
    arguments.clear();
    arguments<<QStringList(bookpath);//actually ,here ,books_cover_path == books_path;
    mprocess->setEnvironment(mprocess->environment());
    mprocess->setWorkingDirectory(FBReader_WORK_DIRECTORY);
    mprocess->start(FBReader_PATH,arguments);

}


/**
 * @brief commonUtils::drawProgressBarOpeningBook
 * @param painter
 */
void commonUtils::drawProgressBarOpeningBook(QPainter *painter)
{
  QRect rect;
  rect.setX(270);
  rect.setY(360);
  rect.setWidth(60);
  rect.setHeight(60);
  painter->drawPixmap(rect,Loading_path);

}



