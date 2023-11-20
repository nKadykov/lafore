#include <iostream>
using namespace std;

class Base {
public: 
    virtual ~Base() {
        cout << "Base is deleted\n";
    }
};

class Derv : public Base {
public:
    ~Derv() {
        cout << "Derv is deleted\n";
    }
};

int main() {
    Base* pBase = new Derv;
    delete pBase;
    return 0;
}