#include "hidepulldown.h"


extern pullDownWindow *pulldonwwindow;

HidePullDown::HidePullDown(QObject *obj):QThread(obj)
{

}

void HidePullDown::run()
{
    if(pulldonwwindow!=NULL){

        pulldonwwindow->hide();
    }

}
