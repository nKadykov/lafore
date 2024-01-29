#include <iostream>
#include <conio.h>
using namespace std;

int main() {
    char dir = 'a';
    int x = 10;
    int y = 10;
    while(dir != '\r') {
        cout << "\nYour coordinates: " << x << ", " << y;
        cout << "\nChoode direction (n, s, e, w): ";
        dir = getche();
        switch(dir) {
            case 'n': 
                y--;
                break;
            case 's':
                y++;
                break;
            case 'e':
                x++;
                break;
            case 'w':
                x--;
                break;
            default:
                cout << "Repeat\n";
        }
    }
    return 0;
}