#include <iostream>
#include "msoftcon.h"
using namespace std;

class Shape {
protected:
    int xCo, yCo;
    color fillcolor;
    fstyle fillstyle;
public:
    Shape() : xCo(0), yCo(0), fillcolor(cWHITE), fillstyle(SOLID_FILL) {}
    Shape(int x, int y, color fc, fstyle fs) : xCo(x), yCo(y), fillcolor(fc), fillstyle(fs) {}
    virtual void draw() = 0;
};

class Ball : public Shape {
    int radius;
public:
    Ball() : Shape() {}
    Ball(int x, int y, int r, color fc, fstyle fs) : Shape(x, y,  fc, fs), radius(r) {}
    void draw() {
        Shape::draw();
        draw_circle(xCo, yCo, radius);
    }
};

class Rect : public Shape {
    int width;
    int height;
public:
    Rect() : Shape(), height(0), width(0) {}
    Rect(int x, int y, int h, int w, color fc, fstyle fs) : Shape(x, y, fc, fs), height(h), width(w) {}
    void draw() {
        Shape::draw();
        draw_rectangle(xCo, yCo, xCo + width, yCo + height);
        set_color(cWHITE);
        draw_line(xCo, yCo, xCo + width, yCo + height);
    }
};

class Tria : public Shape {
    int height;
public:
    Tria() : Shape(), height(0) {}
    Tria(int x, int y, int h, color fc, fstyle fs) : Shape(x, y, fc, fs), height(h) {}
    void draw() {
        Shape::draw();
        draw_pyramid(xCo, yCo, height);
    }
};

int main() {
    init_graphics();
    Shape* pShapes[3];

    pShapes[0] = new Ball(40, 12, 5, cBLUE, X_FILL);
    pShapes[1] = new Rect(12, 7, 10, 15, cRED, SOLID_FILL);
    pShapes[2] = new Tria(60, 7, 11, cGREEN, MEDIUM_FILL);

    for(int i = 0; i < 3; i++) {
        pShapes[i]->draw();
    }
    for(int i = 0; i < 3; i++) {
        delete pShapes[i];
    }
    set_cursor_pos(1, 25);
    return 0;
}