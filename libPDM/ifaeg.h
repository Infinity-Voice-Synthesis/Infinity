#ifndef IFAEG_H
#define IFAEG_H

#include <QString>
#include <QVector>
#include "ifeff.h"

class ifAEG
{
public:
    ifAEG();
    QString name;//音频引擎名
    QString id;//音频引擎id
    QString icon;//音频引擎图标
    QVector<ifEFF *> *EFF=new QVector<ifEFF *>;//效果器列表
};

#endif // IFAEG_H
