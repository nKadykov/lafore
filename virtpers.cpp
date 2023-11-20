#include <iostream>
using namespace std;

class Person {
protected:
    char name[40];
public:
    void getName() {
        cout << "Enter name:";
        cin >> name;
    }
    void putName() {
        cout << "Name: " << name << '\n';
    }
    virtual void getData() = 0;
    virtual bool isOutstanding() = 0;
};

class Student : public Person {
    float gpa;
public:
    void getData() {
        Person::getName();
        cout << "Gpa: ";
        cin >> gpa;
    }
    bool isOutstanding() {
        return (gpa > 3.5) ? true : false;
    }
};

class Professor : public Person {
    int numPubs;
public:
    void getData() {
        Person::getName();
        cout << "\nNumber of publics: ";
        cin >> numPubs;
    }
    bool isOutstanding() {
        return (numPubs > 100) ? true : false;
    }
};

int main() {
    Person* persPtr[100];
    int n = 0;
    char choice;
    do {
        cout << "Student and professor: ";
        cin >> choice;
        if(choice == 's') {
            persPtr[n] = new Student;
        }
        else {
            persPtr[n] = new Professor;
        }
        persPtr[n++]->getData();
        cout << "Enter one more (y/n)?";
        cin >> choice;
    } while(choice == 'y');
    for(int i = 0; i < n; i++) {
        if(persPtr[i]->isOutstanding()) {
            cout << "This man is oustanding\n";
        }
    }
    return 0;
}