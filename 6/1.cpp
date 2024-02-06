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
};

int main() {
    Int i1(7);
    Int i2(11);
    Int i3;

    i3.sum(i1, i2);
    
    cout << "\ni3 = ";
    i3.output();

    return 0;
}