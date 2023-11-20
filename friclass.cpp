#include <iostream>
using namespace std;

class Alpha {
    int data;
public:
    Alpha() : data(99) {}
    friend class Beta;
};


class Beta {
public:
    void func1(Alpha a) {
        cout << "\ndata1 = " << a.data;
    }
    void func2(Alpha a) {
        cout << "\ndata1 = " << a.data;
    }
};

int main() {
    Alpha a;
    Beta b;

    b.func1(a);
    b.func2(a);

    cout << '\n';

    return 0;
}