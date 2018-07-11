#ifndef SYSTEMITEMS_H
#define SYSTEMITEMS_H
#include<QString>

class SystemItems
{
public:
    SystemItems();

private:
    int item_x;
    int item_y;
    int item_width;
    int item_height;

    int item_text_x;
    int item_text_y;
    int item_text_width;
    int item_text_height;
    QString item_text_text;

    int item_icon_x;
    int item_icon_y;
    int item_icon_width;
    int item_icon_height;
    QString item_icon_path;

public:
    void setItem_x(int item_x);
    void setItem_y(int item_y);
    void setItem_width(int item_width);
    void setItem_height(int item_height);
    int getItem_x();
    int getItem_y();
    int getItem_width();
    int getItem_height();



    void setItem_text_x(int item_text_x);
    void setItem_text_y(int item_text_y);
    void setItem_text_width(int item_text_width);
    void setItem_text_height(int item_text_height);
    int getItem_text_x();
    int getItem_text_y();
    int getItem_text_width();
    int getItem_text_height();
    void setItem_text_text(QString str);
    QString getItem_text_text();


    void setItem_icon_x(int item_icon_x);
    void setItem_icon_y(int item_icon_y);
    void setItem_icon_width(int item_icon_width);
    void setItem_icon_height(int item_icon_height);
    void setItem_icon_path(QString path);
    int getItem_icon_x();
    int getItem_icon_y();
    int getItem_icon_width();
    int getItem_item_height();
    QString getItem_icon_path();








};

#endif // SYSTEMITEMS_H
