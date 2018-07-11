#include "connectwifidialog.h"
#include"applications.h"
#include<QHBoxLayout>
#include<QCursor>

connectWifiDialog::connectWifiDialog(QWidget *parent):QDialog(parent)
{
    //this->setAttribute(Qt::WA_TranslucentBackground,true);
    this->setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);

   // this->setFixedHeight(GLOBAL_SCREEN_FIXED_HEIGHT);
   // this->setFixedWidth(GLOBAL_SCREEN_FIXED_WIDTH);
    init();

    this->setGeometry(QRect(100,150,400,300));
    QHBoxLayout *midlayout = new QHBoxLayout;
    midlayout->addWidget(mylineedit);
    midlayout->setGeometry(QRect(0,0,400,300));

    setLayout(midlayout);
    QCursor cursor(0);
    mylineedit->setCursor(cursor);


}

connectWifiDialog::~connectWifiDialog()
{
    delete mylineedit,painter,drawconnectwifidialog;
    mylineedit = NULL;
    painter = NULL;
    drawconnectwifidialog =NULL;


}

void connectWifiDialog::paintEvent(QPaintEvent *event)
{
    painter = new QPainter(this);
    drawconnectwifidialog->drawRectAndName(painter,"Yitoa");
    drawconnectwifidialog->drawInputPassword(painter);
    drawconnectwifidialog->drawTwoButtons(painter);
}

void connectWifiDialog::mousePressEvent(QMouseEvent *event)
{

    int x = event->x();
    int y = event->y();
    if(WIFICONNECTDIALOGCONNECT){
        if(mylineedit->text().isEmpty()){
            return;
        }else{
            emit connectWifiSignal(mylineedit->text());
            mylineedit->clear();

        }

    }else if(WIFICONNECTDIALOGCANCLE){
        this->close();
    }

}

void connectWifiDialog::init()
{
    drawconnectwifidialog = new drawConnectWifiDialog;
    mylineedit = new QLineEdit;

    mylineedit->setFixedHeight(40);
    mylineedit->setFixedWidth(360);

}
