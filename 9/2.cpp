#include <iostream>
#include <cstring>
using namespace std;

class String {
protected:
    enum {SZ = 20};
    char str[SZ];
public:
    String() {
        str[0] == '\0';
    }
    String(char s[]) {
        strcpy(str, s);
    }
    void display() const {
        cout << str << '\n';
    }
    operator char*() {
        return str;
    }
};

class Pstring : public String {
public:
    Pstring(char s[]);
};

int main() {
    Pstring s1 = "Qwekerhkwehkwjfjksdfhkjsdkjfhsdkjfshkdfjksdhkfjsdhkfjshdkfhksdfkjsdhkfjsdhkfjsdkfshdkjfhskdhfsjkdkhfskdfhksdhfksdhkfskdfhksdhfksdhkjfskdfhsjkdfhksdjfksdhfksdjkfsdkfskdjsfkjdfh";
    cout << "s1 = ";
    s1.display();
    Pstring s2 = "Qwewt";
    cout << "s2 = ";
    s2.display();
    return 0;
}

Pstring::Pstring(char s[]) {
    if(strlen(s) > SZ - 1) {
        for(int j = 0; j < SZ - 1; j++) {
            str[j] == s[j];
            str[j] == '\0';
        }
    }
    else {
        String(s);
    }
}