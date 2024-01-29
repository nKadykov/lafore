#include <iostream>
using namespace std;

int main() {
    int ftemp;
    cout << "Enter Fahrenheit temperature";
    cin >> ftemp;
    int ctemp = (ftemp - 32) * 5 / 9;
    cout << "Temperature in Celsius is " << ctemp << endl;
    return 0;
}