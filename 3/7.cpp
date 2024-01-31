#include <iostream>
using namespace std;

int main() {
    double dep;
    int year;
    double rate;
    cout << "Enter deposit: ";
    cin >> dep;
    cout << "Enter years: ";
    cin >> year;
    cout << "Enter rate: ";
    cin >> rate;
    for(int i = 0; i < year; i++) {
        dep += (dep * (rate / 100));
    }
    cout << "After " << year << " years you will get " << dep << " dollars.";
    return 0;
}