#include "pensioner.h"

using namespace std;

Pensioner::Pensioner()
{

   this->_name = "";
   this->_surname = "";
   this->_age = 0;
   this->_data = 0;
   this->_grandchildrenName = "";
   this->_grandchildrenSurname = "";

}
Pensioner::~Pensioner()
{
    std::cout << "Pensioner is destoyed!" << std::endl;
}

void Pensioner::set_name(string name) { this->_name = name; }
void Pensioner::set_surname(string surname) { this->_surname = surname; }
void Pensioner::set_age(int age) { this->_age = age; }
void Pensioner::set_data(int data) { this->_data = data; }
void Pensioner::set_grandchildrenName (string granchildrenName) { this->_grandchildrenName =  granchildrenName; }
void Pensioner::set_grandchildrenSurname (string granchildrenSurname) { this->_grandchildrenSurname =  granchildrenSurname; }

string Pensioner::name() { return this->_name; }
string Pensioner::surname() { return this->_surname; }
int Pensioner::age() { return this->_age; }
int Pensioner::data() { return this->_data; }
string Pensioner::grandchildrenName() { return this->_grandchildrenName; }
string Pensioner::grandchildrenSurname() { return this->_grandchildrenSurname; }

void Pensioner::print() {
    std::cout << _name << " | " << _surname << " | " << _data << " | " << _age << " | " << _grandchildrenName << " | " << _grandchildrenSurname << std::endl;
}
