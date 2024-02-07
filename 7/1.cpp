#include <iostream>
#include <cstring>
using namespace std;

void reversit(char []);

int main() {
    const int MAX = 80;
    char str[MAX];
    cout << "Enter string: ";
    cin.get(str, MAX);
    reversit(str);
    cout << "New string: ";
    cout << str << endl;
    return 0;
}

void reversit(char s[]) {
    int len = strlen(s);
    for(int i = 0; i < len / 2; i++) {
        char temp = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = temp;
    }
}