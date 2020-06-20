#ifndef IFTPK_H
#define IFTPK_H

#include "IFTPK_global.h"

#include <QString>
#include <QVector>

class IFTPK_EXPORT IFNPK
{
public:
    IFNPK();
    QString name;//音符名
    double AT=0;//开始位置
    double RT=1;//结束位置
    int NH=60;//音高
    QString DB0;//声库0
    QString ADB0;//子声库0
    QString DB1;//声库1
    QString ADB1;//子声库1
    QString CHA;//情绪名
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
private:

};

class IFTPK_EXPORT IFSPK
{
public:
    IFSPK();
    QString name;
    QVector<double> *data=new QVector<double>;
private:

};

class IFTPK_EXPORT IFTPK
{
public:
    IFTPK();
    int id;
    qint64 time;
    double tempo;
    int clamp;
    qint64 FS;

    QString audio_engine_add_information;
    QString synthesize_engine_add_information;

    QVector<double> *WavedataL=new QVector<double>;
    QVector<double> *WavedataR=new QVector<double>;


    int GetNoteFormSize();
    QString GetNotename(int index);
    double GetNoteAT(int index);
    double GetNoteRT(int index);
    int GetNoteNH(int index);
    QString GetNoteDB0(int index);
    QString GetNoteADB0(int index);
    QString GetNoteDB1(int index);
    QString GetNoteADB1(int index);
    QString GetNoteCHA(int index);
    QString GetNoteC(int index);
    QString GetNoteV1(int index);
    QString GetNoteV2(int index);
    QString GetNoteV3(int index);
    double GetNoteCP(int index);
    double GetNoteV1P(int index);
    double GetNoteV2P(int index);
    double GetNoteV3P(int index);
    double GetNoteP1(int index);
    double GetNoteP2(int index);

    QVector<double> *GetSetsByName(QString name);

    void AddNote(QString name,
                 double AT,
                 double RT,
                 int NH,
                 QString DB0,
                 QString ADB0,
                 QString DB1,
                 QString ADB1,
                 QString CHA,
                 QString C,
                 QString V1,
                 QString V2,
                 QString V3,
                 double CP,
                 double V1P,
                 double V2P,
                 double V3P,
                 double P1,
                 double P2);

    void AddSets(QString name,QVector<double> *data);

private:
    QVector<IFNPK *> *NoteForm=new QVector<IFNPK *>;
    QVector<IFSPK *> *SetsForm=new QVector<IFSPK *>;
};


#endif // IFTPK_H
