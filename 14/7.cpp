#include <iostream>
#include <vector>
using namespace std;

template<class Type>
class Fraction {
    Type dividend;
    Type divisor;
public:
    Fraction() {}
    Fraction(Type a, Type b) : dividend(a), divisor(b) {}
    Fraction operator+(Fraction) const;
    Fraction operator-(Fraction) const;
    Fraction operator*(Fraction) const;
    Fraction operator/(Fraction) const;
    void putdata() {
        int ch = '/';
        cin >> dividend >> ch >> divisor;
    }
    void getdata() {
        cout << "Result: " << static_cast<long>(dividend) << '/' << static_cast<long>(divisor) << '\n';
    }
    Fraction lowterms();
};

int main() {
    Fraction<char> s1(2, 5), s2(1, 6), result;
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

template<class Type>
Fraction<Type> Fraction<Type>::operator+(Fraction f) const {
    Type a = dividend * f.divisor + divisor * f.dividend;
    Type b = divisor * f.divisor;
    return Fraction(a, b).lowterms();
}

template<class Type>
Fraction<Type> Fraction<Type>::operator-(Fraction<Type> f) const {
    Type a = dividend * f.divisor - divisor * f.dividend;
    Type b = divisor * f.divisor;
    return Fraction(a, b).lowterms();
}

template<class Type>
Fraction<Type> Fraction<Type>::operator*(Fraction<Type> f) const {
    Type a = dividend * f.dividend;
    Type b = divisor * f.divisor;
    return Fraction(a, b).lowterms();
}

template<class Type>
Fraction<Type> Fraction<Type>::operator/(Fraction<Type> f) const {
    Type a = dividend * f.divisor;
    Type b = divisor * f.dividend;
    return Fraction(a, b).lowterms();
}

template<class Type>
Fraction<Type> Fraction<Type>::lowterms() {
    Type tnum, tden, temp, gcd;
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