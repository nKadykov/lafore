#include <iostream>
using namespace std;

int main() {
    void centimize(double*);

    double var = 10.0;
    cout << "var = " << var << " inches\n";

    centimize(&var);
    cout << "var = " << var << " centimeters\n";

    return 0;
}

void centimize(double* ptrd) {
    *ptrd *= 2.54;
}