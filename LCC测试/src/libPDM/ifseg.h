#ifndef IFSEG_H
#define IFSEG_H

#include <QString>
#include <QVector>
#include "iflan.h"
#include "ifcha.h"
#include "ifdbc.h"
#include "ifset.h"

class ifSEG
{
public:
    ifSEG();
    QString name;//合成引擎名
    QString id;//合成引擎id
    QString icon;//合成引擎图标
    QString tool;//引擎声库制作工具
    QVector<iflan> *lan=new QVector<iflan>;//引擎语言
    QVector<ifDBC *> *DB=new QVector<ifDBC *>;//声库列表
    QVector<ifset *> *FST=new QVector<ifset *>;//平参数表
    QVector<ifset *> *WST=new QVector<ifset *>;//波参数表
};

#endif // IFSEG_H
