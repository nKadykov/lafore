#include <iostream>
using namespace std;

class Base {
public:
    virtual void show() {
        cout << "Base\n";
    }
};

class Derv1 : public Base {
public:
    void show() {
        cout << "Derv1\n";
    }
};

class Derv2 : public Base {
public:
    void show() {
        cout << "Derv2\n";
    }
};

int main() {
    Derv1 dv1;
    Derv2 dv2;
    Base* b;

    b = &dv1;
    b->show();
    b = &dv2;
    b->show();

    return 0;
}