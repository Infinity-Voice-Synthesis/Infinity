#include "ifsce.h"

IFSCE::IFSCE()
{
}

bool IFSCE::WriteSCache(int trackid,QString name,QVector<double> *data)
{
    QString trackids;
    trackids.number(trackid);
    QString filename="./forms/"+trackids+"/"+name+".iftf";
    QFile file(filename);
    if(!file.open(QIODevice::ReadWrite|QIODevice::Truncate)){
        return false;
    }
    QDataStream stream(&file);
#if Q_BYTE_ORDER == Q_LITTLE_ENDIAN
    stream.setByteOrder(QDataStream::LittleEndian);
#else
    stream.setByteOrder(QDataStream::BigEndian);
#endif
    for(int i=0;i<data->size();i++){
        stream.writeRawData((char *)&(data->at(i)),sizeof(double));
    }
    file.close();
    return true;
}

bool IFSCE::ReadSCache(int trackid,QString name,QVector<double> *data)
{
    QString trackids;
    trackids.number(trackid);
    QString filename="./forms/"+trackids+"/"+name+".iftf";
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly)){
        return false;
    }
    QDataStream stream(&file);
#if Q_BYTE_ORDER == Q_LITTLE_ENDIAN
    stream.setByteOrder(QDataStream::LittleEndian);
#else
    stream.setByteOrder(QDataStream::BigEndian);
#endif
    data->clear();
    for(int i=0;i<file.size()/sizeof(double);i++){
        double t=0;
        stream.readRawData((char *)&t,sizeof(double));
        data->append(t);
    }
    file.close();
    return true;
}

bool IFSCE::WriteACache(int trackid,QString effname,QString name,QVector<double> *data)
{
    QString trackids;
    trackids.number(trackid);
    QString filename="./forms/"+trackids+"/"+effname+"_"+name+".iftf";
    QFile file(filename);
    if(!file.open(QIODevice::ReadWrite|QIODevice::Truncate)){
        return false;
    }
    QDataStream stream(&file);
#if Q_BYTE_ORDER == Q_LITTLE_ENDIAN
    stream.setByteOrder(QDataStream::LittleEndian);
#else
    stream.setByteOrder(QDataStream::BigEndian);
#endif
    for(int i=0;i<data->size();i++){
        stream.writeRawData((char *)&(data->at(i)),sizeof(double));
    }
    file.close();
    return true;
}

bool IFSCE::ReadACache(int trackid,QString effname,QString name,QVector<double> *data)
{
    QString trackids;
    trackids.number(trackid);
    QString filename="./forms/"+trackids+"/"+effname+"_"+name+".iftf";
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly)){
        return false;
    }
    QDataStream stream(&file);
#if Q_BYTE_ORDER == Q_LITTLE_ENDIAN
    stream.setByteOrder(QDataStream::LittleEndian);
#else
    stream.setByteOrder(QDataStream::BigEndian);
#endif
    data->clear();
    for(int i=0;i<file.size()/sizeof(double);i++){
        double t=0;
        stream.readRawData((char *)&t,sizeof(double));
        data->append(t);
    }
    file.close();
    return true;
}

