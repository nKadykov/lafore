#include <iostream>
using namespace std;

struct Fraction {
    double dividend;
    double divisor;
};

Fraction fadd(Fraction, Fraction);
Fraction fsub(Fraction, Fraction);
Fraction fmul(Fraction, Fraction);
Fraction fdiv(Fraction, Fraction);

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
                fadd(f1, f2);
                break;
            case '-':
                fsub(f1, f2);
                break;
            case '*':
                fmul(f1, f2);
                break;
            case '/':
                fdiv(f1, f2);
                break;
        }
        cout << "Continue? (y/n): ";
        cin >> enter;
    }
    return 0;
}

Fraction fadd(Fraction f1, Fraction f2) {
    Fraction result;
    result.dividend = f1.dividend * f2.divisor + f1.divisor * f2.dividend;
    result.divisor = f1.divisor * f2.divisor;
    cout << result.dividend << '/' << result.divisor << '\n';
    return result;
}

Fraction fsub(Fraction f1, Fraction f2) {
    Fraction result;
    result.dividend = f1.dividend * f2.divisor - f1.divisor * f2.dividend;
    result.divisor = f1.divisor * f2.divisor;
    cout << result.dividend << '/' << result.divisor << '\n';
    return result;
}

Fraction fmul(Fraction f1, Fraction f2) {
    Fraction result;
    result.dividend = f1.dividend * f2.dividend;
    result.divisor = f1.divisor * f2.divisor;
    cout << result.dividend << '/' << result.divisor << '\n';
    return result;
}

Fraction fdiv(Fraction f1, Fraction f2) {
    Fraction result;
    result.dividend = f1.dividend * f2.divisor;
    result.divisor = f1.divisor * f2.dividend;
    cout << result.dividend << '/' << result.divisor << '\n';
    return result;
}