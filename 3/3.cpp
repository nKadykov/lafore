#include <iostream>
#include <conio.h>
using namespace std;

int main() {
    long result = 0;
    int degree = 100000;
    for(int i = 0; i < 6; i++) {
        char ch = getche();
        result += degree * (ch - '0');
        degree /= 10;
    }
    cout << '\n';
    cout << result;
    return 0;
}