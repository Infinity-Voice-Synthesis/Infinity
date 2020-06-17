#ifndef IFLAN_H
#define IFLAN_H

#include <QString>

class iflan
{
public:
    iflan(QString name);
    iflan & operator=(QString input);
    iflan & operator=(iflan input);
    bool operator==(QString input);
    bool operator==(iflan input);
    QString value();
    QString name;
private:

};

#endif // IFLAN_H
