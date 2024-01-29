#include <iostream>
#include <conio.h>
using namespace std;

int main() {
    char dir = 'a';
    int x = 10;
    int y = 10;
    cout << "Push Enter to quit...\n";
    while(dir != '\r') {
        cout << "\nYour coordinates " << x << ", " << y;
        cout << "\nChoose direction:";
        dir = getche();
        if(dir == 'n') {
            y--;
        }
        else {
            if(dir == 's') {
                y++;
            }
            else {
                if(dir == 'e') {
                    x++;
                }
                else {
                    if(dir == 'w') {
                        x--;
                    }
                }
            }
        }
    }
    return 0;
}