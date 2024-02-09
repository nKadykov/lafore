#include <iostream>
#include <vector>
using namespace std;

const unsigned SIZE = 100;
int count = 0;

class Fraction {
    int dividend;
    int divisor;
public:
    Fraction() : dividend(0), divisor(0) {}
    Fraction(int a, int b) : dividend(a), divisor(b) {}
    void putfrac() {
        char ch = '/';
        cout << "Enter fraction: ";
        cin >> dividend >> ch >> divisor;
    }
    void getfrac() {
        lowterms();
        cout << "Fraction: " << dividend << '/' << divisor;
    }
    void fadd(Fraction, Fraction);
    void lowterms();
    void mid(Fraction, int);
};

int main() {
    Fraction f;
    Fraction arr[SIZE];
    char ch;
    do {
        arr[count].putfrac();
        count++;
        cout << "Continue? (y/n): ";
        cin >> ch;
    }
    while(ch != 'n');
    Fraction result = arr[0];
    for(int i = 1; i < count; i++) {
        result.fadd(result, arr[i]);
        i++;
    }
    result.mid(result, count);
    result.getfrac();
    return 0;
}

void Fraction::fadd(Fraction f1, Fraction f2) {
    dividend = f1.dividend * f2.divisor + f1.divisor * f2.dividend;
    divisor = f1.divisor * f2.divisor;
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

void Fraction::mid(Fraction f1, int i) {
    divisor = f1.divisor * i;
}