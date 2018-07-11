#include "setdateandhour.h"
#include<QHBoxLayout>
#include<QApplication>
#include"applications.h"
#include<QProcess>
#include<QDebug>

extern int dateorTime;
extern QString systemtime;

setDateAndHour::setDateAndHour(QWidget *parent) : QMainWindow(parent)
{
    this->setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    QApplication::setScreenUpdateMode(QApplication::EINK_GL16_MODE);//刷新
    init();
    this->setGeometry(QRect(100,150,400,300));
    QHBoxLayout *leftlayout = new QHBoxLayout;
    leftlayout->addWidget(mylineedit1);

    leftlayout->setGeometry(QRect(44,116,60,40));

    QHBoxLayout *rightlayout = new QHBoxLayout;
    rightlayout->addWidget(mylineedit2);
    rightlayout->setGeometry(QRect(245,116,60,40));
    QHBoxLayout *totallayout = new QHBoxLayout;
    totallayout->addLayout(leftlayout);
    totallayout->addLayout(rightlayout);
    setLayout(totallayout);

}

setDateAndHour::~setDateAndHour()
{
    delete mylineedit1,mylineedit2,painter;
    mylineedit1 =NULL;
    mylineedit2 = NULL;
    painter = NULL;

}

void setDateAndHour::init()
{
    mylineedit1 = new QLineEdit(this);
    mylineedit2 = new QLineEdit(this);
    drawdateandhour = new drawDateAndHour;
    mylineedit1->setFixedHeight(40);
    mylineedit1->setFixedWidth(121);
    mylineedit2->setFixedHeight(40);
    mylineedit2->setFixedWidth(121);



}

void setDateAndHour::paintEvent(QPaintEvent *event)
{
    painter = new QPainter(this);
    drawdateandhour->drawConfirmAndCancleButton(painter);
    drawdateandhour->drawLeftInputArea(painter);
    drawdateandhour->drawRightInputArea(painter);
}

void setDateAndHour::mousePressEvent(QMouseEvent *event)
{
    QString str="";
    int x = event->x();
    int y = event->y();
    if(DATEANDTIMECONFIRM){
        if(dateorTime==0){
         QString str1 = mylineedit1->text();
         QString str2 = mylineedit2->text();
         QStringList s = systemtime.split(" ");
             str = "2018-"+str1+"-"+str2+" "+s.at(1);
        }else if(dateorTime==1){
             QString str1 = mylineedit1->text();
             QString str2 = mylineedit2->text();
             str = str1+":"+str2;
        }
        setDateandHourIntoSystem(str);
        emit updateTimeRightnowSignal();
        qDebug()<<"send signal";
        qDebug()<<"send signal";
        qDebug()<<"send signal";
        this->close();
    }else if(DATEANDTIMECANCLE){
        this->close();
    }
}

void setDateAndHour::setDateandHourIntoSystem(QString time)
{
    if(!time.isEmpty()){
    QString m = QString("date -s ")+QString("\"")+time+QString("\"");
     qDebug()<<"date========="<<m;
    QProcess::startDetached(m);
    QProcess::startDetached("hwclock -w");
    QProcess::startDetached("sync");
    }
}

