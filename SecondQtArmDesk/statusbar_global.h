#ifndef STATUSBAR_GLOBAL_H
#define STATUSBAR_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(STATUSBAR_LIBRARY)
#  define STATUSBARSHARED_EXPORT Q_DECL_EXPORT
#else
#  define STATUSBARSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // STATUSBAR_GLOBAL_H

#define VIEW_SCALE_UP 1

#define SCREEN_FIXED_WIDTH 600
#define SCREEN_FIXED_HEIGHT 23
