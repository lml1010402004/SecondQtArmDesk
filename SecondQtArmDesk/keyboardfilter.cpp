#include "keyboardfilter.h"
#include <QDebug>
#include<QProcess>
QProcess *mProcess1;

bool KeyBoardFilter::hasTheTargetProcess(){

    char cmd[128] = "ps -a | grep SleepScreen | awk '{print $3}' ";
    char buf[1024] = {0};

    FILE *pp = popen(cmd, "r");


    if (pp != NULL)
    {
        fread(buf, 1, sizeof(buf), pp);
        QString str = buf;
        if(str.contains("SleepScreen")){
            return true;}else{
            return false;
        }
        pclose(pp);

    }
    return false;

}

KeyBoardFilter::KeyBoardFilter()
{
    isEnableSleepScreen = true;
}

KeyBoardFilter::~KeyBoardFilter()
{
    delete mProcess1;
    mProcess1 = NULL;
}

bool KeyBoardFilter::filter(int unicode, int keycode, int modifiers,
                            bool isPress, bool autoRepeat)
{


    qDebug()<<"KeyBoardFilter::filter keycode=" << keycode<<",isPress="<<isPress;
    if(Qt::Key_PowerDown == keycode && isPress)
    {

        if(isEnableSleepScreen)
        {
            system("/usr/wifi/disablewifi");

            if(!hasTheTargetProcess()){
                mProcess1  = new QProcess ;
                mProcess1->setEnvironment(mProcess1->environment());
                mProcess1->setWorkingDirectory("/usr/local/app/");
                mProcess1->start("/usr/local/app/SleepScreen");
            }
            isEnableSleepScreen = false;
        }
        else{

            isEnableSleepScreen = true;
        }
    }
    return false;
}
