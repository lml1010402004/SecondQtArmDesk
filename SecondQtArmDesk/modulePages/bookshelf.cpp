#include "bookshelf.h"
#include<QDebug>

#include<QApplication>
#include"applications.h"

QString emptypath = ":/mypic/pics/circlempty";

extern QList<QMainWindow*> *mainwindowlist;
extern QString systemtime;
extern int systembatteryvalue;

BookShelf::BookShelf(QWidget *parent) : QMainWindow(parent)
{
    mainwindowlist->append(this);
    //   QApplication::setScreenUpdateMode(QApplication::EINK_GL16_MODE);//局部刷新

    this->setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    this->setFixedHeight(GLOBAL_SCREEN_FIXED_HEIGHT);
    this->setFixedWidth(GLOBAL_SCREEN_FIXED_WIDTH);
    //初始化
    init();

}


/**
 * @brief BookShelf::~BookShelf
 */
BookShelf::~BookShelf()
{
    delete conditonsItemlist,conditionitem,bookinforitem,
            painter,rect,statusbar,drawbookshelf,totalbookinfolist,mprocess,commonutils;
    conditonsItemlist = NULL;
    painter = NULL;
    statusbar = NULL;
    drawbookshelf = NULL;
    totalbookinfolist = NULL;
    mprocess = NULL;
    commonutils = NULL;
}


/**
 * @brief BookShelf::paintEvent
 * @param event
 */
void BookShelf::paintEvent(QPaintEvent *event)
{
    painter = new QPainter(this);

    rect.setRect(0,0,GLOBAL_SCREEN_FIXED_WIDTH,GLOBAL_SCREEN_FIXED_HEIGHT);
    painter->fillRect(rect,QBrush(Qt::white));
    this->setAutoFillBackground(true);//必须有这条语句
    this->setPalette(QPalette(QColor(255,255,255)));

    statusbar->drawSystemTime(painter,systemtime);
    statusbar->drawPullDownRectangle(painter);
    statusbar->drawBattery(painter,systembatteryvalue);


    drawbookshelf->drawHomeButton(painter,true);
    drawbookshelf->drawArrangeTextView(painter,QObject::tr("sort"));
    drawbookshelf->drawSelectCondition(painter,conditonsItemlist,index_select);

    drawbookshelf->drawNineBooks(painter,currentpagebookinfolist);
    drawbookshelf->drawTheFirstAndLastPageIcon(painter);
    drawbookshelf->drawTheNextAndEndPageIcon(painter);
    drawbookshelf->drawCurrentPageAndTotalPages(painter,current_page,total_pages);

    if(mysyssetting->getConnectWifiMac().length()>0){
        statusbar->drawWifiStatus(painter,true);
    }
    if(show_progress_bar>-1){
        commonutils->drawProgressBarOpeningBook(painter);
        show_progress_bar = -1;
    }
}


/**
 * @brief BookShelf::mousePressEvent
 * @param event
 */
void BookShelf::mousePressEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();

    position_old_x = x;

    if(SELECTCONDITIONINDEX0){
        index_select =0;
        current_page = 1;
    }else if(SELECTCONDITIONINDEX1){
        index_select =1;
        current_page = 1;
    }else if(SELECTCONDITIONINDEX2){
        index_select =2;
        current_page = 1;
    }else if(SELECTCONDITIONINDEX3){
        index_select = 3;
        current_page = 1;
    }else if(FIRSTPAGEPOSITION){
        current_page =1;
    }else if(LASTPAGEPOSITION){
        if(current_page>1){
            current_page--;
        }
    }else if(NEXTPAGEPOSITION){
        if(current_page<total_pages){
            current_page++;
        }
    }else if(ENDPAGEPOSITION){
        current_page = total_pages;
    }



}


/**
 * @brief BookShelf::mouseReleaseEvent
 * @param event
 */
void BookShelf::mouseReleaseEvent(QMouseEvent *event)
{

        int x = event->x();
        int y = event->y();
        if(BACKTOMAINPAGE){
            emit backHomePagesignal();
        }else if(x>250&&x<350&&y<30){
            emit showPullWindowSignal();
        }

        emit updateDataSignal();


    int index = getTheTargetBookIndex(x,y);
    if(index>-1&&index<9){
        if(!move_event){
            emit openBookSignal(index);
        }else{
            emit updateDataSignal();
        }
    }
    move_event = false;

}


/**
 * @brief BookShelf::mouseMoveEvent
 * @param event
 */
void BookShelf::mouseMoveEvent(QMouseEvent *event)
{

    int x = event->x();
    int y = event->y();

    if(x-position_old_x>25){

        if(current_page>1){
             move_event = true;
            current_page--;
        }


    }else if(position_old_x-x>25){

        if(current_page<total_pages){
             move_event = true;
            current_page++;
        }

    }
}

/**
   这个函数是计算点击的书本位置.
 * @brief BookShelf::getTheTargetBookIndex
 * @param x
 * @param y
 * @return
 */
int BookShelf::getTheTargetBookIndex(int x, int y)
{
    int temp = -1;
    if(BOOKSHELFBOOKAREA){
        //这是要点击书本
        if((x-66)/180==0){
            temp  = ((y-165)/180)*3;
        }else if((x-66)/180==1){
            temp = ((y-165)/180)*3+1;
        }else if((x-66)/180==2){
            temp = ((y-165)/180)*3+2;
        }
    }
    return temp ;
}


