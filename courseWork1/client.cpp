#include "client.h"
#include <iostream>
using namespace std;
Client::Client()
{

}
Client::~Client()
{

}

Client::Client(QString client, QString clientStatus, QString lostKeys,
               QString propertyDamage, QString alcohol, QString drugs,
               QString smoking, QString otherViolation)
{
    this->_client =client;
    this->_clientStatus = clientStatus;
    this->_lostKeys = lostKeys;
    this->_propertyDamage = propertyDamage;
    this->_alcohol = alcohol;
    this->_drugs = drugs;
    this->_smoking = smoking;
    this->_otherViolation = otherViolation;
}

QString Client::get_client()
{
    return this->_client;
}

QString Client::get_clientStatus()
{
    return this->_clientStatus;
}

QString Client::get_lostKeys()
{
    return this->_lostKeys;
}

QString Client::get_propertyDamage()
{
    return this->_propertyDamage;
}

QString Client::get_alcohol()
{
    return this->_alcohol;
}

QString Client::get_drugs()
{
    return this->_drugs;
}

QString Client::get_smoking()
{
    return this->_smoking;
}

QString Client::get_otherViolation()
{
   return this->_otherViolation;
}

void Client::print()
{
    cout<<" "<<_client.toStdString() <<" "<< _otherViolation.toStdString()<< endl;
}
