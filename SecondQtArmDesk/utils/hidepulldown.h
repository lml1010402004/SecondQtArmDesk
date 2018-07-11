#ifndef HIDEPULLDOWN_H
#define HIDEPULLDOWN_H

#include <QObject>
#include<QThread>
#include"modulePages/pulldownwindow.h"
#include"modulePages/mainpages.h"


class HidePullDown : public QThread
{
    Q_OBJECT
public:
    HidePullDown(QObject *obj);
    void run();

signals:
public slots:

};

#endif // HIDEPULLDOWN_H
