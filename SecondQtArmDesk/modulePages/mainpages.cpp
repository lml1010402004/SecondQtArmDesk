#include "mainpages.h"
#include<QApplication>


QString path0 = ":/mypic/pics/bg2.png";
QString path1 = ":/mypic/pics/bg2.png";
QString path2 = ":/mypic/pics/bg3.png";
const QString SleepApp = "/usr/local/app/SleepScreen";

QList<QMainWindow*> *mainwindowlist;
pullDownWindow *pulldonwwindow;

bool flag_inside_setting;

extern SysSettings *mysyssetting;


QString systemtime;
int systembatteryvalue;

MainPages::MainPages(QWidget *parent) : QMainWindow(parent)
{
    mainwindowlist = new QList<QMainWindow*>;
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setFixedHeight(GLOBAL_SCREEN_FIXED_HEIGHT);
    this->setFixedWidth(GLOBAL_SCREEN_FIXED_WIDTH);
    //初始化
    init();

}

/**
 * Note: deconstructor function,destroy the no-used objects.
 * @brief MainPages::~MainPages
 */
MainPages::~MainPages()
{
    delete bookitem,shelf,bookonline,gamemodule,
            pulldonwwindow,mainwindowlist,statusbar,
            mainpage,rect,font,mysettinglight,mysettingnetwork,
            mysettingusbtransfer,mysettingdateandtime,mysettinglanguage,
            mysettingrestore,mysettingabouttablet;

    bookitem = NULL;
    shelf = NULL;
    bookonline = NULL;
    gamemodule = NULL;
    pulldonwwindow = NULL;
    mainwindowlist = NULL;
    statusbar = NULL;
    mainpage = NULL;
    mysettinglight = NULL;
    mysettingnetwork = NULL;
    mysettingusbtransfer = NULL;
    mysettingdateandtime = NULL;
    mysettinglanguage = NULL;
    mysettingrestore = NULL;
    mysettingabouttablet = NULL;
}

void MainPages::keyPressEvent(QKeyEvent *event)
{
    int key_value = event->key();
    switch (key_value) {
    case Qt::Key_PowerDown:
        mysyssetting->setConnectWifiMac("");
        system("/usr/wifi/disablewifi");
        mprocess->setEnvironment(mprocess->environment());
        mprocess->setWorkingDirectory("/usr/local/app/");
        mprocess->start(SleepApp);


        break;
    case Qt::Key_Right:
        break;
    case Qt::Key_Left:
        break;
    default:
        break;
    }

}

void MainPages::mouseMoveEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();

    if(y>450&&y<600){
        if(x-position_old_x>25){
            move_event = true;
            qDebug()<<"from left to right===";
            if(currentPageOfMainPage>1){
                currentPageOfMainPage--;
                currentPagebooklist = commonutils->getCurrentPageBooks(totaltemp,currentPageOfMainPage,3);
                this->repaint();
            }

        }else if(position_old_x-x>25){
            move_event = true;
            qDebug()<<"from right to left===";
            if(currentPageOfMainPage<totalPagesOfBooks-1){
                currentPageOfMainPage++;
                currentPagebooklist = commonutils->getCurrentPageBooks(totaltemp,currentPageOfMainPage,3);
                this->repaint();
            }
        }
    }

}

