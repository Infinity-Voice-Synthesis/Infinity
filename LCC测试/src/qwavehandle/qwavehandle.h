#ifndef QWAVEHANDLE_H
#define QWAVEHANDLE_H

#include <QObject>
#include <QFile>
#include <QDataStream>
#include <QMessageBox>
#include <QDialog>



class QWaveHandle:public QObject
{
    Q_OBJECT
public:
    QWaveHandle(QObject *parent=nullptr);
    ~QWaveHandle();
    char szRIFFID[4];
    qint32 uiRIFFsize;
    char szRIFFformat[4];
    char formatID[4];
    qint32 formatsize;
    qint16 formattag;
    qint16 channels;
    qint32 samplespersec=44100;
    qint32 avgbytespersec;
    qint16 blockalign;
    qint16 bitspersample;
    char dataID[4];
    qint32 datasize;
    QVector<qreal> *wavedataL=new QVector<qreal>;
    QVector<qreal> *wavedataR=new QVector<qreal>;
    ulong datalength;
    bool ReadFile(QString Filename);
    bool WriteFile(QString Filename);
    void clear();


private:
};

#endif // QWAVEHANDLE_H
