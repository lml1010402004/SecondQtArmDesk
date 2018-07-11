#ifndef MAINPAGES_H
#define MAINPAGES_H

#include <QMainWindow>
#include<applications.h>
#include<QPaintEvent>
#include<QMouseEvent>
#include<QPainter>
#include<QRect>
#include<QFont>
#include<statusbar.h>
#include<statusbar_global.h>
#include<drawViewfunctions/drawmainpageview.h>
#include<dataItem/bookinfoitem.h>
#include<modulePages/bookshelf.h>
#include<QList>
#include<dataItem/bookinfoitem.h>
#include<QDebug>
#include<modulePages/bookshelf.h>
#include<modulePages/pulldownwindow.h>
#include<modulePages/bookonline.h>
#include<modulePages/settings.h>
#include<modulePages/gamemodule.h>


#include<modulePages/settinglight.h>
#include<modulePages/settingscreen.h>
#include<modulePages/settingnetwork.h>
#include<modulePages/settingusbtransfer.h>
#include<modulePages/settingdateandtime.h>
#include<modulePages/settinglanguage.h>
#include<modulePages/settingrestore.h>
#include<modulePages/settingabouttablet.h>
#include"utils/hidepulldown.h"
#include"database/database.h"
#include"utils/commonutils.h"
#include"utils/mysetting.h"
#include<QProcess>
#include"syssettings.h"
#include"searchresultofbook.h"
#include<QKeyEvent>
#include<QDateTime>



class HidePullDown;
class MainPages : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainPages(QWidget *parent = 0);
    ~MainPages();
    StatusBar *statusbar;
    void keyPressEvent(QKeyEvent *event);


private:


    int index_book_of_three;

    QProcess *mprocess;

   commonUtils *commonutils;
   int currentPageOfMainPage ;
   int totalPagesOfBooks;
   mySetting *mysettings_m;
   SysSettings *mysyssetting;

    QRect rect;

    QFont font;


    QPainter *painter;

    drawMainPageView *mainpage;

    QList<localDirectoryItem>  *currentPagebooklist;
    QList<localDirectoryItem> *totaltemp;
    BookInfoItem *bookitem;

    QList<QString> pathlist;

    BookShelf *shelf;
    BookOnLine *bookonline;
    GameModule *gamemodule;

     Settings *mySettings;
     SettingLight *mysettinglight;
     settingScreen *mysettingscreen;
     settingNetWork *mysettingnetwork;
     settingUSBTransfer *mysettingusbtransfer;
     settingDateAndTime *mysettingdateandtime;
     settingLanguage *mysettinglanguage;
     settingRestore *mysettingrestore;
     SettingAboutTablet *mysettingabouttablet;
     searchResultofBook *searchresultforbook;


     HidePullDown *myhidepulldown;



    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);

    void init();
    void initConnections();
    void closeOthereQMainWindow();

    BookInfoItem getlatestBookInfo();

    void getBookDataFromDataBase();

    int getTheBatteryPercentage();





signals:
    void showBookshelfSignal();
    void showPulldownWindowSignal();
    void showBookCitySignal();
    void showGameModuleSignal();

public slots:
    void showBookshelfSlot();
    void showPulldownWindowSlot();
    void showBookCitySlot();
    void showGameModuleSlot();

    void showSettingModuleSlot();

    void initSignalAndSlotBetweenForPullWindow();

    void showSettingLightPageSlot();
    void showSettingScreenPageSlot();
    void showSettingNetWorkSlot();
    void showSettingUSBtransferSlot();
    void showSettingDateSlot();
    void showSettingLanguageSlot();
    void showSettingRestoreSlot();
    void showSettingAboutTabletSlot();
    void showSearchResultBookSlot();

    void updateBookInfoOnUiSlot();

    void updateTimeAndBatteryValue(QString time,int battery);

    void processFinisheds();

};

#endif // MAINPAGES_H
