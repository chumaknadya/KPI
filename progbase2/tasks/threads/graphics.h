#pragma once

typedef struct Graphics Graphics;

typedef struct Vec2D Vec2D;
struct Vec2D {
    double x;
    double y;
};

typedef int ConsoleColor;

void Graphics_drawPixel(Graphics * self, Vec2D pos, ConsoleColor color);
void Graphics_drawLine(Graphics * self, Vec2D start, Vec2D end, ConsoleColor color);
void Graphics_drawCircle(Graphics * self, Vec2D pos, double radius, ConsoleColor color);

Vec2D Vec2D_normalize(Vec2D self) ;
Vec2D Vec2D_rotate(Vec2D self, double radians);
Vec2D Vec2D_multByNumber(Vec2D a, double number);
double Vec2D_length(Vec2D self);
Vec2D Vec2D_substract(Vec2D a, Vec2D b);
Vec2D Vec2D_add(Vec2D a, Vec2D b);
