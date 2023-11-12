#include <iostream>
using namespace std;

class Distance {
    int feet;
    float inches;
public:
    void getdist() {
        cout << "\nEnter feet: ";
        cin >> feet;
        cout << "Enter inches: ";
        cin >> inches;
    }
    void showdist() const {
        cout << feet << "\'-" << inches << '\"';
    }
};

int main() {
    Distance dist[100];
    int n = 0;
    char ans;

    do {
        cout << "Enter number: " << n + 1;
        dist[n++].getdist();
        cout << "Continue enter(y/n)?:";
        cin >> ans;
    } while(ans != 'n');

    for(int j = 0; j < n; j++) {
        cout << "\nDistance " << j + 1 << " : ";
        dist[j].showdist();
    }

    return 0;
}