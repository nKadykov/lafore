#include <iostream>
using namespace std;

int main() {
    double dec;
    cout << "Enter pounds: ";
    cin >> dec;
    int pound;
    double frac;
    pound = static_cast<int>(dec);
    frac = dec - pound;
    double sh = frac;
    int s = static_cast<int>(sh);
    double fr = sh - s;
    int shilling = 20 * frac;
    int pens = 12 * fr;
    cout << "Old writing: " << pound << '.' << shilling << '.' << pens;
    return 0;
}