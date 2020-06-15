#include "segmodel.h"

SEGModel::SEGModel()
{
}

void SEGModel::run()
{
    percent=0;
    //
    QDateTime n=QDateTime::currentDateTime();
    QDateTime now;
    do{
        now=QDateTime::currentDateTime();
        //QApplication::processEvents();
        percent=(double)((double)n.secsTo(now)/(double)10)*(double)100;
    } while (n.secsTo(now)<=10);
    //
    percent=100;
    quit();
}

QObject *Prepare()
{
    SEGModel *SM=new SEGModel;
    return (QObject *)SM;
}

void Run(QObject *SMC,int trackid,double time,double tempo,int clamp,int FS,QString AIN)
{
    SEGModel *SM=(SEGModel *)SMC;
    SM->trackid=trackid;
    SM->time=time;
    SM->tempo=tempo;
    SM->clamp=clamp;
    SM->FS=FS;
    SM->AIN=AIN;
    SM->start();
}

double Get(QObject *SMC)
{
    SEGModel *SM=(SEGModel *)SMC;
    if(SM->isRunning()){
        return SM->percent;
    }
    else{
        return 0;
    }
}

void Stop(QObject *SMC)
{
    SEGModel *SM=(SEGModel *)SMC;
    if(SM->isRunning()){
        SM->quit();
        SM->percent=0;
    }
}

void Clear(QObject *SMC)
{
    SEGModel *SM=(SEGModel *)SMC;
    delete SM;
}

bool Check(QObject *SMC)
{
    SEGModel *SM=(SEGModel *)SMC;
    if(SM->isRunning()){
        return true;
    }
    else{
        return false;
    }
}
