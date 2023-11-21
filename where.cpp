#include <iostream>
using namespace std;

class Where {
    char charray[10];
public:
    void reveal() {
        cout << "\nMy address is " << this;
    }
};

int main() {
    Where w1, w2, w3;
    w1.reveal();
    w2.reveal();
    w3.reveal();

    return 0;
}