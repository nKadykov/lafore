#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

class String {
    char* str;
public:
    String(char* s) {
        int length = strlen(s);
        str = new char[length + 1];
        strcpy(str, s);
    }
    ~String() {
        cout << "Delete string\n";
        delete[] str;
    }
    void display() {
        cout << str << '\n';
    }
    void upit();
};

void String::upit() {
    char *ptrch = str;
    while(*ptrch) {
        *ptrch = toupper(*ptrch);
        ptrch++;
    }
}

int main() {
    String s1 = "My home is very, very big";
    cout << "s1 = ";
    s1.display();
    s1.upit();
    cout << "s1 = ";
    s1.display();

    return 0;
}