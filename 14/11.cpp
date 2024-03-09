#include <iostream>
#include <cstring>
#include <cstdlib>

class String {
    enum {SIZE = 15};
    char str[SIZE];
public:
    class Long {
    public:
        int num;
        Long(int n): num(n) {}
    };
    String() {
        strcpy(str, "");
    }
    String(const char s[]) {
        if(strlen(s) < SIZE) {
            strcpy(str, s);
        }
        else {
            throw Long(1);
        }
    }
    void display() const {
        std::cout << str;
    }
    String operator+(String ss) const {
        String temp;
        if(strlen(str) + strlen(ss.str) < SIZE) {
            strcpy(temp.str, str);
            strcat(temp.str, ss.str);
        }
        else {
            throw Long(2);
        }
        return temp;
    }
};

int main() {
    try {
        String s1("\nMerry Christmas! ");
        String s2("Happy New Year!");
        String s3;

        s1.display();
        s2.display();
        s3.display();
        
        s3 = s1 + s2;

        s3.display();
    }
    catch(String::Long err) {
        switch(err.num) {
            case 1:
                std::cout << "Constructor error" << std::endl;
                break;
            case 2:
                std::cout << "Sum error" << std::endl;
                break;
        }
        exit(1);
    }

    return 0;
}