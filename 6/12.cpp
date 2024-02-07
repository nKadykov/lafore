#include <iostream>
#include <vector>
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
    void putdata(int a, int b) {
        dividend = a;
        divisor = b;
    }
    void getdata() {
        cout << "Result: " << dividend << '/' << divisor;
    }
    void lowterms();
};

int main() {
    Fraction s;
    vector<Fraction> v;
    char ch;
    while(ch != 'n') {
        Fraction t;
        char d = '/';
        int a, b;
        cin >> a >> d >> b;
        t.putdata(a, b);
        v.push_back(t);
        for(int i = 0; i < v.size(); i++) {
            for(int j = 0; j < v.size(); j++) {
                s.fmul(v[i], v[j]);
            }
            cout << '\n';
        }
        cout << "Continue? (y/n): ";
        cin >> ch;
    }
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
    cout << dividend << '/' << divisor << ' ';
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