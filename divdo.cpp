#include <iostream>
using namespace std;

int main() {
    long dividend;
    long divisor;
    char ch;
    do {
        cout << "Enter divident: ";
        cin >> dividend;
        cout << "Enter divisor: ";
        cin >> divisor;
        cout << "Result is " << dividend / divisor;
        cout << ", remainder is " << dividend % divisor;
        cout << "\nOne more? (y/n);";
        cin >> ch;
    }
    while(ch != 'n');
    return 0;
}