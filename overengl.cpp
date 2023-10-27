#include <iostream>
using namespace std;

struct Distance {
    int feet;
    float inches;
};

void engldisp(Distance);
void engldisp(float);

int main() {
    Distance d1;
    float d2;
    cout << "Enter feet: ";
    cin >> d1.feet;
    cout << "Enter inches: ";
    cin >> d1.inches;
    cout << "Enter inches: ";
    cin >> d2;
    cout << "d1 = ";
    engldisp(d1);
    cout << "d2 = ";
    engldisp(d2);
    return 0;
}

void engldisp(Distance dd) {
    cout << dd.feet << "\' - " << dd.inches << "\"\n";
}

void engldisp(float dd) {
    int feet = static_cast<int>(dd / 12);
    float inches = dd - feet * 12;
    cout << feet << "\' - " << inches << "\"\n";
}