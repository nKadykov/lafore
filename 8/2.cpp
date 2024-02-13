#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class String {
    enum {SIZE = 80};
    char str[SIZE];
public:
    String() {
        strcpy(str, "");
    }
    String(char s[]) {
        strcpy(str, s);
    }
    void display() const {
        cout << str;
    }
    String operator+(String ss) const {
        String temp;
        if(strlen(str) + strlen(ss.str) < SIZE) {
            strcpy(temp.str, str);
            strcat(temp.str, ss.str);
        }
        else {
            cout << "\nFull\n";
            exit(1);
        }
        return temp;
    }
    String operator+=(String ss) {
        if(strlen(str) + strlen(ss.str) < SIZE) {
            strcat(str, ss.str);
        }
        else {
            cout << "Full\n";
            exit(1);
        }
        return String(str);
    }
};

int main() {
    String s1 = "Merry Christmas! ";
    String s2 = "Happy New Year!\n";
    String s3;

    s1.display();
    s2.display();
    s3.display();

    s3 = s1 + s2;
    s3.display();

    s3 = s1 += s2;
    s3.display();
    s1 += s2;
    s1.display();

    return 0;
}