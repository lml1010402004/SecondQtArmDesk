#ifndef MYSETTING_H
#define MYSETTING_H
#include<QSettings>
#include<QString>

const QString CURRENTBOOKPATH = "currentBookPath";
const QString CURRENTBOOKTITLE = "currentBookTitle";
const QString CURRENTBOOKAUTHOR = "currentBookAuthor";


class mySetting
{
public:
     mySetting();
     QString getCurrentBookPath();
     void setCurrentBookPath(QString path);
     QString getCurrentBookTitle();
     void setCurrentBookTitle(QString title);
     QString getCurrentBookAuthor();
     QString setCurrentBookAuthor(QString str);

private:
     QSettings *syssettings;

};

#endif // MYSETTING_H
