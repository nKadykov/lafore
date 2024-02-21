#include <iostream>
using namespace std;

int compstr(const char*, const char*);

int main() {
    char* s1 = "abc";
    char* s2 = "abc";
    char* s3 = "bac";
    char* s4 = "acb";
    cout << compstr(s1, s2) << endl;
    cout << compstr(s1, s3) << endl;
    cout << compstr(s3, s4) << endl;
}

int compstr(const char* s1, const char* s2) {
    while(*s1 && *s2) {
        if(*s1 > *s2) {
            return 1;
        }
        else if(*s1 < *s2) {
            return -1;
        }
        s1++;
        s2++;
    }
    if(!*s1 && !*s2) {
        return 0;
    }
    else if(!*s1) {
        return -1;
    }
    else {
        return 1;
    }
}