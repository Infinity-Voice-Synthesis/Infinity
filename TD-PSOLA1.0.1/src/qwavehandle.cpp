#include "qwavehandle.h"



QWaveHandle::QWaveHandle(QObject *parent) : QObject(parent)
{

}



QWaveHandle::~QWaveHandle()
{

}

bool QWaveHandle::ReadFile(QString Filename)
{
    if(Filename.isEmpty())
    {
        QMessageBox::warning(NULL,tr("出错！"),tr("文件名为空！"));
        return false;
    }
    QFile file(Filename);
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(NULL,tr("出错！"),tr("打开文件：")+Filename+tr("失败！"));
        file.close();
        return false;
    }
    QDataStream stream(&file);
    stream.setByteOrder(QDataStream::LittleEndian);

    stream.readRawData((char *)&szRIFFID,4);
    if(!((szRIFFID[0]=='R')&&(szRIFFID[1]=='I')&&(szRIFFID[2]=='F')&&(szRIFFID[3]=='F')))
    {
        QMessageBox::warning(NULL,tr("出错！"),Filename+tr("是一个")+szRIFFID+tr("文件，不是一个RIFF文件！"));
        file.close();
        return false;
    }
    stream.readRawData((char *)&uiRIFFsize,4);
    stream.readRawData((char *)&szRIFFformat,4);
    if(!(szRIFFformat[0]=='W'&&szRIFFformat[1]=='A'&&szRIFFformat[2]=='V'&&szRIFFformat[3]=='E'))//
    {
        QMessageBox::warning(NULL,tr("出错！"),Filename+tr("是一个")+szRIFFformat+tr("文件，不是一个WAVE文件！"));
        file.close();
        return false;
    }
    stream.readRawData((char *)&formatID,4);
    if(!((formatID[0]=='f')&&(formatID[1]=='m')&&(formatID[2]=='t')&&(formatID[3]==0x20)))
    {
        QMessageBox::warning(NULL,tr("出错！"),Filename+tr("有一个")+formatID+tr("块，没有fmt块！"));
        file.close();
        return false;
    }
    stream.readRawData((char *)&formatsize,4);
    stream.readRawData((char *)&formattag,2);
    stream.readRawData((char *)&channels,2);
    stream.readRawData((char *)&samplespersec,4);
    stream.readRawData((char *)&avgbytespersec,4);
    stream.readRawData((char *)&blockalign,2);
    stream.readRawData((char *)&bitspersample,2);
    if(formatsize==18)
    {
        stream.readRawData((char *)NULL,2);
    }
    stream.readRawData((char *)&dataID,4);
    if(!((dataID[0]=='d')&&(dataID[1]=='a')&&(dataID[2]=='t')&&(dataID[3]=='a')))
    {
        QMessageBox::warning(NULL,tr("出错！"),Filename+tr("有一个")+dataID+tr("块，没有data块！"));
        file.close();
        return false;
    }
    stream.readRawData((char *)&datasize,4);
    if(bitspersample==16)
    {
        if(channels==1){
            qint16 temp;
            datalength=datasize/2;
            for(ulong i=0;i<=datalength;i++){
                stream.readRawData((char *)&temp,2);
                wavedataL->append((qreal)temp/32768);
            }
        }
        else if(channels==2){
            qint16 temp;
            datalength=datasize/2/2;
            for(ulong i=0;i<=datalength;i++){
                stream.readRawData((char *)&temp,2);
                wavedataL->append((qreal)temp/32768);
                stream.readRawData((char *)&temp,2);
                wavedataR->append((qreal)temp/32768);
            }
        }
        else
        {
            QMessageBox::warning(NULL,tr("出错！"),Filename+tr("不支持的轨道数！"));
            file.close();
            return false;
        }

    }
    else if(bitspersample==8)
    {
        if(channels==1){
            qint8 temp;
            datalength=datasize/1;
            for(ulong i=0;i<=datalength;i++){
                stream.readRawData((char *)&temp,1);
                wavedataL->append((qreal)temp/128);
            }
        }
        else if(channels==2)
        {
            qint8 temp;
            datalength=datasize/1/2;
            for(ulong i=0;i<=datalength;i++){
                stream.readRawData((char *)&temp,1);
                wavedataL->append((qreal)temp/128);
                stream.readRawData((char *)&temp,1);
                wavedataR->append((qreal)temp/128);
            }
        }
        else
        {
            QMessageBox::warning(NULL,tr("出错！"),Filename+tr("不支持的轨道数！"));
            file.close();
            return false;
        }
    }
    else
    {
        QMessageBox::warning(NULL,tr("出错！"),Filename+tr("比特数未知！"));
        file.close();
        return false;
    }
    file.close();
    return true;
}

