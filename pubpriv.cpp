#include <iostream>
using namespace std;

class A {
    int privdataA;
protected:
    int protdataA;
public:
    int pubdataA;
};

class B : public A {
public:
    void func() {
        int a;
        // a = privdataA;
        a = protdataA;
        a = pubdataA;
    }
};

class C : private A {
public:
    void func() {
        int a;
        // a = privdatA;
        a = protdataA;
        a = pubdataA;
    }
};

int main() {
    int a;
    B objB;
    // a = objB.privdataA;
    // a = objB.protdataA;
    a = objB.pubdataA;

    C objC;
    // a = objC.privdataA;
    // a = objC.protdataA;
    // a = objC.pubdataA;

    return 0;
}