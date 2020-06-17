#ifndef IFSET_H
#define IFSET_H

#include <QString>

class ifset
{
public:
    ifset();
    QString name;//参数名
    double up;//最大值
    double down;//最小值
    double normal;//默认值
};

#endif // IFSET_H
