#include "switchlanguagedialog.h"
#include"applications.h"
#include<QDebug>
#include<QApplication>

extern QTranslator qtTranslator;

switchLanguageDialog::switchLanguageDialog(QWidget *parent):QDialog(parent)
{
    this->setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    this->setGeometry(QRect(250,200,150,270));
    this->setFixedHeight(300);
    this->setFixedWidth(300);


    init();
}



void switchLanguageDialog::paintEvent(QPaintEvent *event)
{
    painter = new QPainter(this);
    myswitchlanguagedialog->drawRect(painter);
    myswitchlanguagedialog->drawLanguageContent(painter,list);

}

void switchLanguageDialog::mousePressEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();
    int index = getIndexFromGeograh(x,y);
    if(index==0){
      bool flag = qtTranslator.load(":/mypic/SecondQt_Cn.qm");
      qDebug()<<"---==========qtTranslator.load()"<<flag;
        QApplication::installTranslator(&qtTranslator);
        this->close();
    }else if(index==1){
     //here we need swtich into English Language.
        bool flag = qtTranslator.load(":/mypic/SecondQt_En.qm");
        qDebug()<<"---==========qtTranslator.load()"<<flag;
        QApplication::installTranslator(&qtTranslator);
        this->close();
    }else if(index==2){
        this->close();
    }else if(index==3){
        this->close();
    }

}

void switchLanguageDialog::init()
{

    list = new QList<QString>;
    list->append("Chinese");
    list->append("English");
    list->append("German");
    list->append("Japanese");
    myswitchlanguagedialog = new drawSwitchLanguageDailog;

}

int switchLanguageDialog::getIndexFromGeograh(int x, int y)
{

int index = -1;
if(SWITCHLANGUAGEINDEX){
    if(SWTICHLANGUAGEINDEX1){
        index = 0;
    }else if(SWTICHLANGUAGEINDEX2){
        index = 1;
    }else if(SWTICHLANGUAGEINDEX3){
        index = 2;
    }else if(SWTICHLANGUAGEINDEX4){
        index = 3;
    }
    return index;
}

}
