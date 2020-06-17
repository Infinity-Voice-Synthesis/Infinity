#ifndef IFPARTS_H
#define IFPARTS_H

#include <QVector>
#include "ifseg.h"
#include "ifaeg.h"
#include "ifdbc.h"
#include "ifplu.h"

class ifparts
{
public:
    ifparts();
    QVector<ifSEG *> *SEG=new QVector<ifSEG *>;
    QVector<ifAEG *> *AEG=new QVector<ifAEG *>;
    //QVector<ifDBC *> *DB=new QVector<ifDBC *>;
    QVector<ifPLU *> *PLU=new QVector<ifPLU *>;
};

#endif // IFPARTS_H
