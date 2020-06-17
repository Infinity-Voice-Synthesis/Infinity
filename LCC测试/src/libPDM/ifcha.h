#ifndef IFCHA_H
#define IFCHA_H

#include <QString>

class ifcha
{
public:
    ifcha(QString name);
    ifcha & operator=(QString input);
    ifcha & operator=(ifcha input);
    bool operator==(QString input);
    bool operator==(ifcha input);
    QString value();
    QString name;
private:

};

#endif // IFCHA_H
