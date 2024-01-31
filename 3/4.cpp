#include <iostream>
#include <conio.h>
using namespace std;

int main() {
    char ch;
    double a;
    double b;
    int ans;
    while(ans != 'n') {
        cout << "Enter first number, operation and second number: ";
        cin >> a >> ch >> b;
        cout << "Result: ";
        switch(ch) {
            case '+':
                cout << a + b << '\n';
                break;
            case '-':
                cout << a - b << '\n';
                break;
            case '*':
                cout << a * b << '\n';
                break;
            case '/':
                cout << a / b << '\n';
                break;
            default:
                cout << "Incorrect operation\n";
        }
        cout << "One more? (y/n): ";
        ans = getche();
    }
    return 0;
}