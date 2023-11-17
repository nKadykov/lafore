#include <iostream>
using namespace std;

int main() {
    int intarray[5] = {31, 54, 77, 52, 93};
    int* ptrint;
    ptrint = intarray;

    for(int i = 0; i < 5; i++) {
        cout << *(ptrint++) << '\n';
    }

    return 0;
}