#include "qifnote.h"

QIFnote::QIFnote()
{

}

void QIFnote::solvedic(QVector<QIFdic *> *dic)
{
    C="";
    V1="a";
    V2="";
    V3="";
    CP=0;
    V1P=0;
    V2P=1;
    V3P=1;
    P1=0.2;
    P2=0.8;
    for(int i=0;i<dic->size();i++){
        if(dic->at(i)->name==name){
            C=dic->at(i)->C;
            V1=dic->at(i)->V1;
            V2=dic->at(i)->V2;
            V3=dic->at(i)->V3;
            CP=dic->at(i)->CP;
            V1P=dic->at(i)->V1P;
            V2P=dic->at(i)->V2P;
            V3P=dic->at(i)->V3P;
            P1=dic->at(i)->P1;
            P2=dic->at(i)->P2;
        }
    }
}
