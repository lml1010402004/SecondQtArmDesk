#ifndef COMMONUTILS_H
#define COMMONUTILS_H

#include<sys/statfs.h>
#include<QString>
#include<QList>
#include<database/database.h>
#include<QProcess>
#include<QStringList>
#include<QPainter>
#include<QRect>


class commonUtils
{

public:
    commonUtils();
    static int getStorageOfDevice();
    static QString GetLocalMac();

    QList<localDirectoryItem>* getCurrentPageBooks(QList<localDirectoryItem> *list,int currentPage,int pagesize);
    void openBookFromFBreader(QProcess *process,QString bookpath);

    void drawProgressBarOpeningBook(QPainter *painter);




private:

    QStringList arguments;

};

#endif // COMMONUTILS_H
