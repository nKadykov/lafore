#include <iostream>
using namespace std;

int main() {
    double a, b, c, d;
    double result;
    char oper;
    char ch = '/';
    char enter;
    while(enter != 'n') {
        cout << "Enter franctions: ";
        cin >> a >> ch >> b >> oper >> c >> ch >> d;
        cout << "Result: ";
        switch(oper) {
            case '+':
                result = (a * d + b * c) / (b * d);
                cout << result << '\n';
                break;
            case '-':
                result = (a * d - b * c) / (b * d);
                cout << result << '\n';
                break;
            case '*':
                result = a / b * c / d;
                cout << result << '\n';
                break;
            case '/':
                result = (a * d) / (b * c);
                cout << result << '\n';
                break;
            default:
                cout << "Error\n";
        }
        cout << "Continue? (y/n): ";
        cin >> enter;
    }
    return 0;
}