#include <iostream>
#include <cmath>
using namespace std;

class Polar {
    double rad;
    double angle;
public:
    Polar() : rad(0.0), angle(0.0) {}
    Polar(double r, double a) : rad(r), angle(a) {}
    Polar operator+(Polar p);
    void put();
    void get();
};

int main() {
    Polar p1, p2;
    p1.put();
    p2.put();
    Polar sum = p1 + p2;
    sum.get();
    return 0;
}

Polar Polar::operator+(Polar p) {
    double x1 = rad * cos(angle);
    double y1 = rad * sin(angle);
    double x2 = p.rad * cos(p.angle);
    double y2 = p.rad * sin(p.angle);
    double x = x1 + x2;
    double y = y1 + y2;
    double r = sqrt(pow(x, 2) + pow(y, 2));
    double a = acos(x / (sqrt(pow(x, 2) + pow(y, 2))));
    return Polar(r, a);
}

void Polar::put() {
    cout << "Enter radius and angle: ";
    cin >> rad >> angle;
}

void Polar::get() {
    cout << "Radius and angle: " << rad << ' ' << angle;
}