#include "percentbackend.h"

percentbackend::percentbackend(QObject *parent) : QThread(parent)
{

}

void percentbackend::run()
{
    if(segptr!=nullptr&&library!=nullptr){
        GetFunction Get=(GetFunction)library->resolve("Get");
        CheckFunction Check=(CheckFunction)library->resolve("Check");
        while(1){
            double temp=Get(segptr);
            if(temp!=percent){
                percent=temp;
                emit percentchanged(percent);
            }
            if(!Check(segptr)){
                emit segfinished();
                break;
            }
        }

    }
    quit();
}
