#include <iostream>
using namespace std;

class Distance {
    int feet;
    float inches;
public:
    Distance(): feet(0), inches(0.0) {}
    Distance(int ft, float in): feet(ft), inches(in) {}
    void getdist() {
        cout << "Enter feet: ";
        cin >> feet;
        cout << "Enter inches: ";
        cin >> inches;
    }
    void showdist() {
        cout << feet << "\' - " << inches << "\"";
    }
    void operator += (Distance);
};

void Distance::operator+=(Distance d) {
    feet += d.feet;
    inches += d.inches;
    if(inches >= 12.0) {
        inches -= 12.0;
        feet++;
    }
}

int main() {
    Distance dist1;
    dist1.getdist();
    
    cout << "\ndist1 = ";
    dist1.showdist();

    Distance dist2(11, 6.25);

    dist1 += dist2;
    cout << "\nAfter insert:";

    cout << "\ndist1 = ";
    dist1.showdist();

    return 0;
}