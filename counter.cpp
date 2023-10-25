#include <iostream>
using namespace std;

class Counter {
    unsigned int count;
public:
    Counter() : count(0) { cout << "Constructor\n"; }
    void int_count() { count++; }
    int get_count() { return count; }
};

int main() {
    Counter c1, c2;
    cout << "\nc1 = " << c1.get_count();
    cout << "\nc2 = " << c2.get_count();
    c1.int_count();
    c2.int_count();
    c2.int_count();
    cout << "\nc1 = " << c1.get_count();
    cout << "\nc2 = " << c2.get_count();
    cout << "\n";

    return 0;
}