#include <iostream>
using namespace std;

int main() {
    int intvar;
    float flovar;

    int* ptrint;
    float* ptrflo;
    void* ptrvoid;

    ptrint = &intvar;
    // ptrint = &flovar;
    // ptrflo = &intvar;
    ptrflo = &flovar;

    ptrvoid = &intvar;
    ptrvoid = &flovar;

    return 0;
}