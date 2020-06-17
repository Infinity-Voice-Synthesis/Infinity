#ifndef LCC_H
#define LCC_H

#include "LCC_global.h"
#include "lce.h"
#include "libPDM/ifparts.h"
#include <QString>
#include <QStringList>
#include <QSettings>

class LCC_EXPORT LCC
{
public:
    LCC();
    ifparts *getparts();
private:
    void getid(IFLCC *lcc,QString type,QString name);
    void saveid(IFLCC *lcc,QString type,QString name);
    void getDBListofSEG(QVector<ifDBC *> *DB,QStringList list);
};

#endif // LCC_H
