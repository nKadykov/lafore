#include <iostream>
using namespace std;

int main() {
    double dep;
    double sum;
    double rate;
    int years = 0;
    cout << "Enter deposite: ";
    cin >> dep;
    cout << "Enter rate: ";
    cin >> rate;
    cout << "Enter sum: ";
    cin >> sum;
    for(int i = dep; i < sum; i += (i * (rate / 100))) {
        years += 1;
    }
    cout << "Years: " << years;
    return 0;
}