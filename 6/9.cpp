#include <iostream>
using namespace std;

class Fraction {
    int dividend;
    int divisor;
public:
    Fraction() : dividend(0), divisor(1) {}
    Fraction(int a, int b) : dividend(a), divisor(b) {}
    void putfrac() {
        char ch = '/';
        cout << "Enter fraction: ";
        cin >> dividend >> ch >> divisor;
    }
    void getfrac() {
        cout << dividend << '/' << divisor << '\n';
    }
    void sumfrac(Fraction f1, Fraction f2) {
        dividend = f1.dividend * f2.divisor + f1.divisor * f2.dividend;
        divisor = f1.divisor * f2.divisor;
        cout << dividend << '/' << divisor << '\n';
    }
};

int main() {
    Fraction f1, f2, s;

    f1.putfrac();
    f1.getfrac();
    f2.putfrac();
    f2.getfrac();

    s.sumfrac(f1, f2);

    return 0;
}