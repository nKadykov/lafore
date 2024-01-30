#include <iostream>
using namespace std;

int main() {
    int speed;
    cout << "Enter number 33, 45 or 78: ";
    cin >> speed;
    switch(speed) {
        case 33:
            cout << "Long\n";
            break;
        case 45:
            cout << "Single\n";
            break;
        case 78:
            cout << "Old\n";
            break;
    }
    return 0;
}