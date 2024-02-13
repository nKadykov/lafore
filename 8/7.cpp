#include <iostream>
#include <vector>
using namespace std;

class Fraction {
    int dividend;
    int divisor;
public:
    Fraction() {}
    Fraction(int a, int b) : dividend(a), divisor(b) {}
    Fraction operator+(Fraction) const;
    Fraction operator-(Fraction) const;
    Fraction operator*(Fraction) const;
    Fraction operator/(Fraction) const;
    void putdata() {
        int ch = '/';
        cin >> dividend >> ch >> divisor;
    }
    void getdata() {
        cout << "Result: " << dividend << '/' << divisor << '\n';
    }
    Fraction lowterms();
};

int main() {
    Fraction s1(2, 5), s2(1, 6), result;
    char ch = 'y';
    result = s1 + s2;
    result.getdata();
    result = s1 - s2;
    result.getdata();
    result = s1 * s2;
    result.getdata();
    result = s1 / s2;
    result.getdata();
    return 0;
}

Fraction Fraction::operator+(Fraction f) const {
    int a = dividend * f.divisor + divisor * f.dividend;
    int b = divisor * f.divisor;
    return Fraction(a, b).lowterms();
}

Fraction Fraction::operator-(Fraction f) const {
    int a = dividend * f.divisor - divisor * f.dividend;
    int b = divisor * f.divisor;
    return Fraction(a, b).lowterms();
}

Fraction Fraction::operator*(Fraction f) const {
    int a = dividend * f.dividend;
    int b = divisor * f.divisor;
    return Fraction(a, b).lowterms();
}

Fraction Fraction::operator/(Fraction f) const {
    int a = dividend * f.divisor;
    int b = divisor * f.dividend;
    return Fraction(a, b).lowterms();
}

Fraction Fraction::lowterms() {
    long tnum, tden, temp, gcd;
    tnum = labs(dividend);
    tden = labs(divisor);
    if(tden == 0) {
        cout << "Incorrect divisor!";
    }
    else if(tnum == 0) {
        dividend = 0;
        divisor = 1;
        return Fraction(dividend, divisor);
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
    return Fraction(dividend, divisor);
}