void MainPages::mouseReleaseEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();

        if(FIRSTBOOK&&!move_event){
            if(currentPagebooklist->size()>0){
                index_book_of_three =0;
                if(Database::getInstance()->deleteADataFromUntouchedTable(currentPagebooklist->at(0)))
                    Database::getInstance()->insertADataToTouchedTable(currentPagebooklist->at(0));
                this->repaint();
                mysettings_m->setCurrentBookPath(currentPagebooklist->at(0).file_path);
                mysettings_m->setCurrentBookTitle(currentPagebooklist->at(0).file_name);
                commonutils->openBookFromFBreader(mprocess,currentPagebooklist->at(0).file_path);

            }

        }else if(SECONDBOOK&&!move_event){
            if(currentPagebooklist->size()>1){
                index_book_of_three =1;

                if(Database::getInstance()->deleteADataFromUntouchedTable(currentPagebooklist->at(1)))
                    Database::getInstance()->insertADataToTouchedTable(currentPagebooklist->at(1));
                this->repaint();
                mysettings_m->setCurrentBookPath(currentPagebooklist->at(1).file_path);
                mysettings_m->setCurrentBookTitle(currentPagebooklist->at(1).file_name);
                commonutils->openBookFromFBreader(mprocess,currentPagebooklist->at(1).file_path);

            }

        }else if(THIRDBOOK&&!move_event){
            if(currentPagebooklist->size()>2){
                index_book_of_three =2;
                if( Database::getInstance()->deleteADataFromUntouchedTable(currentPagebooklist->at(2)))
                    Database::getInstance()->insertADataToTouchedTable(currentPagebooklist->at(2));
                this->repaint();
                mysettings_m->setCurrentBookPath(currentPagebooklist->at(2).file_path);
                mysettings_m->setCurrentBookTitle(currentPagebooklist->at(2).file_name);
                commonutils->openBookFromFBreader(mprocess,currentPagebooklist->at(2).file_path);

            }
        }

        move_event = false;

}

/**
 * @brief commonUtils::getTheBatteryPercentage
 * @return
 */
int MainPages::getTheBatteryPercentage()
{
    int fd = -1;
    fd= open("/sys/class/power_supply/battery/voltage_now",O_RDONLY);
    char rbuf[8]={'\0'};
    if(fd==-1){
        qDebug()<<"read the voltage fail"<<fd;
        return -1;
    }
    read(fd,&rbuf,8);
    QString str = QString(rbuf);
    str = str.mid(0,2);
    int temp = str.toInt(0,10);
    ::close(fd);//这个是c标准
    return temp;

}

/**
 * @brief MainPages::init
 */
void MainPages::init()
{

    move_event = false;

    first_time_enter = true;
    systemtime= QDateTime::currentDateTime().toString("MM-dd hh:mm");
    systembatteryvalue= getTheBatteryPercentage();

    mysyssetting = new SysSettings;
    mprocess = new QProcess(this);
    index_book_of_three =-1;

    flag_inside_setting = false;

    totaltemp = new QList<localDirectoryItem>;
    currentPagebooklist = new QList<localDirectoryItem>;

    statusbar = new StatusBar(this);
    mysettings_m = new mySetting;



    pathlist.append(path0);
    pathlist.append(path1);
    pathlist.append(path2);

    mainpage = new drawMainPageView;
    commonutils = new commonUtils;


    shelf  = new BookShelf(this);
    pulldonwwindow = new pullDownWindow(this);
    bookonline = new BookOnLine(this);
    gamemodule = new GameModule(this);



    mySettings = new Settings(this);
    mysettinglight = new SettingLight(this);
    mysettingscreen = new settingScreen(this);
    mysettingnetwork = new settingNetWork(this);
    mysettingusbtransfer = new settingUSBTransfer(this);
    mysettingdateandtime = new settingDateAndTime(this);
    mysettinglanguage = new settingLanguage(this);
    mysettingrestore = new settingRestore(this);
    mysettingabouttablet = new SettingAboutTablet(this);
    searchresultforbook = new searchResultofBook(this);


    myhidepulldown = new HidePullDown(this);
    currentPageOfMainPage =0;
    totalPagesOfBooks =0;


    initConnections();

    getBookDataFromDataBase();

    mysyssetting->setConnectWifiMac("");




}

