#include <iostream>
using namespace std;

class Distance {
    int feet;
    double inches;
public:
    Distance(): feet(0), inches(0) {}
    Distance(int ft, double in): feet(ft), inches(in) {}
    void getdist() {
        cout << "\nEnter feet: ";
        cin >> feet;
        cout << "\nEnter inches ";
        cin >> inches;
    }
    void showdist() {
        cout << feet << "\' - " << inches << "\"\n";
    }
    bool operator<(Distance) const;
};

bool Distance::operator<(Distance d2) const {
    double bf1 = feet + inches / 12;
    double bf2 = d2.feet + d2.inches / 12;
    return (bf1 < bf2) ? true : false;
}

int main() {
    Distance dist1;
    dist1.getdist();

    Distance dist2(6, 2.5);

    cout << "\ndist1 = ";
    dist1.showdist();
    cout << "\ndist2 = ";
    dist2.showdist();

    if(dist1 < dist2) {
        cout << "\ndist1 less then dist2\n";
    }
    else {
        cout << "\ndist1 more or equal then dist2\n";
    }
    return 0;
}