#include <iostream>
using namespace std;

void zeroSmaller(int& a, int& b) {
    if(a < b) {
        a = 0;
    }
    else {
        b = 0;
    }
}

int main() {
    int a, b;

    cout << "Enter a and b: ";
    cin >> a >> b;

    zeroSmaller(a, b);

    cout << "Result: " << a << ' ' << b;

    return 0;
}