void MainPages::initConnections()
{

    QObject::connect(this,SIGNAL(showBookshelfSignal()),this,SLOT(showBookshelfSlot()));
    QObject::connect(this,SIGNAL(showPulldownWindowSignal()),this,SLOT(showPulldownWindowSlot()));
    QObject::connect(this,SIGNAL(showBookCitySignal()),this,SLOT(showBookCitySlot()));
    QObject::connect(this,SIGNAL(showGameModuleSignal()),this,SLOT(showGameModuleSlot()));
    QObject::connect(pulldonwwindow,SIGNAL(showSettingModuleSignal()),this,SLOT(showSettingModuleSlot()));
    QObject::connect(mySettings,SIGNAL(backToMainPageSignal_Signal()),this,SLOT(initSignalAndSlotBetweenForPullWindow()));
    QObject::connect(mySettings,SIGNAL(showPullDownWindowSignal_setting()),this,SLOT(showPulldownWindowSlot()));
    QObject::connect(mySettings,SIGNAL(showLightPageSignal()),this,SLOT(showSettingLightPageSlot()));
    QObject::connect(searchresultforbook,SIGNAL(showPullDownSignal()),SLOT(showPulldownWindowSlot()));

    QObject::connect(mySettings,SIGNAL(showSettingScreenSignal()),this,SLOT(showSettingScreenPageSlot()));
    QObject::connect(mySettings,SIGNAL(showSettingNetWorkSignal()),this,SLOT(showSettingNetWorkSlot()));
    QObject::connect(mySettings,SIGNAL(showSettingUSBtransferSignal()),this,SLOT(showSettingUSBtransferSlot()));
    QObject::connect(mySettings,SIGNAL(showSettingDateSignal()),this,SLOT(showSettingDateSlot()));
    QObject::connect(mySettings,SIGNAL(showSettingLanguageSignal()),this,SLOT(showSettingLanguageSlot()));
    QObject::connect(mySettings,SIGNAL(showSettingRestoreSignal()),this,SLOT(showSettingRestoreSlot()));
    QObject::connect(mySettings,SIGNAL(showSettingAboutTabletSignal()),this,SLOT(showSettingAboutTabletSlot()));

    QObject::connect(mysettinglight,SIGNAL(showPullDownSignal()),this,SLOT(showPulldownWindowSlot()));
    QObject::connect(mysettingscreen,SIGNAL(showPullDownSignal()),this,SLOT(showPulldownWindowSlot()));
    QObject::connect(mysettingnetwork,SIGNAL(showPullDownSignal()),this,SLOT(showPulldownWindowSlot()));
    QObject::connect(mysettingusbtransfer,SIGNAL(showPullDownSignal()),this,SLOT(showPulldownWindowSlot()));
    QObject::connect(mysettingdateandtime,SIGNAL(showPullDownSignal()),this,SLOT(showPulldownWindowSlot()));
    QObject::connect(mysettinglanguage,SIGNAL(showPullDownSignal()),this,SLOT(showPulldownWindowSlot()));
    QObject::connect(mysettingrestore,SIGNAL(showPullDownSignal()),this,SLOT(showPulldownWindowSlot()));
    QObject::connect(mysettingabouttablet,SIGNAL(showPullDownSignal()),this,SLOT(showPulldownWindowSlot()));

    QObject::connect(shelf,SIGNAL(showPullWindowSignal()),this,SLOT(showPulldownWindowSlot()));
    QObject::connect(bookonline,SIGNAL(showPulldownWindowSignal()),this,SLOT(showPulldownWindowSlot()));
    QObject::connect(gamemodule,SIGNAL(showPulldownWindowSignal()),this,SLOT(showPulldownWindowSlot()));

    QObject::connect(mysettingusbtransfer,SIGNAL(updateTheBookDataSignal()),this,SLOT(updateBookInfoOnUiSlot()));


    QObject::connect(mprocess,SIGNAL(finished(int ,QProcess::ExitStatus)),this,SLOT(processFinisheds()));

    QObject::connect(statusbar,SIGNAL(broadcastTimeAndBattery(QString,int)),this,SLOT(updateTimeAndBatteryValue(QString ,int)));
    QObject::connect(pulldonwwindow,SIGNAL(showSearchResultBookSignal()),this,SLOT(showSearchResultBookSlot()));
    QObject::connect(pulldonwwindow,SIGNAL(showWifiModuleSignal()),this,SLOT(showSettingNetWorkSlot()));

}

void MainPages::closeOthereQMainWindow()
{

    if(mysettinglight!=NULL){

        mysettinglight->close();
    }
    if(mysettingscreen!=NULL){

        mysettingscreen->close();
    }
    if(mysettingnetwork!=NULL){

        mysettingnetwork->close();
    }
    if(mysettingusbtransfer!=NULL){

        mysettingusbtransfer->close();
    }
    if(mysettingdateandtime!=NULL){
        mysettingdateandtime->close();
    }
    if(mysettinglanguage!=NULL){
        mysettinglanguage->close();
    }
    if(mysettingrestore!=NULL){
        mysettingrestore->close();
    }
    if(mysettingabouttablet!=NULL){
        mysettingabouttablet->close();
    }

}



