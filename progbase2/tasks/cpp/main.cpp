#include "ball.h"
#include <iostream>
#include <cmath>
#include <string>

#include <list>

using namespace std;

Geometric_Ball ::Geometric_Ball(string name,float radius,int x,int y, int z) {
	this->name = name;
	this->radius  = radius;
	this->x = x;
	this->y = y;
	this->z = z;

}
string Geometric_Ball :: toString() {
	string str=" Назва  " + name +  " Радіус  " + to_string(radius) + " Х = " + to_string(x) + " Y =  " + to_string(y) + " Z =  " + to_string(z) ;
	return str;
}
Geometric_Ball :: ~Geometric_Ball() {
	cout<<"inside destructor"<<endl;
}


string Geometric_Ball::get_name() {
    return Geometric_Ball::name;
}

float Geometric_Ball::get_radius() {
	 return Geometric_Ball::radius;
}

int Geometric_Ball::get_x() {
	 return Geometric_Ball::x;
}

int Geometric_Ball::get_y() {
	 return Geometric_Ball::y;
}

int Geometric_Ball::get_z() {
	 return Geometric_Ball::z;
}
float Geometric_Ball::count_distance(int x1,int y1,int z1) {
   float result = 0;
   result = sqrt(pow(x - x1,2)+ pow(y - y1,2) + pow(z - z1,2));
   return result;
}

void print_tasks (void) {
	cout << "1.Вивести вміст списку із полями об'єктів у консоль" << endl;
    cout << "2.Додати до списку новий елемент із заданням значень його полів із консолі" << endl;
    cout << "3.Вивести всі кулі, які містять в своєму об'ємі точку (K, K, K), де К задає користувач" << endl;
    cout << "0.Вийти з циклу і завершити роботу програми." << endl;

}
int main(void) {
    list<Geometric_Ball*> list;

	int keyDown = -1;
	int index = 0;
    bool var = true;
	print_tasks();
    do {
	   
	   cout<<"Введіть номер операції"<<endl;

	   cin>>keyDown;
	
	   switch(keyDown) {
	     case 1: {
          
		  
             for (std::list<Geometric_Ball*>::iterator it = list.begin(); it != list.end(); ++it) {
				 Geometric_Ball* cur = *it;
			     cout << cur->toString() << endl;
			  }			 

			
			break;
		 }
		 case 2: {
			
			 string name;
			 float radius = 0.0;
			 int x = 0;
			 int y = 0;
			 int z = 0;
			 cout<< " "<<endl;
			 cout << "Name: ";
    		 cin>>name;
			 cout << "Radius: ";
			 cin >> radius;
			 cout << "X = : ";
			 cin >> x;
			 cout << "Y = : ";
			 cin >> y;
			 cout << "Z = : ";
			 cin >> z;
			 list.push_back(new Geometric_Ball(name,radius,x,y,z));
			 index++;

              break;
		 }
		 case 3: {
			  
			  cout << "Введіть координати точки К "<< endl;
			  int x1;
			  cout << "X = : ";
			  cin >> x1;
			  int y1;
			  cout << "Y = : ";
			  cin >> y1;
			  int z1;
			  cout << "Z = : ";
			  cin >> z1;
     		  
			  cout << "Кулі, які містять в своєму об'ємі точку (K, K, K) :"<< endl;
			  for (std::list<Geometric_Ball*>::iterator it = list.begin(); it != list.end(); ++it) {
				 Geometric_Ball* cur = *it;
			     float res = cur->count_distance(x1,y1,z1);
			     if (cur->get_radius() > res) {
				    cout << " " << cur->get_name() << endl;
			     }
			  }

			  break;
		 }
	
	   }
	   if (keyDown == 0) {
		var = false; 

	   }
	}while(var);

	for (std::list<Geometric_Ball*>::iterator it = list.begin(); it != list.end(); ++it) {
		Geometric_Ball * cur = *it;
		delete cur;
	}




    list.clear();
	return 0;
}