#-------------------------------------------------
#
# Project created by QtCreator 2018-05-31T08:54:11
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SecondQtArmDesk
TEMPLATE = app


SOURCES += main.cpp\
    modulePages/mainpages.cpp \
    drawViewfunctions/drawmainpageview.cpp \
    drawViewfunctions/drawbookshelfpageview.cpp \
    drawViewfunctions/drawbookonlinepageview.cpp \
    drawViewfunctions/drawgamepageview.cpp \
    drawViewfunctions/drawcommonview.cpp \
    dataItem/bookinfoitem.cpp \
    modulePages/bookshelf.cpp \
    modulePages/bookonline.cpp \
    modulePages/gamemodule.cpp \
    dataItem/buttonbottom.cpp \
    dataItem/conditionitem.cpp \
    modulePages/pulldownwindow.cpp \
    drawViewfunctions/drawpulldonwwindow.cpp \
    modulePages/settings.cpp \
    drawViewfunctions/drawsettingsmodules.cpp \
    dataItem/systemitems.cpp \
    modulePages/settinglight.cpp \
    drawViewfunctions/drawsettinglight.cpp \
    modulePages/settingscreen.cpp \
    modulePages/settingnetwork.cpp \
    drawViewfunctions/drawsettingscreen.cpp \
    drawViewfunctions/drawsettingnetwork.cpp \
    modulePages/settingusbtransfer.cpp \
    drawViewfunctions/drawsettingusbtransfer.cpp \
    modulePages/settingdateandtime.cpp \
    drawViewfunctions/drawsettingdateandtime.cpp \
    modulePages/settinglanguage.cpp \
    drawViewfunctions/drawsettinglanguage.cpp \
    modulePages/settingrestore.cpp \
    drawViewfunctions/drawsettingrestore.cpp \
    modulePages/settingabouttablet.cpp \
    drawViewfunctions/drawsettingabouttablet.cpp \
    dataItem/wallpaperitem.cpp \
    dataItem/wifiitem.cpp \
    utils/hidepulldown.cpp \
    utils/wifiservice.cpp \
    modulePages/connectwifidialog.cpp \
    drawViewfunctions/drawconnectwifidialog.cpp \
    keyboardfilter.cpp \
    usbservice.cpp \
    dataItem/datemodel.cpp \
    modulePages/switchlanguagedialog.cpp \
    drawViewfunctions/drawswitchlanguagedailog.cpp \
    utils/commonutils.cpp \
    database/database.cpp \
    utils/mysetting.cpp \
    modulePages/searchresultofbook.cpp \
    drawViewfunctions/drawsearchresultofbooks.cpp \
    modulePages/setdateandhour.cpp \
    drawViewfunctions/drawdateandhour.cpp


HEADERS  += \
    modulePages/mainpages.h \
    modulePages/applications.h \
    applications.h \
    statusbar.h \
    statusbar_global.h \
    drawViewfunctions/drawmainpageview.h \
    drawViewfunctions/drawbookshelfpageview.h \
    drawViewfunctions/drawbookonlinepageview.h \
    drawViewfunctions/drawgamepageview.h \
    drawViewfunctions/drawcommonview.h \
    dataItem/bookinfoitem.h \
    modulePages/bookshelf.h \
    modulePages/bookonline.h \
    modulePages/gamemodule.h \
    dataItem/buttonbottom.h \
    dataItem/conditionitem.h \
    modulePages/pulldownwindow.h \
    drawViewfunctions/drawpulldonwwindow.h \
    modulePages/settings.h \
    drawViewfunctions/drawsettingsmodules.h \
    dataItem/systemitems.h \
    modulePages/settinglight.h \
    drawViewfunctions/drawsettinglight.h \
    modulePages/settingscreen.h \
    modulePages/settingnetwork.h \
    drawViewfunctions/drawsettingscreen.h \
    drawViewfunctions/drawsettingnetwork.h \
    modulePages/settingusbtransfer.h \
    drawViewfunctions/drawsettingusbtransfer.h \
    modulePages/settingdateandtime.h \
    drawViewfunctions/drawsettingdateandtime.h \
    modulePages/settinglanguage.h \
    drawViewfunctions/drawsettinglanguage.h \
    modulePages/settingrestore.h \
    drawViewfunctions/drawsettingrestore.h \
    modulePages/settingabouttablet.h \
    drawViewfunctions/drawsettingabouttablet.h \
    dataItem/wallpaperitem.h \
    dataItem/wifiitem.h \
    syssettings.h \
    utils/hidepulldown.h \
    utils/wifiservice.h \
    modulePages/connectwifidialog.h \
    drawViewfunctions/drawconnectwifidialog.h \
    keyboard.h \
    keyboardfilter.h \
    pinyinim.h \
    usbservice.h \
    dataItem/datemodel.h \
    modulePages/switchlanguagedialog.h \
    drawViewfunctions/drawswitchlanguagedailog.h \
    utils/commonutils.h \
    database/database.h \
    utils/mysetting.h \
    modulePages/searchresultofbook.h \
    drawViewfunctions/drawsearchresultofbooks.h \
    modulePages/setdateandhour.h \
    drawViewfunctions/drawdateandhour.h


FORMS    +=



RESOURCES += \
    pics.qrc

TRANSLATIONS +=SecondQt_Cn.ts   \
                SecondQt_En.ts




win32:CONFIG(release, debug|release): LIBS += -L$$PWD/libs/release/ -lStatusBar
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/libs/debug/ -lStatusBar
else:unix: LIBS += -L$$PWD/libs/ -lStatusBar

INCLUDEPATH += $$PWD/libs
DEPENDPATH += $$PWD/libs

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/libs/release/ -lSysSettings
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/libs/debug/ -lSysSettings
else:unix: LIBS += -L$$PWD/libs/ -lSysSettings



INCLUDEPATH += $$PWD/libs
DEPENDPATH += $$PWD/libs


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/libs/release/ -lPinyinIM
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/libs/debug/ -lPinyinIM
else:unix: LIBS += -L$$PWD/libs/ -lPinyinIM

INCLUDEPATH += $$PWD/libs
DEPENDPATH += $$PWD/libs
