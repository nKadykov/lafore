#include <iostream>
using namespace std;

class Parent {
protected:
    int basedata;
};

class Child1 : public Parent {};

class Child2 : public Parent {};

class Grandchild : public Child1, public Child2 {
public:
    int getdata() {
        // return basedata;
        return 0;
    }
};

int main() {
    return 0;
}