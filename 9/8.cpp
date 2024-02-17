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
    Pstring(): String() {}
    Pstring(char s[]): String(s) {}
};

class Pstring2 : public Pstring {
public:
    Pstring2(): Pstring() {}
    Pstring2(char s[]): Pstring(s) {}
    Pstring& left(string s1, int n) {
        for(int i = 0; i < n; i++) {
            str[i] = s1[i];
        }
        return *this;
    }
    Pstring2& mid(string s1, int s, int n) {
        int j = 0;
        for(int i = s - 1; i < (s + n - 1); i++) {
            str[j++] = s1[i];
        }
        return *this;
    }
    Pstring2& right(string s1, int n) {
        int j = 0;
        for(int i = s1.size() - n; i < s1.size(); i++) {
            str[j++] = s1[i];
        }
        return *this;
    }
};

int main() {
    Pstring2 s;
    string str = "12345";
    s.left(str, 2);
    s.display();
    s.mid(str, 2, 3);
    s.display();
    s.right(str, 3);
    s.display();

    return 0;
}