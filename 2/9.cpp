#include <iostream>
using namespace std;

int main() {
    char dummychar = '/';
    int a;
    int b;
    int c;
    int d;
    cout << "Enter first: ";
    cin >> a >> dummychar >> b;
    cout << "Enter second: ";
    cin >> c >> dummychar >> d;
    cout << "Sum equals: " << (a * d + b * c) << '/' << (b * d);
    return 0;
}