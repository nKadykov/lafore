#include <iostream>
using namespace std;

class Distance {
    int feet;
    float inches;
public:
    Distance() : feet(0), inches(0.0) {}
    Distance(float fltfeet) {
        feet = static_cast<int>(fltfeet);
        inches = 12 * (fltfeet - feet);
    }
    Distance(int ft, float in) {
        feet = ft;
        inches = in;
    }
    void showdist() {
        cout << feet << "\' - " << inches << "\"\n";
    }
    Distance operator+(Distance);
};

Distance Distance::operator+(Distance d2) {
    int f = feet + d2.feet;
    float i = inches + d2.inches;
    if(i >= 12.0) {
        i -= 12.0;
        f++;
    }
    return Distance(f, i);
}

int main() {
    Distance d1 = 2.5;
    Distance d2 = 1.25;
    Distance d3;

    cout << "d1 = ";
    d1.showdist();
    cout << "d2 = ";
    d2.showdist();

    d3 = d1 + 10;
    cout << "d3 = ";
    d3.showdist();
    return 0;
}