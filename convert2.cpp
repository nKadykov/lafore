#include <iostream>
using namespace std;

float lbstokg(float);

int main() {
    float lbs;
    cout << "Pounds: ";
    cin >> lbs;
    cout << "Kilograms: " << lbstokg(lbs) << '\n';

    return 0;
}

float lbstokg(float pounds) {
    return 0.453592 * pounds;
}