/**
 * @brief BookShelf::init
 */
void BookShelf::init()
{
    move_event = false;

    mysyssetting = new SysSettings;
    show_progress_bar = -1;
    index_select = 0;
    mprocess = new QProcess(this);

    statusbar = new StatusBar(this);
    drawbookshelf = new drawBookshelfPageView;
    conditonsItemlist = new QList<ConditionItem>;
    currentpagebookinfolist = new QList<localDirectoryItem>;
    totalbookinfolist = new QList<localDirectoryItem>;
    commonutils = new commonUtils;


    //=============init data===============
    list.clear();
    list.append(QString("Read"));
    list.append(QString("Name"));
    list.append(QString("Time"));
    list.append(QString("Author"));
    for(int i=0;i<list.size();i++){
        conditionitem.setCircle_icon_path(emptypath);
        conditionitem.setText_str(list.at(i));
        conditonsItemlist->append(conditionitem);
    }
    //======================================

    totalbookinfolist = Database::getInstance()->getAllDataFromTouchedTable();

    total_pages = getTotalPagesForEachCondition(totalbookinfolist);

    if(total_pages>0){
        current_page = 1;
        currentpagebookinfolist =  getCurrentPageBooklist(totalbookinfolist,current_page);
    }else{
        current_page =0;
    }
    initConnections();

}


/**
 * @brief BookShelf::initConnections
 */
void BookShelf::initConnections()
{
    QObject::connect(this,SIGNAL(backHomePagesignal()),this,SLOT(backHomePageSlot()));
    QObject::connect(this,SIGNAL(updateDataSignal()),this,SLOT(updateDataSlot()));
    QObject::connect(this,SIGNAL(openBookSignal(int)),this,SLOT(openBookSlot(int)));
    QObject::connect(mprocess,SIGNAL(finished(int ,QProcess::ExitStatus)),this,SLOT(processFinisheds()));
    QObject::connect(statusbar,SIGNAL(broadcastTimeAndBattery(QString,int)),this,SLOT(updateTimeAndBatteryValue(QString,int)));
}

/**
 * @brief BookShelf::getTotalPagesForEachCondition
 * @param list
 * @return
 */
int BookShelf::getTotalPagesForEachCondition(QList<localDirectoryItem> *list)
{
    int temp=0;
    if(list->size()%9==0){
        temp = list->size()/9;
    }else{
        temp = list->size()/9+1;
    }
    return temp;

}


/**
 * @brief BookShelf::getCurrentPageBooklist
 * @param list
 * @return
 */
QList<localDirectoryItem>* BookShelf::getCurrentPageBooklist(QList<localDirectoryItem> *list,int currentpage)
{
    QList<localDirectoryItem> *temp = new QList<localDirectoryItem>;
    temp = commonutils->getCurrentPageBooks(list,currentpage,9);
    return temp;
}



/**
 * @brief BookShelf::backHomePageSlot
 */
void BookShelf::backHomePageSlot()
{
    int size = mainwindowlist->size();
    if(size>0){
        for(int i=0;i<size;i++){
            if(mainwindowlist->at(i)!=NULL){
                mainwindowlist->at(i)->close();
            }
        }
    }

}


/**
 * @brief BookShelf::updateDataSlot
 */
void BookShelf::updateDataSlot()
{
    totalbookinfolist->clear();
    switch (index_select) {
    case 0://The data from touched table.
        totalbookinfolist = Database::getInstance()->getAllDataFromTouchedTable();
        total_pages = getTotalPagesForEachCondition(totalbookinfolist);
        break;
    case 1://the data from totalbooklist table.
        totalbookinfolist = Database::getInstance()->getAllDataFromTotalBooklistTable("name");
        total_pages = getTotalPagesForEachCondition(totalbookinfolist);
        break;
    case 2://the data from totalbooklist table,but the data reverse.
        totalbookinfolist = Database::getInstance()->getAllDataFromTotalBooklistTable("xid");
        total_pages = getTotalPagesForEachCondition(totalbookinfolist);
        break;
    case 3://the data from totalbooklist table,but the data should be arranged by the condition of author.
        totalbookinfolist = Database::getInstance()->getAllDataFromTotalBooklistTable("author");
        total_pages = getTotalPagesForEachCondition(totalbookinfolist);
        break;
    default:
        break;
    }

    currentpagebookinfolist = commonutils->getCurrentPageBooks(totalbookinfolist,current_page,9);

    this->repaint();

}


/**
 * @brief BookShelf::openBookSlot
 * @param index
 */
void BookShelf::openBookSlot(int index)
{
    if((currentpagebookinfolist->size())>index){
        show_progress_bar = 1;
        this->repaint();
        commonutils->openBookFromFBreader(mprocess,currentpagebookinfolist->at(index).file_path);
    }
}


/**
 * @brief BookShelf::processFinisheds
 */
void BookShelf::processFinisheds()
{
    QApplication::setScreenUpdateMode(QApplication::EINK_GC16_MODE);//刷新
    this->repaint();
    QApplication::setScreenUpdateMode(QApplication::EINK_GL16_MODE);//刷新
    repaint();
}

void BookShelf::updateTimeAndBatteryValue(QString time, int battery)
{
    QApplication::setScreenUpdateMode(QApplication::EINK_GL16_MODE);//刷新
    systemtime = time;
    systembatteryvalue = battery;
    this->repaint();

}








