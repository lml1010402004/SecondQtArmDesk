#ifndef BOOKINFOITEM_H
#define BOOKINFOITEM_H
#include<QString>


class BookInfoItem
{

public:
    int icon_x;
    int icon_y;
    int icon_width;
    int icon_height;
    int book_import_time;

    QString book_title;
    QString book_author;
    int book_progress;
    QString book_brief_content;
    QString cover_path;



public:
    BookInfoItem();
    void setIcon_x(int iconx);
    void setIcon_y(int icony);
    void setIcon_width(int iconwidth);
    void setIcon_height(int iconheight);
    void setBook_import_time(int importtime);

    void setBook_title(QString title);
    void setBook_author(QString author);
    void setBook_progress(int progress);
    void setBook_brief_content(QString content);
    void setBook_coverpath(QString path);


    int getIcon_x();
    int getIcon_y();
    int getIcon_width();
    int getIcon_height();
    int getBook_Import_time();

    QString getBook_title();
    QString getBook_author();
    int getBook_progress();
    QString getBook_brief_content();
    QString getBook_coverpath();



};

#endif // BOOKINFOITEM_H
