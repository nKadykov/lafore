#include <iostream>
using namespace std;

int main() {
    long dividend;
    long divisor;
    char ch;
    do {
        cout << "Enter dividend: ";
        cin >> dividend;
        cout << "Enter divisor: ";
        cin >> divisor;
        if(divisor == 0) {
            cout << "Incorrect divisor!\n";
            continue;
        }
        cout << "Result is " << dividend / divisor;
        cout << ", remainder is " << dividend % divisor;
        cout << "\nOne more? (y / n): ";
        cin >> ch;
    } while(ch != 'n');
    return 0;
}