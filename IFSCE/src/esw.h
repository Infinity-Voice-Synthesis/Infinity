#ifndef ESW_H
#define ESW_H

#include <QString>
#include <QVector>

class ESW
{
public:
    ESW();
    QString name;//参数名
    QVector<double> *data=new QVector<double>;//参数数值列
    double minValue;//最小值
    double maxValue;//最大值
    double normalValue;//默认值
    bool open=false;//是否在编辑器上展开
};

#endif // ESW_H
