#ifndef IFEFF_H
#define IFEFF_H

#include <QString>
#include "ifset.h"
#include <QVector>

class ifEFF
{
public:
    ifEFF();
    QString name;//效果器名
    QVector<ifset *> *sets=new QVector<ifset *>;//效果器参数列
};

#endif // IFEFF_H
