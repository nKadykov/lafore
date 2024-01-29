#include <iostream>
#include <conio.h>
using namespace std;

int main() {
    int chcount = 0;
    int wdcount = 1;
    char ch = 'a';
    cout << "Enter string: ";
    while(ch != '\r') {
        ch = getche();
        if(ch == ' ') {
            wdcount++;
        }
        else {
            chcount++;
        }
    }
    cout << "\nWords " << wdcount;
    cout << "\nLetters " << (chcount - 1)  << endl;
    return 0;
}