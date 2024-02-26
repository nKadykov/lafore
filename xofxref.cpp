#include <iostream>
using namespace std;

class Alpha {
    int data;
public:
    Alpha() {}
    Alpha(int d) {
        data = d;
    }
    Alpha(Alpha& a) {
        data = a.data;
        cout << "\nCopy constructor";
    }
    void display() {
        cout << data;
    }
    void operator = (Alpha& a) {
        data = a.data;
        cout << "\nAssignment operator";
    }
};

int main() {
    Alpha a1(37);
    Alpha a2;

    a2 = a1;
    cout << "\na2 = ";
    a2.display();
    Alpha a4 = a1;

    Alpha a3(a1);
    cout << "\na3 = ";
    a3.display();

    return 0;
}