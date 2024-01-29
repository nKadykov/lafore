#include <iostream>
using namespace std;

int main() {
    int intVar = 150000000000;
    intVar = (intVar * 10) / 10;
    cout << "Value is " << intVar << endl;
    intVar = 150000000000;
    intVar = (static_cast<double>(intVar) * 10) / 10;
    cout << "intVar is " << intVar << endl;
}