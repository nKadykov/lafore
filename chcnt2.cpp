#include <iostream>
#include <conio.h>
using namespace std;

int main() {
    int chcount = 0;
    int wdcount = 1;
    char ch;
    while((ch = getche()) != '\r') {
        if(ch == ' ') {
            wdcount++;
        }
        else {
            chcount++;
        }
    }
    cout << "Words: " << wdcount << endl;
    cout << "Letters: " << chcount << endl;
    return 0;
}