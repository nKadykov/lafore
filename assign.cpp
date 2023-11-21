#include <iostream>
using namespace std;

class Alpha {
    int data;
public:
    Alpha() {}
    Alpha(int d) : data(d) {
        cout << "\nConstructor";
    }
    void display() {
        cout << data;
    }
    Alpha operator=(Alpha& a) {
        data = a.data;
        cout << "\nAssignment operator";
        return Alpha(data);
    }
};


int main() {
    Alpha a1(37);
    Alpha a2;

    a2 = a1;
    cout << "\na2 = ";
    a2.display();

    Alpha a3 = a2;
    cout << "\na3 = ";
    a3.display();

    return 0;
}