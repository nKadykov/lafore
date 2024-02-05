#include <iostream>
using namespace std;


struct Fraction {
    int dividend;
    int divisor;
};

int main() {
    Fraction f1;
    Fraction f2;
    char dummychar = '/';
    cout << "Enter first: ";
    cin >> f1.dividend >> dummychar >> f1.divisor;
    cout << "Enter second: ";
    cin >> f2.dividend >> dummychar >> f2.divisor;
    cout << "Sum equals: " << (f1.dividend * f2.divisor + f1.divisor * f2.dividend) << '/' << (f1.divisor * f2.divisor);
    return 0;
}