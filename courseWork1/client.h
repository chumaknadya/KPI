#ifndef CLIENT_H
#define CLIENT_H
#include <QString>

class Client
{
    QString _client;
    QString _clientStatus;
    QString _lostKeys;
    QString _propertyDamage;
    QString _alcohol;
    QString _drugs;
    QString _smoking;
    QString _otherViolation;
public:
    Client();
    ~Client();
     Client(QString  client,QString  clientStatus,
            QString  lostKeys,QString propertyDamage,
            QString  alcohol,QString drugs,
            QString  smoking,QString otherViolation);
     QString get_client();
     QString get_clientStatus();
     QString get_lostKeys();
     QString get_propertyDamage();
     QString get_alcohol();
     QString get_drugs();
     QString get_smoking();
     QString get_otherViolation();
     void print();
};

#endif // CLIENT_H
