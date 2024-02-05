#include <iostream>
using namespace std;

double power(double n, int p = 2) {
    double result = 1;
    for(int i = 0; i < p; i++) {
        result = result * n;
    }
    cout << "Double: " << result << '\n';
    return result;
}

double power(int n, int p = 2) {
    double result = 1;
    for(int i = 0; i < p; i++) {
        result = result * n;
    }
    cout << "Int: " << result << '\n';
    return result;
}

double power(long n, int p = 2) {
    double result = 1;
    for(int i = 0; i < p; i++) {
        result = result * n;
    }
    cout << "Long: " << result << '\n';
    return result;
}

double power(float n, int p = 2) {
    double result = 1;
    for(int i = 0; i < p; i++) {
        result = result * n;
    }
    cout << "Float: " << result << '\n';
    return result;
}

double power(char n, int p = 2) {
    double result = 1;
    int number = n - '0';
    for(int i = 0; i < p; i++) {
        result = result * number;
    }
    cout << "Char: " << result << '\n';
    return result;
}

int main() {
    double n;
    int ni = 10;
    long nl = 1000000000;
    char nc = '2';
    float nf = 2.1;
    int p;

    power(ni);
    power(nl);
    power(nc);
    power(nf);

    cout << "Enter number and degree: ";
    cin >> n >> p;
    
    cout << "Result: " << power(n, p);

    return 0;
}