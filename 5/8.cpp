#include <iostream>
using namespace std;

void swap(int&, int&);

int main() {
    int a, b;
    cout << "Enter numbers:\na: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    swap(a, b);
    cout << "a: " << a << ", b: " << b;
    return 0;
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}