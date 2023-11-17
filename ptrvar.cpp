#include <iostream>
using namespace std;

int main() {
    int var1 = 11;
    int var2 = 22;

    cout << &var1 << '\n' << &var2 << '\n';

    int *ptr;
    int *p;

    ptr = &var1;
    cout << ptr << '\n';

    ptr = &var2;
    cout << ptr << '\n';

    return 0;
}