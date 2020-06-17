#include "qifproject.h"


QIFproject::QIFproject()
{
    Mastertrack->name="Master";
    Mastertrack->mastertrack=true;
    QIFtrack *wavetrack=new QIFtrack;
    wavetrack->wavetrack=true;
    wavetrack->select=true;
    tracklist->append(wavetrack);
    QIFtrack *track1=new QIFtrack;
    track1->select=true;
    track1->name="Track1";
    tracklist->append(track1);
    tracklist->at(1)->wavesf->at(0)->data->fill(-7,((double)(time+1))*1000);
    tracklist->at(1)->wavesf->at(1)->data->fill(0,((double)(time+1))*1000);
    tracklist->at(1)->wavesf->at(2)->data->fill(0,((double)(time+1))*1000);
    tracklist->at(0)->effects->at(0)->Mix->fill(1,((double)(time+1))*1000);
    tracklist->at(0)->effects->at(0)->data->at(0)->data->fill(0,((double)(time+1))*1000);
    tracklist->at(0)->effects->at(0)->data->at(1)->data->fill(0,((double)(time+1))*1000);
    tracklist->at(1)->effects->at(0)->Mix->fill(1,((double)(time+1))*1000);
    tracklist->at(1)->effects->at(0)->data->at(0)->data->fill(0,((double)(time+1))*1000);
    tracklist->at(1)->effects->at(0)->data->at(1)->data->fill(0,((double)(time+1))*1000);
    Mastertrack->effects->at(0)->Mix->fill(1,((double)(time+1))*1000);
    Mastertrack->effects->at(0)->data->at(0)->data->fill(0,((double)(time+1))*1000);
    Mastertrack->effects->at(0)->data->at(1)->data->fill(0,((double)(time+1))*1000);
    //test
    //QIFnote *notetest=new QIFnote;
    //tracklist->at(1)->notef->append(notetest);
    //test
}

void QIFproject::settime(int time)
{

    if(QIFproject::time>time){
        for(int i=1;i<tracklist->size();i++){
            tracklist->at(i)->wavesf->at(0)->data->resize(((double)(time+1))*1000);
            tracklist->at(i)->wavesf->at(1)->data->resize(((double)(time+1))*1000);
            tracklist->at(i)->wavesf->at(2)->data->resize(((double)(time+1))*1000);
            tracklist->at(i)->effects->at(0)->Mix->resize(((double)(time+1))*1000);
            tracklist->at(i)->effects->at(0)->data->at(0)->data->resize(((double)(time+1))*1000);
            tracklist->at(i)->effects->at(0)->data->at(1)->data->resize(((double)(time+1))*1000);
        }

        tracklist->at(0)->effects->at(0)->Mix->resize(((double)(time+1))*1000);
        tracklist->at(0)->effects->at(0)->data->at(0)->data->resize(((double)(time+1))*1000);
        tracklist->at(0)->effects->at(0)->data->at(1)->data->resize(((double)(time+1))*1000);

        Mastertrack->effects->at(0)->Mix->resize(((double)(time+1))*1000);
        Mastertrack->effects->at(0)->data->at(0)->data->resize(((double)(time+1))*1000);
        Mastertrack->effects->at(0)->data->at(1)->data->resize(((double)(time+1))*1000);
    }
    else{
        for(int i=1;i<tracklist->size();i++){
            tracklist->at(i)->wavesf->at(0)->data->insert(tracklist->at(i)->wavesf->at(0)->data->size(),((double)(time+1))*1000-((double)(QIFproject::time+1))*1000,-7);
            tracklist->at(i)->wavesf->at(1)->data->insert(tracklist->at(i)->wavesf->at(1)->data->size(),((double)(time+1))*1000-((double)(QIFproject::time+1))*1000,0);
            tracklist->at(i)->wavesf->at(2)->data->insert(tracklist->at(i)->wavesf->at(2)->data->size(),((double)(time+1))*1000-((double)(QIFproject::time+1))*1000,0);
            tracklist->at(i)->effects->at(0)->Mix->insert(tracklist->at(i)->effects->at(0)->Mix->size(),((double)(time+1))*1000-((double)(QIFproject::time+1))*1000,1);
            tracklist->at(i)->effects->at(0)->data->at(0)->data->insert(tracklist->at(i)->effects->at(0)->data->at(0)->data->size(),((double)(time+1))*1000-((double)(QIFproject::time+1))*1000,0);
            tracklist->at(i)->effects->at(0)->data->at(1)->data->insert(tracklist->at(i)->effects->at(0)->data->at(1)->data->size(),((double)(time+1))*1000-((double)(QIFproject::time+1))*1000,0);
        }

        tracklist->at(0)->effects->at(0)->Mix->insert(tracklist->at(0)->effects->at(0)->Mix->size(),((double)(time+1))*1000-((double)(QIFproject::time+1))*1000,1);
        tracklist->at(0)->effects->at(0)->data->at(0)->data->insert(tracklist->at(0)->effects->at(0)->data->at(0)->data->size(),((double)(time+1))*1000-((double)(QIFproject::time+1))*1000,0);
        tracklist->at(0)->effects->at(0)->data->at(1)->data->insert(tracklist->at(0)->effects->at(0)->data->at(1)->data->size(),((double)(time+1))*1000-((double)(QIFproject::time+1))*1000,0);

        Mastertrack->effects->at(0)->Mix->insert(Mastertrack->effects->at(0)->Mix->size(),((double)(time+1))*1000-((double)(QIFproject::time+1))*1000,1);
        Mastertrack->effects->at(0)->data->at(0)->data->insert(Mastertrack->effects->at(0)->data->at(0)->data->size(),((double)(time+1))*1000-((double)(QIFproject::time+1))*1000,0);
        Mastertrack->effects->at(0)->data->at(1)->data->insert(Mastertrack->effects->at(0)->data->at(1)->data->size(),((double)(time+1))*1000-((double)(QIFproject::time+1))*1000,0);
    }
    QIFproject::time=time;
    for(int i=0;i<tracklist->size();i++){
        tracklist->at(i)->time=time;
    }
    saved=false;

}

