#include <iostream>
using namespace std;

double power(double n, int p = 2) {
    double result = 1;
    for(int i = 0; i < p; i++) {
        result = result * n;
    }
    return result;
}

int main() {
    double n;
    int p;

    cout << "Enter number and degree: ";
    cin >> n >> p;
    
    cout << "Result: " << power(n, p);

    return 0;
}