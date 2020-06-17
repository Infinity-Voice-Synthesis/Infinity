#ifndef LCC_GLOBAL_H
#define LCC_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(LCC_LIBRARY)
#  define LCC_EXPORT Q_DECL_EXPORT
#else
#  define LCC_EXPORT Q_DECL_IMPORT
#endif

#endif // LCC_GLOBAL_H