void QWaveHandle::clear()
{
    wavedataL->clear();
    wavedataR->clear();
}

bool QWaveHandle::WriteFile(QString Filename)
{
    if(Filename.isEmpty())
    {
        QMessageBox::warning(NULL,tr("出错！"),tr("文件名为空！"));
        return false;
    }

    if(QFile::exists(Filename))
    {
        QFile::remove(Filename);
    }
    QFile file(Filename);
    if(!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::warning(NULL,tr("出错！"),tr("打开文件：")+Filename+tr("失败！"));
        file.close();
        return false;
    }
    QDataStream stream(&file);
    stream.setByteOrder(QDataStream::LittleEndian);
    szRIFFID[0]='R';
    szRIFFID[1]='I';
    szRIFFID[2]='F';
    szRIFFID[3]='F';
    szRIFFformat[0]='W';
    szRIFFformat[1]='A';
    szRIFFformat[2]='V';
    szRIFFformat[3]='E';
    formatID[0]='f';
    formatID[1]='m';
    formatID[2]='t';
    formatID[3]=0x20;
    formatsize=16;
    formattag=1;
    if(!wavedataR->isEmpty())
    {
        channels=2;
    }
    else
    {
        channels=1;
    }
    bitspersample=16;
    avgbytespersec=(samplespersec*bitspersample*channels)/8;
    blockalign=(bitspersample*channels)/8;
    dataID[0]='d';
    dataID[1]='a';
    dataID[2]='t';
    dataID[3]='a';
    datasize=(wavedataL->size()+wavedataR->size())*(bitspersample/8);
    uiRIFFsize=datasize+36;
    stream.writeRawData((char *)&szRIFFID,4);
    stream.writeRawData((char *)&uiRIFFsize,4);
    stream.writeRawData((char *)&szRIFFformat,4);
    stream.writeRawData((char *)&formatID,4);
    stream.writeRawData((char *)&formatsize,4);
    stream.writeRawData((char *)&formattag,2);
    stream.writeRawData((char *)&channels,2);
    stream.writeRawData((char *)&samplespersec,4);
    stream.writeRawData((char *)&avgbytespersec,4);
    stream.writeRawData((char *)&blockalign,2);
    stream.writeRawData((char *)&bitspersample,2);
    stream.writeRawData((char *)&dataID,4);
    stream.writeRawData((char *)&datasize,4);
    if(bitspersample==16)
    {
        if(channels==1){
            qint16 temp;
            datalength=wavedataL->size();
            for(ulong i=0;i<datalength;i++){
                temp=wavedataL->at(i)*32768;
                stream.writeRawData((char *)&temp,2);
            }
        }
        else if(channels==2){
            qint16 temp;
            datalength=wavedataL->size();
            for(ulong i=0;i<datalength;i++){
                temp=wavedataL->at(i)*32768;
                stream.writeRawData((char *)&temp,2);
                temp=wavedataR->at(i)*32768;
                stream.writeRawData((char *)&temp,2);
            }
        }
        else
        {
            QMessageBox::warning(NULL,tr("出错！"),Filename+tr("不支持的轨道数！"));
            file.close();
            return false;
        }

    }
    else if(bitspersample==8)
    {
        if(channels==1){
            qint8 temp;
            datalength=wavedataL->size();
            for(ulong i=0;i<datalength;i++){
                temp=wavedataL->at(i)*128;
                stream.writeRawData((char *)&temp,1);
            }
        }
        else if(channels==2)
        {
            qint8 temp;
            datalength=wavedataL->size();
            for(ulong i=0;i<datalength;i++){
                temp=wavedataL->at(i)*128;
                stream.writeRawData((char *)&temp,1);
                temp=wavedataR->at(i)*128;
                stream.writeRawData((char *)&temp,1);
            }
        }
        else
        {
            QMessageBox::warning(NULL,tr("出错！"),Filename+tr("不支持的轨道数！"));
            file.close();
            return false;
        }
    }
    else
    {
        QMessageBox::warning(NULL,tr("出错！"),Filename+tr("比特数未知！"));
        file.close();
        return false;
    }
    file.close();
    return true;
}
