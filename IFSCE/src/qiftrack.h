#ifndef QIFTRACK_H
#define QIFTRACK_H

#include "qifnote.h"
#include "es.h"
#include "ss.h"
#include "qifdic.h"
#include "qwavehandle.h"
#include <QtMath>

class QIFtrack
{
public:
    QIFtrack();
    QString name;//轨道名
    QVector<QIFnote *> *notef=new QVector<QIFnote *>;//音符列表
    QVector<SS *> *flatsf=new QVector<SS *>;//平参数列表
    QVector<SS *> *wavesf=new QVector<SS *>;//波参数列表
    double wavetimeat=0;//伴奏时间校正
    bool mastertrack=false;//是否为主轨
    bool wavetrack=false;//是否为伴奏轨
    QString wavefilepath;//伴奏文件路径
    QWaveHandle *wavedata=new QWaveHandle;//伴奏数据
    bool mute=false;//是否静音
    bool solo=false;//是否独奏
    QVector<QIFdic *> *dictionary=new QVector<QIFdic *>;//轨道字典
    QString synthesize_engine_add_information;//合成引擎附加数据
    QString DB0;//声库0
    QString DB1;//声库1
    QString SEG;//合成引擎
    QVector<ES *> *effects=new QVector<ES *>;//效果器设置
    bool select=false;//轨道在编辑器上显示

    double tempo=120;//项目曲速
    int clamp=4;//项目节拍
    qint64 FS=44100;//项目采样率
    qint64 time=20;//项目小节时长

    int addnote(double AT,double RT,int NH);
    void checknotemute();
    int movenote(int id,double AT,int NH);
    void deletenote(int id);
    void setnoteRT(int id,double RT);
    void sloveTONbyPIT();
    void slovePITbyTON();
};

#endif // QIFTRACK_H
