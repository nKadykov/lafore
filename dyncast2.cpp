#include <iostream>
#include <typeinfo>
using namespace std;

class Base {
protected:
    int ba;
public:
    Base() : ba(0) {}
    Base(int b) : ba(b) {}
    virtual void vertFunc() {}
    void show() {
        cout << "\nBase: ba = " << ba;
    }
};

class Derv : public Base {
    int da;
public:
    Derv(int b, int d) : da(d), Base(b) {}
    void show() {
        cout << "\nDerv: ba = " << ba << ", da = " << da;
    }
};

int main() {
    Base* pBase = new Base(10);
    Derv* pDerv = new Derv(21, 22);

    pBase = dynamic_cast<Base*>(pDerv);
    pBase->show();

    pBase = new Derv(31, 32);

    pDerv = dynamic_cast<Derv*>(pBase);
    pDerv->show();

    return 0;
}