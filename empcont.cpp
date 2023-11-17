#include <iostream>
#include <string>
using namespace std;

class Student {
    string school;
    string degree;
public:
    void getedu() {
        cout << "\nEnter school: ";
        cin >> school;
        cout << "\nEnter degree: ";
        cin >> degree;
    }
    void putedu() const {
        cout << "\nSchool: " << school;
        cout << "\nDegree: " << degree;
    }
};

class Employee {
    string name;
    unsigned long number;
public:
    void getdata() {
        cout << "\nEnter last name: ";
        cin >> name;
        cout << "\nEnter number: ";
        cin >> number;
    }
    void putdata() const {
        cout << "\nLast name: " << name;
        cout << "\nNumber: " << number;
    }
};

class Manager {
    string title;
    double dues;
    Employee emp;
    Student stu;
public:
    void getdata() {
        emp.getdata();
        cout << "Enter duty: ";
        cin >> title;
        cout << "Enter sum: ";
        cin >> dues;
    }
    void putdata() const {
        emp.putdata();
        cout << "\nDuty: ";
        cout << "\nNumber of publics: ";
        stu.putedu();
    }
};

class Scientist {
    int pubs;
    Employee emp;
    Student stu;
public:
    void getdata() {
        emp.getdata();
        cout << "Number of publics: ";
        cin >> pubs;
        stu.getedu();
    }
    void putdata() const {
        emp.putdata();
        cout << "\nNumber of publics: " << pubs;
        stu.putedu();
    }
};

class Laborer {
    Employee emp;
public:
    void getdata() {
        emp.getdata();
    }
    void putdata() const {
        emp.putdata();
    }
};

int main() {
    Manager m1;
    Scientist s1, s2;
    Laborer l1;

    cout << "\nEnter information about first manager: ";
    m1.getdata();

    cout << "\nEnter information about first scientist: ";
    s1.getdata();

    cout << "\nEnter information about second scientist: ";
    s2.getdata();

    cout << "\nEnter information about first laborer: ";
    l1.getdata();

    cout << "\nInformation about first manager: ";
    m1.putdata();

    cout << "\nInformation about first scientist: ";
    s1.putdata();

    cout << "\nInformation about second scientist: ";
    s2.putdata();

    cout << "\nInformation about first laborer: ";
    l1.putdata();
}