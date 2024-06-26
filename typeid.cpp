#include <iostream>
#include <typeinfo>
using namespace std;

class Base {
    virtual void virtFunc() {}
};

class Derv1 : public Base {};

class Derv2 : public Base {};

void displayName(Base* pB) {
    cout << "\nPointer to object of class ";
    cout << typeid(*pB).name();
}

int main() {
    Base* pBase = new Derv1;
    displayName(pBase);
    pBase = new Derv2;
    displayName(pBase);

    return 0;
}