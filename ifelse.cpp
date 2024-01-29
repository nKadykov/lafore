#include <iostream>
using namespace std;

int main() {
    int x;
    cout << "\nEnter number: ";
    cin >> x;
    if(x > 100) {
        cout << "This number's greater than 100\n"; 
    }
    else {
        cout << "This number's not greater than 100\n";
    }
    return 0;
}