#include <iostream>
using namespace std;

float lbstokg(float);

int main() {
    float lbs, kgs;
    cout << "Enter pounds: ";
    cin >> lbs;
    kgs = lbstokg(lbs);
    cout << "Kilograms: " << kgs << '\n';
    return 0;
}

float lbstokg(float pounds) {
    float kilograms = 0.453592 * pounds;
    return kilograms;
}