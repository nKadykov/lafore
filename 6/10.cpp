#include <iostream>
using namespace std;

class Angle {
    int grad;
    float min;
    char dir;
public:
    Angle() : grad(0), min(0), dir(' ') {}
    Angle(int g, int m, char d) : grad(g), min(m), dir(d) {}
    void input() {
        cout << "Enter coordinades: ";
        cin >> grad >> min >> dir;
    }
    void output() {
        cout << grad << ' ' << min << '\'' << ' ' << dir << '\n';
    }
};

class Ship {
    static int count;
    int number = count;
    Angle coor;
public:
    Ship() {
        count++;
    }
    Ship(int n, Angle a) : number(n), coor(a) {
        count++;
    }
    void put() {
        coor.input(); 
    }
    void get() {
        cout << "Information\nNumber: " << number << "\nCoordinates: ";
        coor.output(); 
    }
};

int Ship::count = 1;

int main() {
    Ship s1, s2, s3;

    s1.put();
    s1.get();
    s2.put();
    s2.get();
    s3.put();
    s3.get();

    return 0;
}