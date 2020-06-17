#ifndef IFDBC_H
#define IFDBC_H

#include <QString>
#include <QVector>
#include "iflan.h"
#include "ifadb.h"
#include "ifcha.h"
#include "libIFDM/qifdic.h"

class ifDBC
{
public:
    ifDBC();
    QString name;//声库名
    QString id;//声库id
    QString icon;//声库图标
    QVector<iflan> *lan=new QVector<iflan>;//声库语言
    QVector<ifADB *> *adb=new QVector<ifADB *>;//子声库表
    QVector<ifcha> *cha=new QVector<ifcha>;//情绪表
    QVector<QIFdic *> *dictionary=new QVector<QIFdic *>;//词典
};

#endif // IFDBC_H
