#include <iostream>
using namespace std;

class Distance {
    int feet;
    float inches;
public:
    Distance() : feet(0), inches(0.0) {}
    Distance(int ft, float in) : feet(ft), inches(in) {}
    void getdist() {
        cout << "\nEnter feet: ";
        cin >> feet;
        cout << "Enter inches: ";
        cin >> inches;
    }
    void showdist() const {
        cout << feet << "\' " << inches << '\"';
    }
    void add_dist(Distance, Distance);
    void div_dist(Distance, int);
};

int main() {
    Distance distarr[100];
    Distance total(0, 0.0), average;
    int count = 0;
    char ch;
    do {
        cout << "Enter distance: ";
        distarr[count++].getdist();
        cout << "Continue? (y/n): ";
        cin >> ch;
    }
    while(ch != 'n');
    for(int i = 0; i < count; i++) {
        total.add_dist(total, distarr[i]);
    }
    average.div_dist(total, count);
    cout << "Average: ";
    average.showdist();
    cout << endl;
}

void Distance::add_dist(Distance d1, Distance d2) {
    inches = d1.inches + d2.inches;
    feet = 0;
    if(inches >= 12.0) {
        inches -= 12.0;
        feet++;
    }
    feet += d1.feet + d2.feet;
}

void Distance::div_dist(Distance d2, int divisor) {
    float fltfeet = d2.feet + d2.inches / 12.0;
    fltfeet /= divisor;
    feet = int(fltfeet);
    inches = (fltfeet - feet) * 12.0;
}