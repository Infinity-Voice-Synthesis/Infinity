#include "iftpk.h"

IFTPK::IFTPK()
{
}

IFSPK::IFSPK()
{

}

IFNPK::IFNPK()
{

}

int IFTPK::GetNoteFormSize()
{
    return NoteForm->size();
}

QString IFTPK::GetNotename(int index)
{
    if((index>=0)&&(index<NoteForm->size())){
        return NoteForm->at(index)->name;
    }else{
        return "";
    }
}

double IFTPK::GetNoteAT(int index)
{
    if((index>=0)&&(index<NoteForm->size())){
        return NoteForm->at(index)->AT;
    }else{
        return 0;
    }
}

double IFTPK::GetNoteRT(int index)
{
    if((index>=0)&&(index<NoteForm->size())){
        return NoteForm->at(index)->RT;
    }else{
        return 0;
    }
}

int IFTPK::GetNoteNH(int index)
{
    if((index>=0)&&(index<NoteForm->size())){
        return NoteForm->at(index)->NH;
    }else{
        return 0;
    }
}

QString IFTPK::GetNoteDB0(int index)
{
    if((index>=0)&&(index<NoteForm->size())){
        return NoteForm->at(index)->DB0;
    }else{
        return "";
    }
}

QString IFTPK::GetNoteADB0(int index)
{
    if((index>=0)&&(index<NoteForm->size())){
        return NoteForm->at(index)->ADB0;
    }else{
        return "";
    }
}

QString IFTPK::GetNoteDB1(int index)
{
    if((index>=0)&&(index<NoteForm->size())){
        return NoteForm->at(index)->DB1;
    }else{
        return "";
    }
}

QString IFTPK::GetNoteADB1(int index)
{
    if((index>=0)&&(index<NoteForm->size())){
        return NoteForm->at(index)->ADB1;
    }else{
        return "";
    }
}

QString IFTPK::GetNoteCHA(int index)
{
    if((index>=0)&&(index<NoteForm->size())){
        return NoteForm->at(index)->CHA;
    }else{
        return "";
    }
}

QString IFTPK::GetNoteC(int index)
{
    if((index>=0)&&(index<NoteForm->size())){
        return NoteForm->at(index)->C;
    }else{
        return "";
    }
}

QString IFTPK::GetNoteV1(int index)
{
    if((index>=0)&&(index<NoteForm->size())){
        return NoteForm->at(index)->V1;
    }else{
        return "";
    }
}

QString IFTPK::GetNoteV2(int index)
{
    if((index>=0)&&(index<NoteForm->size())){
        return NoteForm->at(index)->V2;
    }else{
        return "";
    }
}

QString IFTPK::GetNoteV3(int index)
{
    if((index>=0)&&(index<NoteForm->size())){
        return NoteForm->at(index)->V3;
    }else{
        return "";
    }
}

double IFTPK::GetNoteCP(int index)
{
    if((index>=0)&&(index<NoteForm->size())){
        return NoteForm->at(index)->CP;
    }else{
        return 0;
    }
}

double IFTPK::GetNoteV1P(int index)
{
    if((index>=0)&&(index<NoteForm->size())){
        return NoteForm->at(index)->V1P;
    }else{
        return 0;
    }
}

double IFTPK::GetNoteV2P(int index)
{
    if((index>=0)&&(index<NoteForm->size())){
        return NoteForm->at(index)->V2P;
    }else{
        return 0;
    }
}

double IFTPK::GetNoteV3P(int index)
{
    if((index>=0)&&(index<NoteForm->size())){
        return NoteForm->at(index)->V3P;
    }else{
        return 0;
    }
}

double IFTPK::GetNoteP1(int index)
{
    if((index>=0)&&(index<NoteForm->size())){
        return NoteForm->at(index)->P1;
    }else{
        return 0;
    }
}

double IFTPK::GetNoteP2(int index)
{
    if((index>=0)&&(index<NoteForm->size())){
        return NoteForm->at(index)->P2;
    }else{
        return 0;
    }
}

QVector<double> *(IFTPK::GetSetsByName(QString name))
{
    QVector<double> *rp=nullptr;
    for(int i=0;i<SetsForm->size();i++){
        if(SetsForm->at(i)->name==name){
            rp=SetsForm->at(i)->data;
        }
    }
    return rp;
}

void IFTPK::AddNote(QString name,
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
                    double P2)
{
    ::IFNPK *np=new ::IFNPK;
    np->name=name;
    np->AT=AT;
    np->RT=RT;
    np->NH=NH;
    np->DB0=DB0;
    np->ADB0=ADB0;
    np->DB1=DB1;
    np->ADB1=ADB1;
    np->CHA=CHA;
    np->C=C;
    np->V1=V1;
    np->V2=V2;
    np->V3=V3;
    np->CP=CP;
    np->V1P=V1P;
    np->V2P=V2P;
    np->V3P=V3P;
    np->P1=P1;
    np->P2=P2;
    NoteForm->append(np);
}


void IFTPK::AddSets(QString name,QVector<double> *data)
{
    ::IFSPK *sp=new ::IFSPK;
    sp->name=name;
    for(int i=0;i<data->size();i++){
        sp->data->append(data->at(i));
    }
    SetsForm->append(sp);
}