/**
 * @brief MainPages::mousePressEvent
 * @param event
 */
void MainPages::mousePressEvent(QMouseEvent *event)
{
    QApplication::setScreenUpdateMode(QApplication::EINK_GL16_MODE);//刷新
    int x = event->x();
    int y = event->y();

    position_old_x = x;
    position_old_y = y;

    if(SHOWBOOKSHELFSIGNAL){
        emit showBookshelfSignal();
    }else if(SHOWPULLDOWNWINDOWSIGNAL){
        emit showPulldownWindowSignal();
    }else if(SHOWBOOKCITY){
        emit showBookCitySignal();
    }else if(SHOWGAMEMODULE){
        emit showGameModuleSignal();
    }else if(CLICKLASTPAGE){
        if(currentPageOfMainPage>1){
            currentPageOfMainPage--;
            currentPagebooklist = commonutils->getCurrentPageBooks(totaltemp,currentPageOfMainPage,3);
            this->repaint();
        }

    }else if(CLICKNEXTPAGE){
        if(currentPageOfMainPage<totalPagesOfBooks-1){
            currentPageOfMainPage++;
            currentPagebooklist = commonutils->getCurrentPageBooks(totaltemp,currentPageOfMainPage,3);

            this->repaint();
        }
    }else if(CURRENTBOOKAREA){
        index_book_of_three = 3;
        this->repaint();
        commonutils->openBookFromFBreader(mprocess,mysettings_m->getCurrentBookPath());
    }
}


/**
 * @brief MainPages::paintEvent
 * @param event
 */
void MainPages::paintEvent(QPaintEvent *event)
{
    if(first_time_enter){
        QApplication::setScreenUpdateMode(QApplication::EINK_GC16_MODE);//刷新
        first_time_enter = false;
    }
    painter = new QPainter(this);

    rect.setRect(0,0,GLOBAL_SCREEN_FIXED_WIDTH,GLOBAL_SCREEN_FIXED_HEIGHT);
    painter->fillRect(rect,QBrush(Qt::white));

    this->setAutoFillBackground(true);//必须有这条语句
    this->setPalette(QPalette(QColor(255,255,255)));


    statusbar->drawSystemTime(painter,systemtime);
    statusbar->drawPullDownRectangle(painter);
    statusbar->drawBattery(painter,systembatteryvalue);

    if(mysyssetting->getConnectWifiMac().length()>2){
        statusbar->drawWifiStatus(painter,true);
    }

    if(index_book_of_three>-1){
        commonutils->drawProgressBarOpeningBook(painter);
        index_book_of_three =-1;
    }
    //Current reading book.
    mainpage->drawCurrentBookCover(painter,mysettings_m->getCurrentBookPath());
    mainpage->drawCurrentBookTitle(painter,mysettings_m->getCurrentBookTitle());
    mainpage->drawCurrentBookAuthor(painter,mysettings_m->getCurrentBookAuthor());
    mainpage->drawCurrentBookBrefContent(painter,"Stray birds of summer come to my window without a song ,and flutter and fall");
    mainpage->drawCurrentBookProgress(painter,30);



    mainpage->drawTextView(painter);
    mainpage->drawLastPage(painter,1);
    mainpage->drawNextPage(painter,1);

    mainpage->drawThreeBooksOfCurrentPage(painter,currentPagebooklist);

    mainpage->drawThreeModulesonBottom(painter,1);


}


/**
 * @brief MainPages::getlatestBookInfo
 * @return
 */
BookInfoItem MainPages::getlatestBookInfo()
{
    //从数据库中获取和从固定文件中读取.



}

void MainPages::getBookDataFromDataBase()
{

    Database* tempdatabase = Database::getInstance();
    totaltemp =  tempdatabase->getLastTimeTableFromDatabase();
    int size = totaltemp->size();

    if(size>0){
        if(size%3==0){
            totalPagesOfBooks = size/3;
        }else{
            totalPagesOfBooks = size/3+1;
        }
        currentPageOfMainPage =1;
        currentPagebooklist = commonutils->getCurrentPageBooks(totaltemp,currentPageOfMainPage,3);
    }

}


