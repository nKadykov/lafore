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
    Distance(int ft, float in) : feet(ft), inches(in) {}
    void showdist() {
        cout << feet << "' - " << inches << "\"\n";
    }
    friend Distance operator*(Distance, Distance);
};

Distance operator*(Distance d1, Distance d2) {
    float feet1 = d1.feet + d1.inches / 12;
    float feet2 = d2.feet + d2.inches / 12;
    float product = feet1 * feet2;
    return Distance(product);
}

int main() {
    Distance d1(1, 1.0);
    Distance d2(2, 2.0);
    Distance d3;
    d3 = d1 * d2;
    d3.showdist();
    d3 = 10 * d1;
    d3.showdist();

    return 0;    
}