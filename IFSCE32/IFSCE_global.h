#ifndef IFSCE_GLOBAL_H
#define IFSCE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(IFSCE_LIBRARY)
#  define IFSCE_EXPORT Q_DECL_EXPORT
#else
#  define IFSCE_EXPORT Q_DECL_IMPORT
#endif

#endif // IFSCE_GLOBAL_H
