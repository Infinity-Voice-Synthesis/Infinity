#include "ifcha.h"

ifcha::ifcha(QString name)
{
    ifcha::name=name;
}

ifcha & ifcha::operator=(QString input)
{
    name=input;
    return *this;
}

ifcha & ifcha::operator=(ifcha input)
{
    name=input.name;
    return *this;
}

bool ifcha::operator==(QString input)
{
    if(name==input){
        return true;
    }else{
        return false;
    }
}

bool ifcha::operator==(ifcha input)
{
    if(name==input.name){
        return true;
    }else{
        return false;
    }
}

QString ifcha::value()
{
    return name;
}
