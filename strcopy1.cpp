#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str1[] = "Qwerty";
    const int MAX = 80;
    char str2[MAX];
    int j;
    for(j = 0; j < strlen(str1); j++) {
        str2[j] = str1[j];   
    }
    cout << str2 << '\n';
    return 0;
}