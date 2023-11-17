#include <iostream>
using namespace std;

int main() {
    int var1 = 11;
    int var2 = 22;

    int* ptr;
    ptr = &var1;
    cout << *ptr << '\n';

    ptr = &var2;
    cout << *ptr << '\n';
    cout << *ptr << '\n';

    return 0;
}