#include <iostream>
using namespace std;

class Class {
    static int count;
    int number = count;
public:
    Class() {
        count++;
    }
    void getcount() {
        cout << count << endl;
    }
    void getnumber() {
        cout << number << endl;
    }
};

int Class::count = 0;

int main() {
    Class o1, o2, o3;
    o1.getcount();
    o1.getnumber();
    o2.getcount();
    o2.getnumber();
    o3.getcount();
    o3.getnumber();

    return 0;
}