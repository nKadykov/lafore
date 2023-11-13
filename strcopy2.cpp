#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str1[] = "Qwe rty asd fgh";
    const int MAX = 80;
    char str2[MAX];
    strcpy(str2, str1);
    cout << str2 << '\n';
    return 0;
}