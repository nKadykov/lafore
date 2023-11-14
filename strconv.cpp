#include <iostream>
#include <cstring>
using namespace std;

class String {
    enum {SIZE = 80};
    char str[SIZE];
public:
    String() {
        str[0] = '\x0';
    }
    String(char s[]) {
        strcpy(str, s);
    }
    void display() const {
        cout << str;
    }
    operator char*() {
        return str;
    }
};

int main() {
    String s1;
    char xstr[] = "Friends! ";
    s1 = xstr;
    s1.display();

    String s2 = "We won!";

    cout << static_cast<char*>(s2);
    cout << '\n';

    return 0;
}