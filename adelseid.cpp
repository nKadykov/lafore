#include <iostream>
#include <conio.h>
using namespace std;

int main() {
    char dir = 'a';
    int x = 10;
    int y = 10;
    cout << "Enter for exit: \n";
    while(dir != '\r') {
        cout << "\nYour coordinates: " << x << ", " << y;
        cout << "\nEnter direction (n, s, e, w): ";
        dir = getche();
        if(dir == 'n') {
            y--;
        }
        else if(dir == 's') {
            y++;
        }
        else if(dir == 'e') {
            x++;
        }
        else if(dir == 'w') {
            x--;
        }
    }
    return 0;
}