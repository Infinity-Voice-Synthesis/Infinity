#ifndef QIFPROJECT_H
#define QIFPROJECT_H

#include "qiftrack.h"
#include <QMessageBox>

class QIFproject
{
public:
    QIFproject();
    QString name;//项目名
    QString editor;//编辑者
    QIFtrack *Mastertrack=new QIFtrack;//主轨
    QVector<QIFtrack *> *tracklist=new QVector<QIFtrack *>;//音轨列表
    qint64 time=20;//项目小节时长
    double tempo=120;//项目曲速
    int clamp=4;//项目节拍
    QString AEG;//音频引擎
    QString audio_engine_add_information;//音频引擎附加信息
    qint64 FS=44100;//项目采样率
    bool saved=false;//已保存
    QString Filepath;//文件路径
    void settime(int time);
    void settempo(double tempo);
    void addtrack();
    void settrack(int track);
    void deletetrack(int track);
    void setclamp(int clamp);
};

#endif // QIFPROJECT_H