/**
 * @brief MainPages::showBookshelfSlot
 */
void MainPages::showBookshelfSlot()
{
    if(shelf==NULL){
        shelf  = new BookShelf(this);
    }
    shelf->hide();
    shelf->show();
}


/**
 * @brief MainPages::showPulldownWindowSlot
 */
void MainPages::showPulldownWindowSlot()
{

    if(pulldonwwindow==NULL){
        pulldonwwindow = new pullDownWindow(this);

    }

    pulldonwwindow->hide();
    pulldonwwindow->show();

}


/**
 * @brief MainPages::showBookCitySlot
 */
void MainPages::showBookCitySlot()
{
    if(bookonline==NULL){
        bookonline = new BookOnLine(this);
    }
    bookonline->show();

}

void MainPages::showGameModuleSlot()
{
    if(gamemodule==NULL){
        gamemodule = new GameModule(this);
    }
    gamemodule->show();
}


/**
 * @brief MainPages::showSettingModuleSlot
 */
void MainPages::showSettingModuleSlot()
{
    if(mySettings!=NULL){
        mySettings->show();
    }
    if(!flag_inside_setting){
        closeOthereQMainWindow();
        if(pulldonwwindow!=NULL){
            myhidepulldown->start();
        }
    }else{
        pulldonwwindow->hide();
        closeOthereQMainWindow();
    }

}

void MainPages::initSignalAndSlotBetweenForPullWindow()
{
    //    init();
    initConnections();
}

void MainPages::showSettingLightPageSlot()
{
    if(mysettinglight!=NULL){
        mysettinglight->hide();
        mysettinglight->show();
    }

}


/**
 * @brief MainPages::showSettingScreenPageSlot
 */
void MainPages::showSettingScreenPageSlot()
{

    if(mysettingscreen!=NULL){
        mysettingscreen->hide();
        mysettingscreen->show();
    }
}


/**
 * @brief MainPages::showSettingNetWorkSlot
 */
void MainPages::showSettingNetWorkSlot()
{
    if(mysettingnetwork!=NULL){
        mysettingnetwork->hide();
        mysettingnetwork->show();
    }
}

void MainPages::showSettingUSBtransferSlot()
{

    if(mysettingusbtransfer!=NULL){
        mysettingusbtransfer->hide();
        mysettingusbtransfer->show();
    }

}

void MainPages::showSettingDateSlot()
{
    if(mysettingdateandtime!=NULL){
        mysettingdateandtime->hide();
        mysettingdateandtime->show();
    }
}

void MainPages::showSettingLanguageSlot()
{
    if(mysettinglanguage!=NULL){
        mysettinglanguage->hide();
        mysettinglanguage->show();
    }

}

void MainPages::showSettingRestoreSlot()
{
    if(mysettingrestore!=NULL){
        mysettingrestore->hide();
        mysettingrestore->show();
    }
}

void MainPages::showSettingAboutTabletSlot()
{
    if(mysettingabouttablet!=NULL){
        mysettingabouttablet->hide();
        mysettingabouttablet->show();
    }
}

/**
 * @brief MainPages::showSearchResultBookSlot
 */
void MainPages::showSearchResultBookSlot()
{
    if(searchresultforbook!=NULL){
        searchresultforbook->hide();
        searchresultforbook->show();
    }

}

void MainPages::updateBookInfoOnUiSlot()
{

    getBookDataFromDataBase();
    repaint();

}

void MainPages::updateTimeAndBatteryValue(QString time, int battery)
{
    QApplication::setScreenUpdateMode(QApplication::EINK_GL16_MODE);//刷新
    systemtime = time;
    systembatteryvalue = battery;
    this->repaint();

}

void MainPages::processFinisheds()
{

    QApplication::setScreenUpdateMode(QApplication::EINK_GC16_MODE);//刷新
    this->repaint();
    QApplication::setScreenUpdateMode(QApplication::EINK_GL16_MODE);//刷新
    repaint();

}
