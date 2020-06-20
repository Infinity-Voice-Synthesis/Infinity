#ifndef IFTPK_GLOBAL_H
#define IFTPK_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(IFTPK_LIBRARY)
#  define IFTPK_EXPORT Q_DECL_EXPORT
#else
#  define IFTPK_EXPORT Q_DECL_IMPORT
#endif

#endif // IFTPK_GLOBAL_H
