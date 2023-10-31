#include <iostream>
using namespace std;

int main() {
    const int SIZE = 6;
    double sales[SIZE];
    cout << "Enter sales un each day:";
    for(int i = 0; i < SIZE; i++) {
        cin >> sales[i];
    }
    double total = 0;
    for(int i = 0; i < SIZE; i++) {
        total += sales[i];
    }
    double average = total / SIZE;
    cout << "Average: " << average;
    return 0;
}