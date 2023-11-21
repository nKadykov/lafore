#include <iostream>
#include <cstring>
using namespace std;

class StrCount {
    int count;
    char* str;
    friend class String;
    StrCount(char* s) {
        int length = strlen(s);
        str = new char[length + 1];
        strcpy(str, s);
        count  = 1;
    }
    ~StrCount() {
        delete[] str;
    }
};

class String {
    StrCount* psc;
public:
    String() {
        psc = new StrCount("NULL");
    }
    String(char* s) {
        psc = new StrCount(s);
    }
    String(String& S) {
        cout << "\nCopy constructor";
        psc = S.psc;
        (psc->count)++;
    }
    ~String() {
        if(psc->count == 1) {
            delete psc;
        }
        else {
            (psc->count)--;
        }
    }
    void display() {
        cout << psc->str;
        cout << " (addr = " << psc << ")";
    }
    String& operator = (String& S) {
        cout << "\nAssignment";
        if(psc->count == 1) {
            delete psc;
        }
        else {
            (psc->count)--;
        }
        psc = S.psc;
        (psc->count)++;
        return *this;
    }
};

int main() {
    String s3 = "Qwerty";
    cout << "\ns3 = ";
    s3.display();

    String s1, s2;
    s1 = s2 = s3;
    cout << "\ns1 = ";
    s1.display();
    cout << "\ns2 = ";
    s2.display();

    return 0;
}