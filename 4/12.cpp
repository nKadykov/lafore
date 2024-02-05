#include <iostream>
using namespace std;

struct Fraction {
    double dividend;
    double divisor;
};

int main() {
    Fraction f1, f2;
    double result;
    char oper;
    char ch = '/';
    char enter;
    while(enter != 'n') {
        cout << "Enter franctions: ";
        cin >> f1.dividend >> ch >> f1.divisor >> oper >> f2.dividend >> ch >> f2.divisor;
        cout << "Result: ";
        switch(oper) {
            case '+':
                result = (f1.dividend * f2.divisor + f1.divisor * f2.dividend) / (f1.divisor * f2.divisor);
                cout << result << '\n';
                break;
            case '-':
                result = (f1.dividend * f2.divisor - f1.divisor * f2.dividend) / (f1.divisor * f2.divisor);
                cout << result << '\n';
                break;
            case '*':
                result = f1.dividend / f1.divisor * f2.dividend / f2.divisor;
                cout << result << '\n';
                break;
            case '/':
                result = (f1.dividend * f2.divisor) / (f1.divisor * f2.dividend);
                cout << result << '\n';
                break;
        }
        cout << "Continue? (y/n): ";
        cin >> enter;
    }
    return 0;
}