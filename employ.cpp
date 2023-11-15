#include <iostream>
using namespace std;

const int LEN = 80;

class Employee {
    char name[LEN];
    unsigned long number;
public:
    void getdata() {
        cout << "\nEnter last name: ";
        cin >> name;
        cout << "Enter number: ";
        cin >> number;
    }
    void putdata() const {
        cout << "\nLast name " << name;
        cout << "\nNumber: " << number;
    }
    void putdata() {
        cout << "\nLast name: " << name;
        cout << "\nNumber: " << number;
    }
};

class Manager: public Employee {
    char title[LEN];
    double dues;
public:
    void getdata() {
        Employee::getdata();
        cout << "Enter title: ";
        cin >> title;
        cout << "\nSum: ";
        cin >> dues; 
    }
};

class Scientist: public Employee {
    int pubs;
public:
    void getdata() {
        Employee::getdata();
        cout << "Enter number of publics: ";
        cin >> pubs;
    }
    void putdata() const {
        Employee::putdata();
        cout << "\nNumber of publics: " << pubs;
    }
};

class Laborer: public Employee {

};

int main() {
    Manager m1, m2;
    Scientist s1;
    Laborer l1;

    cout << '\n';
    cout << "Enter information about first manager";
    m1.getdata();

    cout << "Enter information about second manager";
    m2.getdata();

    cout << "Enter information about first scietist";
    s1.getdata();

    cout << "Enter information about first laborer";
    l1.getdata();

    cout << "\nInformation about first manager: ";
    m1.putdata();

    cout << "\nInformation about second manager: ";
    m2.putdata();

    cout << "\nInformation about first scientist: ";
    s1.putdata();

    cout << "\nInformation abour first laborer: ";
    l1. putdata();

    return 0;
}