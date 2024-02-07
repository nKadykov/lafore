#include <iostream>
#include <string>
using namespace std;

class Employee {
    string name;
    long number;
public:
    void getdata() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter number: ";
        cin >> number;
    }
    void putdata() {
        cout << "Name: " << name << endl;
        cout << "Number: " << number << endl;
    }
};

int main() {
    Employee e[100];
    int n = 0;
    char ch;
    do {
        cout << "Enter info about employee number " << n + 1 << '\n';
        e[n++].getdata();
        cout << "Continue? (y / n): ";
        cin >> ch;
    } while(ch != 'n');
    for(int i = 0; i < n; i++) {
        cout << "Employee number: " << i + 1 << '\n';
        e[i].putdata();
    }
    cout << endl;
    return 0;
}