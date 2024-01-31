#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    for(int i = 0; i < 20; i++) {
        string ch;
        for(int j = 0; j < (i + 1); j++) {
            ch += 'x';
        }
        cout << setw(20) << ch;
        cout << '\n';
    }
    return 0;
}