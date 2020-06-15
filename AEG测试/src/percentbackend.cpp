#include "percentbackend.h"

percentbackend::percentbackend(QObject *parent) : QThread(parent)
{

}

void percentbackend::run()
{
    if(aegptr!=nullptr&&library!=nullptr){
        GetFunction Get=(GetFunction)library->resolve("Get");
        CheckFunction Check=(CheckFunction)library->resolve("Check");
        while(1){
            double temp=Get(aegptr);
            if(temp!=percent){
                percent=temp;
                emit percentchanged(percent);
            }
            if(!Check(aegptr)){
                emit aegfinished();
                break;
            }
        }

    }
    quit();
}
