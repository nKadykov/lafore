#include <iostream>
using namespace std;

int main() {
    static int var1 = 11;
    static int var2 = 22;
    static int var3 = 33;

    cout << &var1 << '\n' << &var2 << '\n' << &var3;
    
    return 0;
}