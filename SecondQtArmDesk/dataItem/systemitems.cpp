#include "systemitems.h"

SystemItems::SystemItems()
{

}

void SystemItems::setItem_x(int item_x)
{
    this->item_x = item_x;

}

void SystemItems::setItem_y(int item_y)
{
    this->item_y = item_y;
}

void SystemItems::setItem_width(int item_width)
{
    this->item_width = item_width;
}

void SystemItems::setItem_height(int item_height)
{
    this->item_height = item_height;
}

int SystemItems::getItem_x()
{
    return this->item_x;
}

int SystemItems::getItem_y()
{
    return this->item_y;
}

int SystemItems::getItem_width()
{
    return this->item_width;
}

int SystemItems::getItem_height()
{
    return this->item_height;
}

void SystemItems::setItem_text_x(int item_text_x)
{
     this->item_text_x = item_text_x;
}

void SystemItems::setItem_text_y(int item_text_y)
{
     this->item_text_y = item_text_y;
}

void SystemItems::setItem_text_width(int item_text_width)
{
     this->item_text_width = item_text_width;
}

void SystemItems::setItem_text_height(int item_text_height)
{
     this->item_text_height = item_text_height;
}

int SystemItems::getItem_text_x()
{
       return item_text_x;
}

int SystemItems::getItem_text_y()
{
       return item_text_y;
}

int SystemItems::getItem_text_width()
{
       return item_text_width;
}

int SystemItems::getItem_text_height()
{
    return item_text_height;
}

void SystemItems::setItem_text_text(QString str)
{
    this->item_text_text = str;
}

QString SystemItems::getItem_text_text()
{
    return this->item_text_text;
}

void SystemItems::setItem_icon_x(int item_icon_x)
{
      this->item_icon_x = item_icon_x;
}

void SystemItems::setItem_icon_y(int item_icon_y)
{
      this->item_icon_y = item_icon_y;
}

void SystemItems::setItem_icon_width(int item_icon_width)
{
       this->item_icon_width = item_icon_width;
}

void SystemItems::setItem_icon_height(int item_icon_height)
{
    this->item_icon_height = item_icon_height;
}

void SystemItems::setItem_icon_path(QString path)
{
    this->item_icon_path = path;
}

int SystemItems::getItem_icon_x()
{
       return this->item_icon_x;
}

int SystemItems::getItem_icon_y()
{
       return this->item_icon_y;
}

int SystemItems::getItem_icon_width()
{
       return this->item_icon_width;
}

int SystemItems::getItem_item_height()
{
    return this->item_icon_height;
}

QString SystemItems::getItem_icon_path()
{
      return this->item_icon_path;
}
