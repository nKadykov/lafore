#include <iostream>
using namespace std;

class A {
public:
    virtual void func();
};

class B : public A {
};

class C : public A {
};

class D : public B, public C {
};

int main() {
    D objD;
    // objD.func();
    return 0;
}