#include <iostream>
using namespace std;

class Person {
    char name[40];
public:
    void setName() {
        cout << "Enter name: ";
        cin >> name;
    }
    void printName() {
        cout << "\nName: " << name;
    }
};

int main() {
    Person* persPtr[100];
    int n = 0;
    char choice;

    do {
        persPtr[n] = new Person;
        persPtr[n]->setName();
        n++;
        cout << "Continue enter (y/n)?";
        cin >> choice;
    } while (choice == 'y');
    for(int i = 0; i < n; i++) {
        cout << "\nInformation about number: " << i + 1;
        persPtr[i]->printName();
    }
    return 0;
}