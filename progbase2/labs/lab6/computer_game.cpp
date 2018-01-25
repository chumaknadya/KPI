#include "computer_game.h"
#include <iostream>
//Classification ::Classification(QString  platform,int numbers_of_player){
//    this->_platform = platform;
//    this->_numbers_of_player = numbers_of_player;
//}

Computer_Game::Computer_Game(QString  fullname,QString  genre,int year,float raiting,QString  platform,int numbers_of_player)
{
      this->_fullname = fullname;
      this->_genre = genre;
      this->_year= year;
      this->_raiting = raiting;
      classification.set_platform_classification(platform);
      classification.set_numbers_of_player_classification(numbers_of_player);




}
Computer_Game::~Computer_Game()
{
    std::cout << "Computer Game is destoyed!" << std::endl;
}
//Classification::~Classification()
//{
//    std::cout << "Classification is destoyed!" << std::endl;
//}
void Classification::set_platform_classification(QString platform) { this->_platform  = platform;}
void Classification::set_numbers_of_player_classification(int numbers_of_player) {this->_numbers_of_player = numbers_of_player ;}
void Computer_Game::set_fullname(QString  fullname) { this->_fullname = fullname; }
void Computer_Game::set_genre(QString  genre) { this->_genre = genre; }
void Computer_Game::set_year(int year) { this->_year = year; }
void Computer_Game::set_raiting(float raiting) { this->_raiting = raiting;}
void Computer_Game::set_platform(QString  platform) { classification.set_platform_classification(platform);}
void Computer_Game::set_numbers_of_player(int numbers_of_player) { classification.set_numbers_of_player_classification(numbers_of_player);}

QString Classification::platform_classification() { return this->_platform;}
int Classification::numbers_of_player_classification() { return this->_numbers_of_player;}
QString Computer_Game ::fullname() { return this->_fullname; }
QString Computer_Game::genre() { return this->_genre; }
int Computer_Game::year() { return this->_year; }
float Computer_Game::raiting() { return this->_raiting; }
QString Computer_Game::platform() {return classification.platform_classification();}
int Computer_Game::numbers_of_player() { return classification.numbers_of_player_classification();}

void Computer_Game::print()
{
    std::cout << _fullname.toStdString() << " | " << _genre.toStdString() << " | " << _year <<
    " | " << _raiting << " | " << classification.platform_classification().toStdString() << " | " << classification.numbers_of_player_classification() << std::endl;
}
