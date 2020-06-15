#include "qiftrack.h"


QIFtrack::QIFtrack()
{
    SS *tone=new SS;
    tone->name="TON";
    tone->minValue=-0.5;
    tone->maxValue=119.5;
    tone->normalValue=-13;
    tone->edit=true;
    tone->count=1;
    wavesf->append(tone);
    SS *PIT=new SS;
    PIT->name="PIT";
    PIT->minValue=-12;
    PIT->maxValue=12;
    PIT->normalValue=0;
    PIT->edit=false;
    wavesf->append(PIT);
    SS *XSY=new SS;
    XSY->name="XSY";
    XSY->minValue=0;
    XSY->maxValue=1;
    XSY->normalValue=0;
    wavesf->append(XSY);
    ES *trackbase=new ES;
    ESW *Gain=new ESW;
    ESW *Pan=new ESW;
    Gain->name="Gain";
    Gain->minValue=-10;
    Gain->maxValue=10;
    Gain->normalValue=0;
    Pan->name="Pan";
    Pan->minValue=-1;
    Pan->maxValue=1;
    Pan->normalValue=0;
    trackbase->name="Mixer";
    trackbase->data->append(Gain);
    trackbase->data->append(Pan);
    trackbase->select=true;
    effects->append(trackbase);
}

int QIFtrack::addnote(double AT,double RT,int NH)
{
    int id=0;
    if(notef->size()==0){
        id=0;
    }
    else{
        if(AT<notef->at(0)->AT){
            id=0;
        }
        for(int i=0;i<notef->size()-1;i++){
            if(AT>=notef->at(i)->AT&&AT<notef->at(i+1)->AT){
                id=i+1;
            }
        }
        if(AT>=notef->at(notef->size()-1)->AT){
            id=notef->size();
        }
    }
    QIFnote *note=new QIFnote;
    note->AT=AT;
    note->RT=RT;
    note->NH=NH;
    note->DB0=DB0;
    note->DB1=DB1;
    note->ADB0="";
    note->ADB1="";
    note->CHA="Normal";
    note->solvedic(dictionary);
    notef->insert(id,1,note);
    for(int i=0;i<flatsf->size();i++){
        flatsf->at(i)->data->insert(id,1,flatsf->at(i)->normalValue);
    }
    checknotemute();
    sloveTONbyPIT();
    return id;
}

void QIFtrack::checknotemute()
{
    for(int i=0;i<notef->size();i++){
        notef->at(i)->mute=false;
    }
    for(int i=0;i<notef->size()-1;i++){
        for(int j=i+1;j<notef->size();j++){
            if(notef->at(i)->RT>notef->at(j)->AT){
                notef->at(i)->mute=true;
                notef->at(j)->mute=true;
            }
        }

    }
}

int QIFtrack::movenote(int id,double AT,int NH)
{
    int idc=0;
    if(notef->size()==0){
        idc=0;
    }
    else{
        if(AT<notef->at(0)->AT){
            idc=0;
        }
        for(int i=0;i<notef->size()-1;i++){
            if(AT>=notef->at(i)->AT&&AT<notef->at(i+1)->AT){
                idc=i+1;
            }
        }
        if(AT>=notef->at(notef->size()-1)->AT){
            idc=notef->size();
        }
    }
    QIFnote *notetemp=notef->at(id);
    if(idc>id){
        notef->insert(idc,1,notetemp);
        for(int i=0;i<flatsf->size();i++){
            flatsf->at(i)->data->insert(idc,1,flatsf->at(i)->normalValue);
        }
        notef->remove(id);
        for(int i=0;i<flatsf->size();i++){
            flatsf->at(i)->data->remove(id);
        }
        idc=idc-1;
    }
    else if(idc<id){
        notef->insert(idc,1,notetemp);
        for(int i=0;i<flatsf->size();i++){
            flatsf->at(i)->data->insert(idc,1,flatsf->at(i)->normalValue);
        }
        notef->remove(id+1);
        for(int i=0;i<flatsf->size();i++){
            flatsf->at(i)->data->remove(id+1);
        }
    }
    else{

    }
    notetemp->RT=AT+(notetemp->RT-notetemp->AT);
    notetemp->AT=AT;
    notetemp->NH=NH;
    checknotemute();
    sloveTONbyPIT();
    return idc;
}

