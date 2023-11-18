#include <iostream>
using namespace std;

class Distance {
    int feet;
    float inches;
public:
    void getdist() {
        cout << "\nEnter feet:";
        cin >> feet;
        cout << "Enter inches:";
        cin >> inches;
    }
    void showdist() {
        cout << feet << "\' - " << inches << "\"";
    }
};

int main() {
    Distance& dist = *(new Distance);
    dist.getdist();
    dist.showdist();

    return 0;
}