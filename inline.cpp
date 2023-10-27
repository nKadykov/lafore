#include <iostream>
using namespace std;

inline float lbstokg(float pounds) {
    return 0.453592 * pounds;
}

int main() {
    float lbs;
    cout << "Enter pounds: ";
    cin >> lbs;
    cout << lbstokg(lbs) << '\n';

    return 0;
} 