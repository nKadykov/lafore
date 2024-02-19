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
        cout << "School: " << school << endl;
        cout << "Degree: " << degree << endl;
    }
};

class Employee {
    char name[LEN];
    unsigned long number;
public:
    void getdata() {
        cout << "Enter last name: ";
        cin >> name;
        cout << "Enter number: ";
        cin >> number;
    }
    void putdata() const {
        cout << "Last name: " << name << endl;
        cout << "Number: " << number << endl;
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
        cout << "Duty: " << title << endl;
        cout << "Sum: " << dues << endl;
        Student::putedu();
    }
};

class Executive : public Manager {
    int annualBonus;
    int share;
public:
    void getdata() {
        Manager::getdata();
        cout << "Enter annual bonus: ";
        cin >> annualBonus;
        cout << "Enter company share: ";
        cin >> share;
    }
    void putdata() {
        Manager::putdata();
        cout << "Annual bonus: " << annualBonus << endl;
        cout << "Company share: " << share << endl;
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
        cout << "Number of publics: " << pubs << endl;
        Student::putedu();
    }
};

class Laborer : public Employee {
};

int main() {
    Executive e;
    cout << "Enter information about executive\n";
    e.getdata();
    e.putdata();

    return 0;
}