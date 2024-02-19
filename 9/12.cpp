#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class Sterling {
protected:
    long pound;
    int shilling;
    int pence;
public:
    Sterling() : pound(0), shilling(0), pence(0) {}
    Sterling(double d) {
        pound = d;
        shilling = (d - pound) * 20;
        pence = round(((d - pound) * 20 - shilling) * 12);
    }
    Sterling(long p, int sh, int pen) : pound(p), shilling(sh), pence(pen) {}
    void getSterling() {
        char ch = '.';
        cout << "Enter sum: ";
        cin >> pound >> ch >> shilling >> ch >> pence;
    }
    void putSterling() const {
        cout << "Sterling: " << pound << '.' << shilling << '.' << pence;
    }
    operator double() const {
        return (pound + shilling / 20 + pence / 20 / 12);
    }
    Sterling operator+(Sterling s) const {
        return Sterling(double(Sterling(pound, shilling, pence)) + double(s));
    }
    Sterling operator-(Sterling s) const {
        return Sterling(double(Sterling(pound, shilling, pence)) - double(s));
    }
    Sterling operator*(double n) const {
        return Sterling(double(Sterling(pound, shilling, pence)) * n);
    }
    double operator/(Sterling s) const {
        return double(Sterling(pound, shilling, pence)) / double(s);
    }
    Sterling operator/(double n) const {
        return Sterling(double(Sterling(pound, shilling, pence)) / n);
    }
};

class Sterfrac : public Sterling {
    int eight;
public:
    Sterfrac() : Sterling(), eight(0) {}
    Sterfrac(double d) {
        pound = d;
        shilling = (d - pound) * 20;
        pence = ((d - pound) * 20 - shilling) * 12;
        eight = round((((d - pound) * 20 - shilling) * 12 - pence) * 8);
    }
    Sterfrac(long p, int sh, int pen, int e) : Sterling(p, sh, pen), eight(e) {}
    void getSterling() {
        char ch;
        int dividend, divisor;
        cout << "Enter sum (9.9.9 - 1/4): ";
        cin >> pound >> ch >> shilling >> ch >> pence >> ch >> dividend >> ch >> divisor;
        if(divisor == 2) {
            dividend = dividend * 4;
        }
        if(divisor == 4) {
            dividend = dividend * 2;
        }
        eight = dividend;
    }
    void putSterling() const {
        Sterling::putSterling();
        cout << " - ";
        switch(eight) {
            case 2:
                cout << "1/4" << endl;
                break;
            case 4:
                cout << "1/2" << endl;
                break;
            case 6:
                cout << "3/4" << endl;
                break;
            default:
                cout << eight << "/8" << endl;
        }
    }
    operator double() const {
        return (Sterling::operator double() + eight / 1920);
    }
    Sterfrac operator+(Sterfrac s) const {
        return Sterfrac(double(Sterfrac(pound, shilling, pence, eight)) + double(s));
    }
    Sterfrac operator-(Sterfrac s) const {
        return Sterfrac(double(Sterfrac(pound, shilling, pence, eight)) + double(s));
    }
    Sterfrac operator*(double n) const {
        return Sterfrac(double(Sterfrac(pound, shilling, pence, eight)) * n);
    }
    double operator/(Sterfrac s) const {
        return double(Sterfrac(pound, shilling, pence, eight)) / double(s);
    }
    Sterfrac operator/(double n) const {
        return Sterfrac(double(Sterfrac(pound, shilling, pence, eight)) / n);
    }
};

int main() {
    Sterfrac s1, s2, s;
    double n;
    cout << "1. ";
    s1.getSterling();
    cout << "2. ";
    s2.getSterling();
    cout << "1. In pounds: " << ios::fixed << setprecision(2) << double(s1) << endl;
    cout << "2. In pounds: " << ios::fixed << setprecision(2) << double(s2) << endl;

    s = s1 + s2;
    cout << "Sum: ";
    s.putSterling();

    s = s1 - s2;
    cout << "Difference: ";
    s.putSterling();

    s = s1 * 2.0;
    cout << "Product: ";
    s.putSterling();

    n = s1 / s2;
    cout << "Qoutient: " << n << endl;

    s = s1 / 2.0;
    cout << "Quotient: ";
    s.putSterling();

    return 0;
}