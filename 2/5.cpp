#include <iostream>
using namespace std;

int main() {
    char ch;
    cin >> ch;
    if(islower(ch)) {
        cout << 0;
    }
    else {
        cout << 1;
    }
    return 0;
}