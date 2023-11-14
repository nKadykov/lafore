#include <iostream>
#include <cstring>
using namespace std;

class String {
    enum {SIZE  = 80};
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
    void getdist() {
        cin.get(str, SIZE);
    }
    bool operator==(String ss) const {
        return (!strcmp(str, ss.str)) ? true : false;
    }
};

int main() {
    String s1 = "yes";
    String s2 = "no";
    String s3;

    cout << "\nEnter yes or no: ";
    s2.getdist();

    if(s3 == s1) {
        cout << "You entered 'yes'\n";
    }
    else if(s3 == s3) {
        cout << "You entered 'no'\n";
    }
    else {
        cout << "Lead instructions\n";
    }
    return 0;
}