void QIFtrack::deletenote(int id)
{
    if(id<notef->size()){
        //qDebug("1");
        delete notef->at(id);
        //qDebug("2");
        notef->remove(id);
        for(int i=0;i<flatsf->size();i++){
            flatsf->at(i)->data->remove(id);
        }
        //qDebug("3");
    }
    checknotemute();
    sloveTONbyPIT();
    //qDebug("4");
}

void QIFtrack::setnoteRT(int id,double RT)
{
    if(id<notef->size()){
        notef->at(id)->RT=RT;
        checknotemute();
        sloveTONbyPIT();
    }
}

void QIFtrack::sloveTONbyPIT()
{
    for(int i=0;i<wavesf->at(0)->data->size();i++){
        wavesf->at(0)->data->replace(i,-13);
    }
    for(int i=0;i<notef->size();i++){
        if(!notef->at(i)->mute){
            for(int j=(double)((double)(notef->at(i)->AT))*1000;j<(double)((double)(notef->at(i)->RT)*1000);j++){
                if(j>=0&&j<wavesf->at(0)->data->size()){
                    wavesf->at(0)->data->replace(j,notef->at(i)->NH);
                }
            }
            for(int j=0;j<(double)((double)(1-notef->at(i)->SP)*(double)(notef->at(i)->RT-notef->at(i)->AT))*1000;j++){
                if(j>=0&&j<wavesf->at(0)->data->size()){
                    wavesf->at(0)->data->replace(j+(double)((double)(notef->at(i)->AT+(double)(notef->at(i)->SP)*(double)(notef->at(i)->RT-notef->at(i)->AT))*1000),notef->at(i)->NH+(notef->at(i)->SH*qSin(notef->at(i)->SV*j)));
                }

            }
        }


    }
    for(int i=0;i<wavesf->at(0)->data->size();i++){
        wavesf->at(0)->data->replace(i,wavesf->at(0)->data->at(i)+wavesf->at(1)->data->at(i));
    }
}

void QIFtrack::slovePITbyTON()
{
    for(int i=0;i<wavesf->at(1)->data->size();i++){
        wavesf->at(1)->data->replace(i,wavesf->at(0)->data->at(i)+13);
    }
    for(int i=0;i<notef->size();i++){
        if(!notef->at(i)->mute){
            for(int j=(double)((double)(notef->at(i)->AT)*1000);j<(double)((double)(notef->at(i)->RT)*1000);j++){
                if(j>=0&&j<wavesf->at(0)->data->size()){
                    wavesf->at(1)->data->replace(j,wavesf->at(0)->data->at(j));
                }
            }
            for(int j=0;j<(double)((double)(1-notef->at(i)->SP)*(double)(notef->at(i)->RT-notef->at(i)->AT))*1000;j++){
                if(j>=0&&j<wavesf->at(1)->data->size()){
                    wavesf->at(1)->data->replace(j+(double)((double)(notef->at(i)->AT+(double)(notef->at(i)->SP)*(double)(notef->at(i)->RT-notef->at(i)->AT))*1000),wavesf->at(1)->data->at(j+(double)((double)(notef->at(i)->AT+(double)(notef->at(i)->SP)*(double)(notef->at(i)->RT-notef->at(i)->AT)))*1000)-(notef->at(i)->SH*qSin(notef->at(i)->SV*j)));
                }

            }
            for(int j=(double)((double)(notef->at(i)->AT)*1000);j<(double)((double)(notef->at(i)->RT)*1000);j++){
                if(j>=0&&j<wavesf->at(1)->data->size()){
                    wavesf->at(1)->data->replace(j,wavesf->at(1)->data->at(j)-notef->at(i)->NH);
                }
            }
        }


    }
}
