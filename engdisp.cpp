#include <iostream>
using namespace std;

struct Distance {
    int feet;
    float inches;
};

void engdisp(Distance);

int main() {
    Distance d1, d2;

    cout << "Enter feet: ";
    cin >> d1.feet;
    cout << "Enter inches: ";
    cin >> d1.inches;
    cout << "Enter feet: ";
    cin >> d2.feet;
    cout << "Enter inches: ";
    cin >> d2.inches;
    cout << "d1 = ";
    engdisp(d1);
    cout << "d2 = ";
    engdisp(d2);
    cout << '\n';

    return 0;
}

void engdisp(Distance dd) {
    cout << dd.feet << "\' - " << dd.inches << '\"' << '\n';
}