void QIFproject::settempo(double tempo)
{


    QIFproject::tempo=tempo;
    for(int i=0;i<tracklist->size();i++){
        tracklist->at(i)->tempo=tempo;
    }
    saved=false;
}

void QIFproject::addtrack()
{
    QIFtrack *track=new QIFtrack;
    QString idtemp;
    idtemp.number(tracklist->size());
    track->name="Track"+idtemp;
    track->time=time;
    track->tempo=tempo;
    track->clamp=clamp;
    track->FS=FS;
    track->wavesf->at(0)->data->fill(-7,((double)(time+1))*1000);
    track->wavesf->at(1)->data->fill(0,((double)(time+1))*1000);
    track->wavesf->at(2)->data->fill(0,((double)(time+1))*1000);
    track->effects->at(0)->Mix->fill(1,((double)(time+1))*1000);
    track->effects->at(0)->data->at(0)->data->fill(0,((double)(time+1))*1000);
    track->effects->at(0)->data->at(1)->data->fill(0,((double)(time+1))*1000);
    tracklist->append(track);
}

void QIFproject::settrack(int track)
{
    for(int i=1;i<tracklist->size();i++){
        if(tracklist->at(i)->select){
            tracklist->at(i)->select=false;
        }
    }
    tracklist->at(track)->select=true;
}

void QIFproject::deletetrack(int track)
{
    if(track<tracklist->size()){
        if(tracklist->size()==2){
            QMessageBox::warning(nullptr,"出错","只有一轨",QMessageBox::Ok,QMessageBox::Ok);
        }
        else{
            for(int i=0;i<tracklist->at(track)->notef->size();i++){
                delete tracklist->at(track)->notef->at(i);
            }
            tracklist->at(track)->notef->clear();
            for(int i=0;i<tracklist->at(track)->flatsf->size();i++){
                tracklist->at(track)->flatsf->at(i)->data->clear();
                delete tracklist->at(track)->flatsf->at(i);
            }
            tracklist->at(track)->flatsf->clear();
            for(int i=0;i<tracklist->at(track)->wavesf->size();i++){
                tracklist->at(track)->wavesf->at(i)->data->clear();
                delete tracklist->at(track)->wavesf->at(i);
            }
            tracklist->at(track)->wavesf->clear();
            for(int i=0;i<tracklist->at(track)->dictionary->size();i++){
                delete tracklist->at(track)->dictionary->at(i);
            }
            tracklist->at(track)->dictionary->clear();
            for(int i=0;i<tracklist->at(track)->effects->size();i++){
                tracklist->at(track)->effects->at(i)->Mix->clear();
                for(int j=0;j<tracklist->at(track)->effects->at(i)->data->size();j++){
                    tracklist->at(track)->effects->at(i)->data->at(j)->data->clear();
                    delete tracklist->at(track)->effects->at(i)->data->at(j);
                }
                tracklist->at(track)->effects->at(i)->data->clear();
                delete tracklist->at(track)->effects->at(i);
            }
            tracklist->at(track)->effects->clear();
            delete tracklist->at(track);
            tracklist->remove(track);
            if(track>1){
                for(int i=1;i<tracklist->size();i++){
                    tracklist->at(i)->select=false;
                }
                tracklist->at(track-1)->select=true;
            }
            else{
                for(int i=1;i<tracklist->size();i++){
                    tracklist->at(i)->select=false;
                }
                tracklist->at(1)->select=true;
            }
        }
    }

}

void QIFproject::setclamp(int clamp)
{


    QIFproject::clamp=clamp;
    for(int i=0;i<tracklist->size();i++){
        tracklist->at(i)->clamp=clamp;
    }
    saved=false;

}
