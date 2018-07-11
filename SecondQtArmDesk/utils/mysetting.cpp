#include "mysetting.h"

mySetting::mySetting()
{
    syssettings = new QSettings;
}

QString mySetting::getCurrentBookPath()
{
    syssettings->beginGroup("mySetting");
    QString temp =syssettings->value(CURRENTBOOKPATH).toString();
    syssettings->endGroup();
    return temp;

}

void mySetting::setCurrentBookPath(QString path)
{
    syssettings->beginGroup("mySetting");
    syssettings->setValue(CURRENTBOOKPATH,path);
    syssettings->endGroup();

}

QString mySetting::getCurrentBookTitle()
{
  syssettings->beginGroup("mySetting");
 QString temp = syssettings->value(CURRENTBOOKTITLE).toString();
  syssettings->endGroup();
  return temp;
}

void mySetting::setCurrentBookTitle(QString title)
{
    syssettings->beginGroup("mySetting");
    syssettings->setValue(CURRENTBOOKTITLE,title);
    syssettings->endGroup();

}

QString mySetting::getCurrentBookAuthor()
{
    syssettings->beginGroup("mySetting");
    QString temp = syssettings->value(CURRENTBOOKAUTHOR).toString();
    syssettings->endGroup();
    return temp;

}

QString mySetting::setCurrentBookAuthor(QString str)
{
    syssettings->beginGroup("mySetting");
    syssettings->setValue(CURRENTBOOKAUTHOR,str);
    syssettings->endGroup();

}

