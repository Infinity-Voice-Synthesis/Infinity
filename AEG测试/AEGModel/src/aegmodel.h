#ifndef AEGMODEL_H
#define AEGMODEL_H

#include "AEGModel_global.h"
#include <QThread>
#include <QObject>
#include <QDateTime>
//#include <QApplication>

class AEGMODEL_EXPORT AEGModel:public QThread
{
    Q_OBJECT
public:
    AEGModel();
    void run() Q_DECL_OVERRIDE;
    double percent=0;
    int tracks;
    double time;
    int FS;
    QString AIN;
};

extern "C" AEGMODEL_EXPORT QObject *Prepare();
extern "C" AEGMODEL_EXPORT void Run(QObject *AMC,int tracks,double time,int FS,QString AIN);
extern "C" AEGMODEL_EXPORT double Get(QObject *AMC);
extern "C" AEGMODEL_EXPORT bool Check(QObject *AMC);
extern "C" AEGMODEL_EXPORT void Stop(QObject *AMC);
extern "C" AEGMODEL_EXPORT void Clear(QObject *AMC);

#endif // AEGMODEL_H
