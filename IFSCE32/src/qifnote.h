#ifndef QIFNOTE_H
#define QIFNOTE_H

#include <QString>
#include "qifdic.h"
#include <QVector>

class QIFnote
{
public:
    QIFnote();
    QString name="a";//音符名
    double AT=0;//开始位置
    double RT=1;//结束位置
    int NH=60;//音高
    QString DB0;//声库0
    QString ADB0;//子声库0
    QString DB1;//声库1
    QString ADB1;//子声库1
    QString CHA;//情绪名
    bool mute=false;//静音
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

    double SP=1;//颤音开始位置占比
    double SH=0;//颤音高度系数
    double SV=0;//颤音速度系数

    bool select=false;//编辑器选择
    bool moving=false;//编辑器移动音符
    bool timing=false;//编辑器修改音符时长

    void solvedic(QVector<QIFdic *> *dic);
};

#endif // QIFNOTE_H
