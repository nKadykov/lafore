#include <iostream>
using namespace std;

class Fraction {
    double dividend;
    double divisor;
public:
    Fraction() : dividend(0), divisor(1) {}
    Fraction(double a, double b) : dividend(a), divisor(b) {}
    void fadd(Fraction, Fraction);
    void fsub(Fraction, Fraction);
    void fmul(Fraction, Fraction);
    void fdiv(Fraction, Fraction);
    void putdata() {
        int ch = '/';
        cin >> dividend >> ch >> divisor;
    }
    void getdata() {
        cout << "Result: " << dividend << '/' << divisor;
    }
    void lowterms();
};

int main() {
    Fraction f1(2, 5), f2(1, 5), s;
    cout << "Enter franctions\n";
    cout << "a/b + c/d = ";
    s.fadd(f1, f2);
    cout << "a/b - c/d = ";
    s.fsub(f1, f2);
    cout << "a/b * c/d = ";
    s.fmul(f1, f2);
    cout << "a/b / c/d = ";
    s.fdiv(f1, f2);
    return 0;
}

void Fraction::fadd(Fraction f1, Fraction f2) {
    dividend = f1.dividend * f2.divisor + f1.divisor * f2.dividend;
    divisor = f1.divisor * f2.divisor;
    lowterms();
    cout << dividend << '/' << divisor << '\n';
}

void Fraction::fsub(Fraction f1, Fraction f2) {
    dividend = f1.dividend * f2.divisor - f1.divisor * f2.dividend;
    divisor = f1.divisor * f2.divisor;
    lowterms();
    cout << dividend << '/' << divisor << '\n';
}

void Fraction::fmul(Fraction f1, Fraction f2) {
    dividend = f1.dividend * f2.dividend;
    divisor = f1.divisor * f2.divisor;
    lowterms();
    cout << dividend << '/' << divisor << '\n';
}

void Fraction::fdiv(Fraction f1, Fraction f2) {
    dividend = f1.dividend * f2.divisor;
    divisor = f1.divisor * f2.dividend;
    lowterms();
    cout << dividend << '/' << divisor << '\n';
}

void Fraction::lowterms() {
    long tnum, tden, temp, gcd;
    tnum = labs(dividend);
    tden = labs(divisor);
    if(tden == 0) {
        cout << "Incorrect divisor!";
        exit(1);
    }
    else if(tnum == 0) {
        dividend = 0;
        divisor = 1;
        return;
    }
    while(tnum != 0) {
        if(tnum < tden) {
            temp = tnum;
            tnum = tden;
            tden = temp;
        }
        tnum = tnum - tden;
    }
    gcd = tden;
    dividend = dividend / gcd;
    divisor = divisor / gcd;
}