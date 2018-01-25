#ifndef PENSIONER_H
#define PENSIONER_H
#include <iostream>
using namespace std;

class Pensioner
{
    string _name;
    string _surname;
    int _data;
    int _age;
    string _grandchildrenName;
    string _grandchildrenSurname;

public:
    Pensioner();
    ~Pensioner();
    void set_name(string name);
    void set_surname(string surname);
    void set_age(int age);
    void set_data(int data);
    void set_grandchildrenName (string granchildrenName);
    void set_grandchildrenSurname (string granchildrenSurname);

    string name();
    string surname();
    int age();
    int data();
    string grandchildrenName();
    string grandchildrenSurname();

    void print();

};

#endif // PENSIONER_H
