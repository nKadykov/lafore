#include <iostream>
using namespace std;

class toolBooth {
    unsigned int carNumber;
    double sumValue;
public:
    toolBooth() : carNumber(0), sumValue(0) {}
    void payingCar() { 
        carNumber++;
        sumValue += 0.5;
    }
    void nopayCar() {
        carNumber++;
    }
    void display() const{
        cout << carNumber << ' ' << sumValue << '\n';
    }
};

int main() {
    char button;
    cout << "Enter a or b: ";
    toolBooth tool;
    while(cin >> button) {
        if(button == 'a') {
            tool.payingCar();
        }
        else {
            tool.nopayCar();
        }
        tool.display();
    }

    return 0;
}