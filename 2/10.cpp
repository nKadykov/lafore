#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double pound;
    double shilling;
    double pens;
    cout << "Enter pounds: ";
    cin >> pound;
    cout << "Enter shillings: ";
    cin >> shilling;
    cout << "Enter pens: ";
    cin >> pens;
    cout << "Pound: " << setprecision(3) << pound + (shilling / 20) + (pens / 20 / 12);
    return 0;
}