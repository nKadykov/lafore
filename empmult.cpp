#include <iostream>
using namespace std;
const int LEN = 80;

class Student {
    char school[LEN];
    char degree[LEN];
public:
    void getedu() {
        cout << "Enter name of school: ";
        cin >> school;
        cout << "Enter degree: ";
        cin >> degree;
    }
    void putedu() const {
        cout << "\nSchool: " << school;
        cout << "\nDegree: " << degree;
    }
};

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
        cout << "\n:Last name: " << name;
        cout << "\nNumber: " << number;
    }
};

class Manager : private Employee, private Student {
    char title[LEN];
    double dues;
public:
    void getdata() {
        Employee::getdata();
        cout << "Enter duty: ";
        cin >> title;
        cout << "Enter sum: ";
        cin >> dues;
        Student::getedu();
    }
    void putdata() const {
        Employee::putdata();
        cout << "\nDuty: " << title;
        cout << "\nSum: " << dues;
        Student::putedu();
    }
};

class Scientist : private Employee, private Student {
    int pubs;
public:
    void getdata() {
        Employee::getdata();
        cout << "Enter number of publics: ";
        cin >> pubs;
        Student::getedu();
    }
    void putdata() {
        Employee::putdata();
        cout << "\nNumber of publics: " << pubs;
        Student::putedu();
    }
};

class Laborer : public Employee {
};

int main() {
    Manager m1;
    Scientist s1, s2;
    Laborer l1;

    cout << "\nEnter information about first manager: ";
    m1.getdata();

    cout << "\nEnter information about first manager: ";
    s1.getdata();

    cout << "\nEnter information about second scientist: ";
    s2.getdata();

    cout << "\nEnter information about first laborer: ";
    l1.getdata();

    cout << "\nInformation about first scientist: ";
    m1.putdata();

    cout << "\nInormation about first scientist";
    s1.putdata();

    cout << "\nInformation about second scientist: ";
    s2.putdata();

    cout << "\nInformation about << first laborer: ";
    l1.putdata();

    return 0;
}