#include <QCoreApplication>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <QDebug>
#include <thread>
#include <mutex>
#include "graphics.h"
#include <progbase.h>
#include <progbase-cpp/console.h>
using namespace std;
using namespace progbase::console;





void clearRect(Vec2D location, Vec2D size) {
   for (int y = 0; y < size.y; y++) {
        for (int x = 0; x < size.x; x++) {
            Vec2D pos = { location.x + x, location.y + y };
            Graphics_drawPixel(NULL, pos, CursorAttributes::BG_BLACK);
        }
    }
 }

void Square_draw(Vec2D CenterCoordinates,
                  double M,
                  double N,
                  double radius,
                  CursorAttributes color,
                  mutex & m) {
     double angleBeta = 2*atan(M/N);
     M = 2*radius*sin(angleBeta/2);
     N = 2*radius*cos(angleBeta/2);
     Vec2D FirstCoordinates = (Vec2D){CenterCoordinates.x+N/2,CenterCoordinates.y+M/2};
     Vec2D SecondCoordinates = (Vec2D){CenterCoordinates.x-N/2,CenterCoordinates.y+M/2};
     Vec2D ThirdCoordinates = (Vec2D){CenterCoordinates.x-N/2,CenterCoordinates.y-N/2};
     Vec2D FourthCoordinates = (Vec2D){CenterCoordinates.x+N/2,CenterCoordinates.y-N/2};
     m.lock();
     Graphics_drawLine(NULL, FirstCoordinates , SecondCoordinates, color);
     Graphics_drawLine(NULL, SecondCoordinates, ThirdCoordinates, color);
     Graphics_drawLine(NULL, ThirdCoordinates, FourthCoordinates, color);
     Graphics_drawLine(NULL, FourthCoordinates, FirstCoordinates, color);
     m.unlock();


 }

void threadLeft(mutex & m,
                int amp,
                int milliseconds,
                double M,
                double N,
                CursorAttributes color) {
    Vec2D SquareCentreCoordinates = (Vec2D){20,13};
    double radius = sqrt(pow(M,2) + pow(N,2))/2;
    int degrees = 0;
    while (1) {
       m.lock();
       clearRect((Vec2D){0, 0}, (Vec2D){40, 26});
       m.unlock();
       double radians = degrees * M_PI / 180.0;
       double r = amp * sinf(radians);
       Square_draw(SquareCentreCoordinates,M,N,radius + r,color,m);
       Console::hideCursor();
       this_thread::sleep_for(chrono::milliseconds(milliseconds));
       degrees++;
    }
}
void PrintRotateSquare(Vec2D consoleCenter,
                       double M,
                       double N,
                       double radians,
                       double radius,
                       double rotateRadius,
                       mutex & m,
                       CursorAttributes color) {
    Vec2D rotateVector = (Vec2D){1, 1};
    rotateVector = Vec2D_normalize(rotateVector);
    rotateVector = Vec2D_multByNumber(rotateVector, rotateRadius);
    rotateVector = Vec2D_rotate(rotateVector, radians);
    Vec2D squareCenter = Vec2D_add(consoleCenter, rotateVector);
    Square_draw(squareCenter,M,N,radius,color,m);
    Console::hideCursor();

}

void threadRight(mutex & m,
                 int milliseconds,
                 double M,
                 double N,
                 double rotateRadius,
                 CursorAttributes color) {
     Vec2D consoleCenter = (Vec2D){60, 13};
     double radius =  sqrt(pow(M,2) + pow(N,2))/2;
     int degrees = 0;
      while (1) {
         m.lock();
         clearRect((Vec2D){40, 0}, (Vec2D){40, 26});
         m.unlock();
         double radians = degrees * M_PI / 180.0;
         PrintRotateSquare(consoleCenter,M,N,radians,radius,rotateRadius,m,color);
         Console::hideCursor();
         degrees++;
         this_thread::sleep_for(chrono::milliseconds(milliseconds));
    }
}


int main(void)
{

    mutex m;
    Console::clear();
    int millisecond = 3;
    int millis = 2;
    int amp = 2;
    double M = 4;
    double N = 6;
    double rotateRadius = 8;
    thread first(threadLeft,std::ref(m),amp,millisecond,M,N,CursorAttributes::BG_RED);
    thread second(threadRight,std::ref(m),millis,M,N,rotateRadius,CursorAttributes::BG_BLUE);

    while (!Console::isKeyDown()) { }

    first.detach();
    second.detach();

    Console::reset();
    cout << endl;

   return 0;
}
