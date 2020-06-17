#include "iflan.h"

iflan::iflan(QString name)
{
    iflan::name=name;
}

iflan & iflan::operator=(QString input)
{
    name=input;
    return *this;
}

iflan & iflan::operator=(iflan input)
{
    name=input.name;
    return *this;
}

bool iflan::operator==(QString input)
{
    if(name==input){
        return true;
    }else{
        return false;
    }
}

bool iflan::operator==(iflan input)
{
    if(name==input.name){
        return true;
    }else{
        return false;
    }
}

QString iflan::value()
{
    return name;
}
