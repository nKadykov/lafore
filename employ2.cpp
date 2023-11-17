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
        cout << "\n:Last name: " << name;
        cout << "\nNumber: " << number;
    }
};

class Manager : public Employee {
    char title[LEN];
    double dues;
public:
    void getdata() {
        Employee::getdata();
        cout << "Enter duty: ";
        cin >> title;
        cout << "Enter sum: ";
        cin >> dues;
    }
    void putdata() const {
        Employee::putdata();
        cout << "\nDuty: " << title;
        cout << "\nSum: " << dues;
    }
};

class Scientist : public Employee {
    int pubs;
public:
    void getdata() {
        Employee::getdata();
        cout << "Enter number of publics: ";
        cin >> pubs;
    }
    void putdata() {
        Employee::putdata();
        cout << "\nNumber of publics: " << pubs;
    }
};

class Laborer : public Employee {
};

class Foreman : public Laborer {
    float quotas;
public:
    void getdata() {
        Laborer::getdata();
        cout << "Quota: " << quotas;
    }
    void putdata() const {
        Laborer::putdata();
        cout << "\n Quota: " << quotas;
    }
};

int main() {
    Laborer l1;
    Foreman f1;

    cout  << "\nEnter information about first emloyee: ";
    l1.getdata();
    cout << "\nEnter information about first foreman: ";
    f1.getdata();

    cout << "\nInformation about first employee: ";
    l1.putdata();
    cout << "\nInformation about first foreman";
    f1.putdata();

    return 0;
}