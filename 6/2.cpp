#include <iostream>
#include <conio.h>
using namespace std;

class tollBooth {
    unsigned int number;
    double sum;
public:
    tollBooth() : number(0), sum(0) {}
    void payingCar() {
        number++;
        sum += 0.5;
    }
    void nopayCar() {
        number++;
    }
    void display() const {
        cout << "Number: " << number << ", sum: " << sum << '\n';
    }
};

int main() {
    tollBooth pay;
    char ch;
    while(ch != 'e') {
        cout << "Enter 'p' to pay and 'n' not to pay: ";
        ch = getche();
        if(ch == 'p') {
            pay.payingCar();
        }
        if(ch == 'n') {
            pay.nopayCar();
        }
        pay.display();
    }

    return 0;
}