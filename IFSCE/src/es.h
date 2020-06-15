#ifndef ES_H
#define ES_H

#include "esw.h"

class ES
{
public:
    ES();
    QString name;//效果器名称
    QVector<ESW *> *data=new QVector<ESW *>;//效果器参数列表
    QVector<double> *Mix=new QVector<double>;//效果器混合系数
    bool select=false;//效果器在编辑器中显示
};

#endif // ES_H
