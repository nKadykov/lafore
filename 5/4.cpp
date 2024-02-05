#include <iostream>
using namespace std;

struct Distance {
    int feet;
    float inches;
};

Distance findBiggest(Distance, Distance);

int main() {
    Distance d1, d2, d3;

    cout << "Enter feet: ";
    cin >> d1.feet;
    cout << "Enter inches: ";
    cin >> d1.inches;

    cout << "Enter feet: ";
    cin >> d2.feet;
    cout << "Enter inches: ";
    cin >> d2.inches;

    d3 = findBiggest(d1, d2);
    cout << "Biggest: " << d3.feet << ' ' << d3.inches;

    return 0;
}

Distance findBiggest(Distance d1, Distance d2) {
    if(d1.feet > d2.feet) {
        return d1;
    }
    if(d1.feet < d2.feet) {
        return d2;
    }
    if(d1.inches > d2.inches) {
        return d1;
    }
    else {
        return d2;
    }
}