#include <iostream>
using namespace std;

class Distance {
    int feet;
    float inches;
public:
    Distance() : feet(0), inches(0.0) {}
    Distance(int ft, float in) : feet(ft), inches(in) {}
    void getdist() {
        cout << "Enter feet: ";
        cin >> feet;
        cout << "Enter inches: ";
        cin >> inches;
    }
    void showdist() {
        cout << feet << "\' - " << inches << '\"';
    }
};

int main() {
    Distance dist1(11, 6.25);
    Distance dist2(dist1);
    Distance dist3 = dist1;

    cout << "\ndist1 = ";
    dist1.showdist();
    cout << "\ndist2 = ";
    dist2.showdist();
    cout << "\ndist3 = ";
    dist3.showdist();

    return 0;
}