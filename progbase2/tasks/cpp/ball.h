#pragma once
#include <iostream>


using namespace std;

class Geometric_Ball {
  string name;
  float radius;
  //координати центра кулі
  int  x;
  int y;
  int z;
  public :
    string get_name();
	float get_radius();
	int get_x();
	int get_y();
	int get_z();
	float count_distance(int,int,int);
    string toString();
	Geometric_Ball(string name,float radius,int x,int y, int z);
    ~Geometric_Ball();

  

};
