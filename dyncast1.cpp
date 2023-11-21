#include <iostream>
#include <typeinfo>
using namespace std;

class Base {
    virtual void vertFunc() {}
};

class Derv1 : public Base {};

class Derv2 : public Base {};

bool isDerv1(Base* pUnknown) {
    Derv1* pDerv1;
    if(pDerv1 = dynamic_cast<Derv1*>(pUnknown)) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    Derv1* d1 = new Derv1;
    Derv2* d2 = new Derv2;

    if(isDerv1(d1)) {
        cout << "\nd1 - component of class Derv1";
    }
    else {
        cout << "\nd1 - not component of class Derv1";
    }
    if(isDerv1(d2)) {
        cout << "\nd2 - component of class Derv1";
    }
    else {
        cout << "\nd2 - not component of class Derv1";
    }

    return 0;
}