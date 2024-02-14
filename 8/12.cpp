#include <iostream>
#include <iomanip>
using namespace std;

class Sterling;
class bMoney;

class Sterling {
    long pound;
    int shilling;
    int pence;
public:
    Sterling() : pound(0), shilling(0), pence(0) {}
    Sterling(double);
    Sterling(long p, int sh, int pen) : pound(p), shilling(sh), pence(pen) {}
    Sterling(const bMoney);
    void getSterling();
    void putSterling();
    Sterling operator+(Sterling);
    Sterling operator-(Sterling);
    Sterling operator*(double);
    double operator/(Sterling);
    Sterling operator/(double);
    operator double();
    long getpounds();
    int getshilling();
    int getpence();
};

class bMoney {
    string str;
    long double sum;
public:
    bMoney() : sum(0.0) {}
    bMoney(Sterling);
    void mstold();
    void display() const;
    long double get() const;
};

int main() {
    Sterling s1, s2;
    bMoney d1, d2;
    s1.getSterling();
    d1.mstold();
    s2 = d1;
    d2 = s1;
    s2.putSterling();
    d1.display();
    return 0;
}

Sterling::Sterling(const bMoney m) {
    long double dollar = m.get();
    int pen = (dollar / 50) * 20 * 12;
    pound = pen / (20 * 12);
    shilling = (pen / 12) % 20;
    pence = pen % 12;
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

long Sterling::getpounds() {
    return pound;
}

int Sterling::getshilling() {
    return shilling;
}

int Sterling::getpence() {
    return pence;
}

bMoney::bMoney(Sterling s) {
    long p = s.getpounds();
    int sh = s.getshilling();
    int pen = s.getpence();
    sum = (p * 50) + ((50 / 20) * sh) + ((50 / 20 / 12) * pen);
}

void bMoney::mstold() {
    cout << "Enter amount: ";
    getline(cin, str);
    int l = str.size();
    int n = 0;
    string num;
    for(int j = 0; j < l; j++) {
        if(str[j] != ',' && str[j] != '$') {
            num += str[j];
        }
    }
    sum = stold(num);
}

void bMoney::display() const {
    cout << setiosflags(ios::fixed) << setiosflags(ios::showpoint) << setprecision(2) << '$' << sum << '\n';
}

long double bMoney::get() const {
    return sum;
}