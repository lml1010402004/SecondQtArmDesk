#include "bookinfoitem.h"

BookInfoItem::BookInfoItem()
{

}

void BookInfoItem::setIcon_x(int iconx)
{
    this->icon_x = iconx;

}

void BookInfoItem::setIcon_y(int icony)
{
 this->icon_y = icony;
}

void BookInfoItem::setIcon_width(int iconwidth)
{
  this->icon_width=iconwidth;
}

void BookInfoItem::setIcon_height(int iconheight)
{
this->icon_height = iconheight;
}

void BookInfoItem::setBook_import_time(int importtime)
{
this->book_import_time = importtime;
}

void BookInfoItem::setBook_title(QString title)
{
this->book_title = title;
}

void BookInfoItem::setBook_author(QString author)
{
this->book_author = author;
}

void BookInfoItem::setBook_progress(int progress)
{
this->book_progress = progress;
}

void BookInfoItem::setBook_brief_content(QString content)
{
    this->book_brief_content = content;
}

void BookInfoItem::setBook_coverpath(QString path)
{
  this->cover_path = path;
}

int BookInfoItem::getIcon_x()
{
   return this->icon_x;
}

int BookInfoItem::getIcon_y()
{
 return this->icon_y;
}

int BookInfoItem::getIcon_width()
{
return this->icon_width;
}

int BookInfoItem::getIcon_height()
{
return this->icon_height;
}

int BookInfoItem::getBook_Import_time()
{
 return this->book_import_time;
}

QString BookInfoItem::getBook_title()
{
return this->book_title;
}

QString BookInfoItem::getBook_author()
{
return this->book_author;
}

int BookInfoItem::getBook_progress()
{
return this->book_progress;
}

QString BookInfoItem::getBook_brief_content()
{
    return this->book_brief_content;
}

QString BookInfoItem::getBook_coverpath()
{
   return this->cover_path;
}


