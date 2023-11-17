#include <iostream>
using namespace std;

int main() {
    char str1[] = "Array";
    char* str2 = "Pointer";

    cout << str1 << '\n';
    cout << str2 << '\n';

    // str1++;
    str2++;

    cout << str2 << '\n';

    return 0;
}