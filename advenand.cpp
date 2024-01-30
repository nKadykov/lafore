#include <iostream>
#include <process.h>
#include <conio.h>
using namespace std;

int main() {
    char dir = 'a';
    int x = 10;
    int y = 10;
    while(dir != '\r') {
        cout << "\nYour coordinates: " << x << ", " << y;
        cout << "\nChoose direction (n, s, e, w): ";
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
        }
        if(x == 7 && y == 11) {
            cout << "\nYou found your gold!\n";
            exit(0);
        }
    }
    return 0;
}