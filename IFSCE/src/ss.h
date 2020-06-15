#ifndef SS_H
#define SS_H

#include <QString>
#include <QVector>

class SS
{
public:
    SS();
    QString name;//参数名
    QVector<double> *data=new QVector<double>;//参数数据列
    double minValue;//最小值
    double maxValue;//最大值
    double normalValue;//默认值
    bool flat=false;//是否为平参数
    bool edit=false;//参数是否正在被编辑
    int count=0;//编辑器数
};

#endif // SS_H
