#ifndef AEGMODEL_GLOBAL_H
#define AEGMODEL_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(AEGMODEL_LIBRARY)
#  define AEGMODEL_EXPORT Q_DECL_EXPORT
#else
#  define AEGMODEL_EXPORT Q_DECL_IMPORT
#endif

#endif // AEGMODEL_GLOBAL_H
