#include <iostream>
using namespace std;

class Class {
    static int count;
public:
    Class() {
        count++;
    }
    void getcount() {
        cout << count << endl;
    }
};

int Class::count = 0;

int main() {
    Class o1, o2, o3;
    o1.getcount();
    o2.getcount();
    o3.getcount();

    return 0;
}