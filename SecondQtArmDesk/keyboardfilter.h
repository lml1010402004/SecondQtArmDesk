#ifndef KEYBOARDFILTER_H
#define KEYBOARDFILTER_H
#include <QWSServer>

class KeyBoardFilter : public QWSServer::KeyboardFilter
{
public:

    KeyBoardFilter();

    ~KeyBoardFilter();
    bool filter(int unicode, int keycode, int modifiers,
                        bool isPress, bool autoRepeat);

    bool hasTheTargetProcess();


private:
    bool isEnableSleepScreen;

};

#endif // KEYBOARDFILTER_H
