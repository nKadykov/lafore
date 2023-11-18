#include <iostream>
using namespace std;

class Distance {
    int feet;
    float inches;
public:
    void getdist() {
        cout << "\nEnter feet: ";
        cin >> feet;
        cout << "\nEnter inches: ";
        cin >> inches;
    }
    void showdist() {
        cout << feet << "\' - " << inches << "\"\n";
    }
};

int main() {
    Distance dist;
    dist.getdist();
    dist.showdist();

    Distance* distptr;
    distptr = new Distance;
    distptr->getdist();
    distptr->showdist();
    cout << '\n';

    return 0;
}