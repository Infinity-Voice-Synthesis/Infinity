#include "aegmodel.h"

AEGModel::AEGModel()
{
}

void AEGModel::run()
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
    AEGModel *AM=new AEGModel;
    return (QObject *)AM;
}

void Run(QObject *AMC,int tracks,double time,int FS,QString AIN)
{
    AEGModel *AM=(AEGModel *)AMC;
    AM->tracks=tracks;
    AM->time=time;
    AM->FS=FS;
    AM->AIN=AIN;
    AM->start();
}

double Get(QObject *AMC)
{
    AEGModel *AM=(AEGModel *)AMC;
    if(AM->isRunning()){
        return AM->percent;
    }
    else{
        return 0;
    }
}

void Stop(QObject *AMC)
{
    AEGModel *AM=(AEGModel *)AMC;
    if(AM->isRunning()){
        AM->quit();
        AM->percent=0;
    }
}

void Clear(QObject *AMC)
{
    AEGModel *AM=(AEGModel *)AMC;
    delete AM;
}

bool Check(QObject *AMC)
{
    AEGModel *AM=(AEGModel *)AMC;
    if(AM->isRunning()){
        return true;
    }
    else{
        return false;
    }
}
