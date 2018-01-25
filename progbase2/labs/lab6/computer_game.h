#ifndef COMPUTER_GAME_H
#define COMPUTER_GAME_H
#include <iostream>
#include <QString>
#include <QMetaType>
using namespace std;
class Classification
{
    QString _platform = " ";
    int _numbers_of_player = 0;
public:
    void set_platform_classification(QString platform);
    void set_numbers_of_player_classification(int numbers_of_player);
    QString platform_classification();
    int numbers_of_player_classification();
    //Classification(QString  platform,int numbers_of_player);
    //~Classification();
};

class Computer_Game
{
    QString _fullname = " ";
    QString _genre = " ";
    int _year = 0;
    float _raiting = 0.0;
    Classification classification;
    //QString _platform = " ";
   //int _numbers_of_player = 0;


public:

    Computer_Game();
    Computer_Game(QString  fullname,QString  genre,int year,float raiting,QString  platform,int numbers_of_player);
    ~Computer_Game();
    void set_fullname(QString  fullname);
    void set_genre(QString  genre);
    void set_year(int year);
    void set_raiting(float raiting);
    void set_platform(QString  platform);
    void set_numbers_of_player(int numbers_of_player);
    QString fullname();
    QString genre();
    int year();
    float  raiting();
    QString platform();
    int numbers_of_player();
    void print();


};
Q_DECLARE_METATYPE(Computer_Game)
#endif // COMPUTER_GAME_H
