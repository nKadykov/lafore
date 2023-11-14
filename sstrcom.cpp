#include <iostream>
#include <cstring>
using namespace std;

int main() {
    string aName = "Ivan";
    string userName;

    cout << "Enter name: ";
    cin >> userName;

    if(userName == aName) {
        cout << "Hello, Ivan\n";
    }
    else if (userName < aName) {
        cout << "Your name before name Ivan\n";
    }
    else {
        cout << "Your name after name Ivan\n";
    }

    int n = userName.compare(0, 2, aName, 0, 2);
    cout << "First letters ";
    if(n == 0) {
        cout << "are equal ";
    }
    else if(n < 0) {
        cout << " before ";
    }
    else {
        cout << " after ";
    }
    cout << aName.substr(0, 2) << '\n';
    return 0;
}