#include <iostream>
using namespace std;

const int LEN = 80;

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
        cout << "Last name " << name << '\n';
        cout << "Number: " << number << '\n';
    }
};

class Employee2 : public Employee {
    double compensation;
    enum period {HOUR, WEEK, MONTH};
    period method;
public:
    void getdata() {
        Employee::getdata();
        char ch;
        cout << "Enter compensation: ";
        cin >> compensation;
        cout << "Enter payment method (h, w, m): ";
        cin >> ch;
        switch(ch) {
            case 'h':
                method = HOUR;
                break;
            case 'w':
                method = WEEK;
                break;
            case 'm':
                method = MONTH;
                break;
        }
    }
    void putdata() const {
        Employee::putdata();
        cout << "Compensation: " << compensation << '\n';
        cout << "Method: ";
        switch(method) {
            case HOUR:
                cout << "hourly";
                break;
            case WEEK:
                cout << "weekly";
                break;
            case MONTH:
                cout << "monthly";
                break;
        }
        cout << '\n';
    }
};

class Manager: public Employee2 {
    char title[LEN];
    double dues;
public:
    void getdata() {
        Employee2::getdata();
        cout << "Enter title: ";
        cin >> title;
        cout << "Sum: ";
        cin >> dues; 
    }
};

class Scientist: public Employee2 {
    int pubs;
public:
    void getdata() {
        Employee2::getdata();
        cout << "Enter number of publics: ";
        cin >> pubs;
    }
    void putdata() const {
        Employee2::putdata();
        cout << "Number of publics: " << pubs;
    }
};

class Laborer: public Employee2 {

};

int main() {
    Manager m1, m2;
    Scientist s1;
    Laborer l1;

    cout << "Enter information about first manager\n";
    m1.getdata();

    cout << "Enter information about second manager\n";
    m2.getdata();

    cout << "Enter information about first scietist\n";
    s1.getdata();

    cout << "Enter information about first laborer\n";
    l1.getdata();

    cout << "Information about first manager\n";
    m1.putdata();

    cout << "Information about second manager\n";
    m2.putdata();

    cout << "Information about first scientist\n";
    s1.putdata();

    cout << "Information abour first laborer\n";
    l1.putdata();

    return 0;
}