#include <iostream>
using namespace std;

class Int {
    int integer;
public:
    void set() { integer = 0; }
    void show() { cout << integer << '\n'; }
    int add(int a, int b) {
        int sum = a + b;
        return sum;
    }
};

int main() {
    Int i;
    i.set();
    i.show();
    cout << i.add(10, 2) << '\n';

    return 0;
}