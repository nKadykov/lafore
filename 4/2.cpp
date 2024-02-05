#include <iostream>
using namespace std;

struct Point {
    int x;
    int y;
};

int main() {
    Point p1;
    Point p2;

    cout << "Enter coordinates of p1: ";
    cin >> p1.x >> p1.y;
    cout << "Enter coordinates of p2: ";
    cin >> p2.x >> p2.y;

    cout << "Coordinates of p1 + p2 are " << p1.x + p2.x << "." << p1.y + p2.y;

    return 0;
}