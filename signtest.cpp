#include <iostream>
using namespace std;

int main() {
    int signedVar = 150000000;
    unsigned int unsignVar = 150000000;
    signedVar = (signedVar * 2) / 3;
    unsignVar = (unsignVar * 2) / 3;
    cout << "Signed var is " << signedVar << endl;
    cout << "Unsigned var is " << unsignVar << endl;
    return 0;
}