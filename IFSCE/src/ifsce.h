#ifndef IFSCE_H
#define IFSCE_H

#include "IFSCE_global.h"
#include <QVector>
#include <QString>
#include "qifnote.h"
#include <QFile>
#include <QDataStream>

class IFSCE_EXPORT IFSCE
{
public:
    IFSCE();
    static bool WriteSCache(int trackid,QString name,QVector<double> *data);
    static bool ReadSCache(int trackid,QString name,QVector<double> *data);
    static bool WriteACache(int trackid,QString effname,QString name,QVector<double> *data);
    static bool ReadACache(int trackid,QString effname,QString name,QVector<double> *data);
    static bool WriteNCache(int trackid,QVector<QIFnote *> *data);
    static bool ReadNCache(int trackid,QVector<QIFnote *> *data);
};

#endif // IFSCE_H
