#ifndef SEGMODEL_GLOBAL_H
#define SEGMODEL_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(SEGMODEL_LIBRARY)
#  define SEGMODEL_EXPORT Q_DECL_EXPORT
#else
#  define SEGMODEL_EXPORT Q_DECL_IMPORT
#endif

#endif // SEGMODEL_GLOBAL_H
