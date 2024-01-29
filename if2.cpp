#include <iostream>
using namespace std;

int main() {
    int x;
    cout << "Enter number: ";
    cin >> x;
    if(x > 100) {
        cout << "Number " << x;
        cout << " greater than 100\n";
    }
    return 0;
}