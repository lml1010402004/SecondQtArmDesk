#include "searchresultofbook.h"
#include"applications.h"
#include<QLineEdit>
#include<QHBoxLayout>
#include"keyboard.h"
#include"keyboardfilter.h"

extern QList<QMainWindow*> *mainwindowlist;
extern QString systemtime;
extern int systembatteryvalue;

searchResultofBook::searchResultofBook(QWidget *parent) : QMainWindow(parent)
{
    mainwindowlist->append(this);
    this->setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    this->setFixedHeight(GLOBAL_SCREEN_FIXED_HEIGHT);
    this->setFixedWidth(GLOBAL_SCREEN_FIXED_WIDTH);
    init();
    mylineedit = new QLineEdit(this);
    QHBoxLayout *hboxlayout = new QHBoxLayout();
    hboxlayout->addWidget(mylineedit);
    hboxlayout->setGeometry(QRect(60,135,400,60));
    setLayout(hboxlayout);
}

void searchResultofBook::init()
{
    mystatusbar = new StatusBar(this);
    drawsearchresultbooks = new drawSearchResultofBooks;
    searchoutresultbooklist = new QList<localDirectoryItem>;

    QObject::connect(this,SIGNAL(searchBooksSignal(QString)),this,SLOT(getSearchOutBookList(QString)));
    connect(mystatusbar,SIGNAL(broadcastTimeAndBattery(QString,int)),this,SLOT(updateTimeAndBatteryValue(QString,int)));
}

void searchResultofBook::mousePressEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();
    if(BACKTOMAINPAGE){
        backToHomePage();
    }else if(SHOWPULLDOWNWINDOWSIGNAL){
        emit showPullDownSignal();
    }else if(SEARCHBOOKFROMDATABASE){
        QString str = mylineedit->text();
        if(str.length()>0)
            emit searchBooksSignal(str);
    }else if(RETURNICONPOSITION){
        this->close();
    }

}

void searchResultofBook::paintEvent(QPaintEvent *event)
{
    painter = new QPainter(this);
    rect.setRect(0,0,GLOBAL_SCREEN_FIXED_WIDTH,GLOBAL_SCREEN_FIXED_HEIGHT);
    painter->fillRect(rect,QBrush(Qt::white));
    mystatusbar->drawBattery(painter,systembatteryvalue);
    mystatusbar->drawSystemTime(painter,systemtime);
    mystatusbar->drawPullDownRectangle(painter);
    drawsearchresultbooks->drawHomeIcon(painter);
    drawsearchresultbooks->drawSearchButton(painter);

    drawsearchresultbooks->drawSearchOutBooks(painter,searchoutresultbooklist);
    drawsearchresultbooks->drawBackIcon(painter);

}

void searchResultofBook::backToHomePage()
{

    for(int i=0;i<mainwindowlist->size();i++){
        mainwindowlist->at(i)->close();
    }
}

void searchResultofBook::getSearchOutBookList(QString str)
{
    searchoutresultbooklist->clear();
    searchoutresultbooklist = Database::getInstance()->getSearchResultBookList(str);
    for(int i=0;i<searchoutresultbooklist->size();i++)
        qDebug()<<"searchoutresultbooklist.size==="<<searchoutresultbooklist->at(i).file_name;
    this->repaint();
}

void searchResultofBook::updateTimeAndBatteryValue(QString time, int battery)
{

    QApplication::setScreenUpdateMode(QApplication::EINK_GL16_MODE);//刷新
    systemtime = time;
    systembatteryvalue = battery;
    this->repaint();
}



