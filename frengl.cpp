#include <iostream>
using namespace std;

class Distance {
    int feet;
    float inches;
public:
    Distance() : feet(0), inches(0.0) {}
    Distance(float fltfeet) {
        feet = int(fltfeet);
        inches = 12 * (fltfeet) - feet;
    }
    Distance(int ft, float in) : feet(ft), inches(in) {}
    void showdist() {
        cout << feet << "' - " << inches << "\"";
    }
    friend Distance operator+(Distance, Distance);
};

Distance operator+(Distance d1, Distance d2) {
    int f = d1.feet + d2.feet;
    float i = d1.inches + d2.inches;
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

    d3 = d1 + 10;
    cout << "\nd3 = ";
    d1.showdist();
    d3 = 10 + d1;
    cout << "\nd3 = ";
    d3.showdist();

    return 0;    
}