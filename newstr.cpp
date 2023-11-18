#include <iostream>
#include <cstring>
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
};

int main() {
    String s1 = "Mmm";
    cout << "s1 = ";
    s1.display();

    return 0;
}