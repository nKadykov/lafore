#include <iostream>
using namespace std;

const int FSIZE = 50;
const int PSIZE = 50;
float fmemory[FSIZE];
int pmemory[PSIZE];
int fmem_top = 0;
int pmem_top = 0;

class Float {
    int addr;
public:
    Float(float value) {
        fmemory[fmem_top] = value;
        addr = fmem_top;
        fmem_top++;
    }
    int operator&() const {
        return addr;
    }
};

class ptrFloat {
    int addr;
public:
    ptrFloat(int value) {
        pmemory[pmem_top] = value;
        addr = pmem_top;
        pmem_top++;
    }
    float& operator*() const {
        return fmemory[pmemory[addr]];
    }
};

int main() {
    Float var1 = 1.234;
    Float var2 = 5.678;
    ptrFloat ptr1 = &var1;
    ptrFloat ptr2 = &var2;
    cout << "*ptr1 = " << *ptr1 << endl;
    cout << "*ptr2 = " << *ptr2 << endl;
    *ptr1 = 7.123;
    *ptr2 = 8.456;
    cout << "*ptr1 = " << *ptr1 << endl;
    cout << "*ptr2 = " << *ptr2 << endl;

    return 0;
}