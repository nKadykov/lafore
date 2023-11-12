#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    const int MAX = 20;
    char str[MAX];
    cout << "\nEnter string: ";
    cin >> setw(MAX) >> str;
    cout << "You entered " << str << '\n';
    return 0;
}