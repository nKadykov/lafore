#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cout << "Enter numbers a, b, c: \n";
    cin >> a >> b >> c;
    if(a == b) {
        if(b == c) {
            cout << "a, b, c equal\n";
        }
        else {
            cout << "a and b are not equal\n";
        }
    }
    return 0;
}