bool IFSCE::WriteNCache(int trackid,QVector<QIFnote *> *data)
{
    QString trackids;
    trackids.number(trackid);
    QString filename="./forms/"+trackids+"/notes.iftnf";
    QFile file(filename);
    if(!file.open(QIODevice::ReadWrite|QIODevice::Truncate)){
        return false;
    }
    QDataStream stream(&file);
#if Q_BYTE_ORDER == Q_LITTLE_ENDIAN
    stream.setByteOrder(QDataStream::LittleEndian);
#else
    stream.setByteOrder(QDataStream::BigEndian);
#endif
    for(int i=0;i<data->size();i++){
        QByteArray bytearray;
        bytearray=data->at(i)->name.toUtf8();
        stream.writeBytes(bytearray,bytearray.length());
        stream.writeRawData((char *)&(data->at(i)->AT),sizeof(double));
        stream.writeRawData((char *)&(data->at(i)->RT),sizeof(double));
        stream.writeRawData((char *)&(data->at(i)->NH),sizeof(int));
        bytearray=data->at(i)->DB0.toUtf8();
        stream.writeBytes(bytearray,bytearray.length());
        bytearray=data->at(i)->ADB0.toUtf8();
        stream.writeBytes(bytearray,bytearray.length());
        bytearray=data->at(i)->DB1.toUtf8();
        stream.writeBytes(bytearray,bytearray.length());
        bytearray=data->at(i)->ADB1.toUtf8();
        stream.writeBytes(bytearray,bytearray.length());
        bytearray=data->at(i)->CHA.toUtf8();
        stream.writeBytes(bytearray,bytearray.length());
        stream.writeRawData((char *)&(data->at(i)->mute),sizeof(bool));
        bytearray=data->at(i)->C.toUtf8();
        stream.writeBytes(bytearray,bytearray.length());
        bytearray=data->at(i)->V1.toUtf8();
        stream.writeBytes(bytearray,bytearray.length());
        bytearray=data->at(i)->V2.toUtf8();
        stream.writeBytes(bytearray,bytearray.length());
        bytearray=data->at(i)->V3.toUtf8();
        stream.writeBytes(bytearray,bytearray.length());
        stream.writeRawData((char *)&(data->at(i)->CP),sizeof(double));
        stream.writeRawData((char *)&(data->at(i)->V1P),sizeof(double));
        stream.writeRawData((char *)&(data->at(i)->V2P),sizeof(double));
        stream.writeRawData((char *)&(data->at(i)->V3P),sizeof(double));
        stream.writeRawData((char *)&(data->at(i)->P1),sizeof(double));
        stream.writeRawData((char *)&(data->at(i)->P2),sizeof(double));
        stream.writeRawData((char *)&(data->at(i)->SP),sizeof(double));
        stream.writeRawData((char *)&(data->at(i)->SH),sizeof(double));
        stream.writeRawData((char *)&(data->at(i)->SV),sizeof(double));
    }
    file.close();
    return true;
}

bool IFSCE::ReadNCache(int trackid,QVector<QIFnote *> *data)
{
    QString trackids;
    trackids.number(trackid);
    QString filename="./forms/"+trackids+"/notes.iftnf";
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly)){
        return false;
    }
    QDataStream stream(&file);
#if Q_BYTE_ORDER == Q_LITTLE_ENDIAN
    stream.setByteOrder(QDataStream::LittleEndian);
#else
    stream.setByteOrder(QDataStream::BigEndian);
#endif
    for(int i=0;i<data->size();i++){
        delete data->at(i);
    }
    data->clear();
    for(int i=0;!file.atEnd();i++){
        QIFnote *note=new QIFnote;
        char *buf;
        uint len=0;
        stream.readBytes(buf,len);
        note->name=QString::fromLocal8Bit(buf,len);
        stream.readRawData((char *)&(note->AT),sizeof(double));
        stream.readRawData((char *)&(note->RT),sizeof(double));
        stream.readRawData((char *)&(note->NH),sizeof(int));
        stream.readBytes(buf,len);
        note->DB0=QString::fromLocal8Bit(buf,len);
        stream.readBytes(buf,len);
        note->ADB0=QString::fromLocal8Bit(buf,len);
        stream.readBytes(buf,len);
        note->DB1=QString::fromLocal8Bit(buf,len);
        stream.readBytes(buf,len);
        note->ADB1=QString::fromLocal8Bit(buf,len);
        stream.readBytes(buf,len);
        note->CHA=QString::fromLocal8Bit(buf,len);
        stream.readRawData((char *)&(note->mute),sizeof(bool));
        stream.readBytes(buf,len);
        note->C=QString::fromLocal8Bit(buf,len);
        stream.readBytes(buf,len);
        note->V1=QString::fromLocal8Bit(buf,len);
        stream.readBytes(buf,len);
        note->V2=QString::fromLocal8Bit(buf,len);
        stream.readBytes(buf,len);
        note->V3=QString::fromLocal8Bit(buf,len);
        stream.readRawData((char *)&(note->CP),sizeof(double));
        stream.readRawData((char *)&(note->V1P),sizeof(double));
        stream.readRawData((char *)&(note->V2P),sizeof(double));
        stream.readRawData((char *)&(note->V3P),sizeof(double));
        stream.readRawData((char *)&(note->P1),sizeof(double));
        stream.readRawData((char *)&(note->P2),sizeof(double));
        stream.readRawData((char *)&(note->SP),sizeof(double));
        stream.readRawData((char *)&(note->SH),sizeof(double));
        stream.readRawData((char *)&(note->SV),sizeof(double));
        data->append(note);
    }
    file.close();
    return true;
}
