#include <iostream>
using namespace std;

class Int {
    int number;
public:
    Int() : number(0) {}
    Int(int n) : number(n) {}
    void output() {
        cout << number << '\n';
    }
    void sum(Int a, Int b) {
        number = a.number + b.number; 
    }
    Int operator+(Int);
    Int operator-(Int);
    Int operator*(Int);
    Int operator/(Int);
    void Error(int);
};

int main() {
    Int a(10), b(2);
    Int s, r, p, q;
    s = a + b;
    r = a - b;
    p = a * b;
    q = a / b;
    s.output();
    r.output();
    p.output();
    q.output();
    return 0;
}

Int Int::operator+(Int i) {
    int sum = number + i.number;
    Error(sum);
    return Int(sum);
}

Int Int::operator-(Int i) {
    int res = number - i.number;
    Error(res);
    return Int(res);
}

Int Int::operator*(Int i) {
    int prod = number * i.number;
    Error(prod);
    return Int(prod);
}

Int Int::operator/(Int i) {
    int quot = number / i.number;
    Error(quot);
    return Int(quot);
}

void Int::Error(int n) {
    if(n > INT_MAX || n < INT_MIN) {
        cout << "Error\n";
        exit(1);
    }
}