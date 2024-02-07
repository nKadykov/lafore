#include <iostream>
using namespace std;

const int SIZE = 10;

int maxint(int sales[]);

int main() {
    int num[SIZE];
    cout << "Enter numbers: ";
    for(int i = 0; i < SIZE; i++) {
        cin >> num[i];
    }
    cout << maxint(num);
    return 0;
}

int maxint(int n[]) {
    int max = INT_MIN;
    for(int i = 0; i < SIZE; i++) {
        if(n[i] > max) {
            max = n[i];
        }
    }
    return max;
}