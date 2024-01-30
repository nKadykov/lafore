#include <iostream>
using namespace std;

int main() {
    int choise;
    cout << "Enter 1 to revert Celcius in Farenheit,\n2 to revert Farenheit in Celcius: ";
    cin >> choise;
    if(choise == 2) {
        double far;
        cout << "Farenheit: ";
        cin >> far;
        cout << "Celcius: " << (far - 32) * 5 / 9;
    }
    else if(choise == 1) {
        double cels;
        cout << "Celcius: ";
        cin >> cels;
        cout << "Farenheit: " << cels * 9 / 5 + 32;
    }
    return 0;
}