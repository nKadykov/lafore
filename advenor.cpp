#include <iostream>
#include <process.h>
#include <conio.h>
using namespace std;

int main() {
    char dir = 'a';
    int x = 10;
    int y = 10;
    while(dir != '\r') {
        cout << "\nYout coodinates: " << x << ", " << y;
        if(x < 5 || x > 15) {
            cout << "\nBe careful, Dragons are here!!!";
        }
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
    }
    return 0;
}