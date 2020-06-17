#ifndef QIFDIC_H
#define QIFDIC_H

#include <QString>

class QIFdic
{
public:
    QIFdic();
    QString name="a";//单词名称
    QString C="";//清音
    QString V1="a";//浊音1
    QString V2="";//浊音2
    QString V3="";//浊音3
    double CP=0;//清音开始位置占比
    double V1P=0;//浊音1开始位置占比
    double V2P=1;//浊音2开始位置占比
    double V3P=1;//浊音3开始位置占比
    double P1=0.2;//头腹界限位置占比
    double P2=0.8;//腹尾界限位置占比
};

#endif // QIFDIC_H
