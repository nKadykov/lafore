#include <iostream>
using namespace std;

class Sterling {
    long pound;
    int shilling;
    int pence;
public:
    Sterling() : pound(0), shilling(0), pence(0) {}
    Sterling(double);
    Sterling(long p, int sh, int pen) : pound(p), shilling(sh), pence(pen) {}
    void getSterling();
    void putSterling();
    Sterling operator+(Sterling);
    Sterling operator-(Sterling);
    Sterling operator*(double);
    double operator/(Sterling);
    Sterling operator/(double);
    operator double();
};

int main() {
    Sterling s1, s2, result;
    double n;
    s1.getSterling();
    s2.getSterling();
    cout << "Enter n: ";
    cin >> n;
    result = s1 + s2;
    cout << "Sterling + Sterling: ";
    result.putSterling();
    result = s1 - s2;
    cout << "Sterling - Sterling: ";
    result.putSterling();
    result = s1 * n;
    cout << "Sterling * double: ";
    result.putSterling();
    result = s1 / n;
    cout << "Sterling / double: ";
    result.putSterling();
    cout << "Sterling / Sterling: " << s1 / s2;
    return 0;
}

Sterling::Sterling(double money) {
    int m = static_cast<int>(money);
    pence = m % 12;
    pound = m / 20 / 12;
    shilling = (m / 12) % 20;
}

void Sterling::getSterling() {
    char point = '.';
    cout << "Enter sterlings: (example 9.19.11): ";
    cin >> pound >> point >> shilling >> point >> pence;
}

void Sterling::putSterling() {
    cout << pound << '.' << shilling << '.' << pence << '\n';
    if(pound < 0 || shilling < 0 || shilling > 19 || pence < 0 || pence > 11) {
        cout << "Incorrect input\n";
    }
}

Sterling Sterling::operator+(Sterling s) {
    return Sterling(double(Sterling(pound, shilling, pence)) + double(s));
}

Sterling Sterling::operator-(Sterling s) {
    return Sterling(double(Sterling(pound, shilling, pence)) - double(s));
}

Sterling Sterling::operator*(double n) {
    return Sterling(double(Sterling(pound, shilling, pence)) * n);
}

double Sterling::operator/(Sterling s) {
    return (double(Sterling(pound, shilling, pence)) / double(s));
}

Sterling Sterling::operator/(double n) {
    return Sterling(double(Sterling(pound, shilling, pence)) / n);
}

Sterling::operator double() {
    return (pound * 20 * 12 + shilling * 12 + pence);
}