#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cctype>
#include <unordered_map>
#include "msoftcon.h"
using namespace std;

class Circle {
protected:
    int xCo, yCo;
    int radius;
    color fillcolor;
    fstyle fillstyle;
public:
    void set(int x, int y, int r, color fc, fstyle fs) {
        xCo = x;
        yCo = y;
        radius = r;
        fillcolor = fc;
        fillstyle = fs;     
    }
    void draw() {
        set_color(fillcolor);
        set_fill_style(fillstyle);
        draw_circle(xCo, yCo, radius);
    }
};

int main() {
    init_graphics();
    Circle c1;
    Circle c2;
    Circle c3;

    c1.set(15, 7, 5, cBLUE, X_FILL);
    c2.set(41, 12, 7, cRED, O_FILL);
    c3.set(65, 18, 4, cGREEN, MEDIUM_FILL);
    c1.draw();
    c2.draw();
    c3.draw();
    set_cursor_pos(1, 25);

    return 0;
}