#ifndef SEGMODEL_H
#define SEGMODEL_H

#include "SEGModel_global.h"
#include <QThread>
#include <QObject>
#include <QDateTime>
//#include <QApplication>

class SEGMODEL_EXPORT SEGModel:public QThread
{
    Q_OBJECT
public:
    SEGModel();
    void run() Q_DECL_OVERRIDE;
    double percent=0;
    int trackid;
    double time;
    double tempo;
    int clamp;
    int FS;
    QString AIN;
};

extern "C" SEGMODEL_EXPORT QObject *Prepare();
extern "C" SEGMODEL_EXPORT void Run(QObject *SMC,int trackid,double time,double tempo,int clamp,int FS,QString AIN);
extern "C" SEGMODEL_EXPORT double Get(QObject *SMC);
extern "C" SEGMODEL_EXPORT bool Check(QObject *SMC);
extern "C" SEGMODEL_EXPORT void Stop(QObject *SMC);
extern "C" SEGMODEL_EXPORT void Clear(QObject *SMC);

#endif // SEGMODEL_H
