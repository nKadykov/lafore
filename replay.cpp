#include <iostream>
using namespace std;

int main() {
    int age[4];
    for(int i = 0; i < 4; i++) {
        cout << "Enter age: ";
        cin >> age[i];
    }
    for(int i = 0; i < 4; i++) {
        cout << "Your age: " << age[i] << '\n';
    }
    return 0;
}