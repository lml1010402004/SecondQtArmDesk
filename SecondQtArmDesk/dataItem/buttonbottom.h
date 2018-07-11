#ifndef BUTTONBOTTOM_H
#define BUTTONBOTTOM_H
#include<QString>

class buttonbottom
{
public:
    buttonbottom();
    void setLine_x(int x);
    void setLine_y(int y);
    void setLine_width(int width);
    void setLine_height(int height);
    void setIcon_x(int x);
    void setIcon_y(int y);
    void setIcon_width(int width);
    void setIcon_height(int height);
    void setText_x(int x);
    void setText_y(int y);
    void setText_width(int width);
    void setText_height(int height);

    void setText(QString text);

    int getLine_x();
    int getLine_y();
    int getLine_width();
    int getLine_height();
    int getIcon_x();
    int getIcon_y();
    int getIcon_width();
    int getIcon_height();
    int getText_x();
    int getText_y();
    int getText_width();
    int getText_height();
    QString getText();


private:
int line_x;
int line_y;
int line_width;
int line_height;

int icon_x;
int icon_y;
int icon_width;
int icon_height;

int text_x;
int text_y;
int text_width;
int text_height;
QString text;







};

#endif // BUTTONBOTTOM_H
