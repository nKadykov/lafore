#include <iostream>
using namespace std;

enum etype {laborer, secretary, manager, accountant, executive, researcher};

etype position(char pos) {
    switch(pos) {
        case 'l':
            return laborer;
        case 's':
            return secretary;
        case 'm':
            return manager;
        case 'a':
            return accountant;
        case 'e':
            return executive;
        case 'r':
            return researcher;
    }
}

void outputPosition(etype p) {
    switch(p) {
        case 0:
            cout << "laborer\n";
            break;
        case 1:
            cout << "secretary\n";
            break;
        case 2:
            cout << "manager\n";
            break;
        case 3:
            cout << "accountant\n";
            break;
        case 4:
            cout << "executive\n";
            break;
        case 5:
            cout << "researcher\n";
            break;
    }
}

class Date {
    int month;
    int day;
    int year;
public:
    Date() : month(0), day(0), year(0) {}
    void getdate() {
        char ch = '/';
        cin >> day >> ch >> month >> ch >> year;
    }
    void showdate() {
        cout << day << "/" << month << "/" << year << '\n';
    }
};

class Employee {
    int number;
    float salary;
    Date hiring;
    etype pos;
public:
    Employee() : number(0), salary(0) {}
    Employee(int n, int s) : number(n), salary(s) {}
    void putemploy() {
        char p;
        cout << "Enter information about employee:\n";
        cout << "Number: ";
        cin >> number;
        cout << "Salary: ";
        cin >> salary;
        cout << "Date of hiring: ";
        hiring.getdate();
        cout << "Position: ";
        cin >> p;
        pos = position(p);
    }
    void getemploy() {
        cout << "Information\nNumber: " << number << "\nSalary: " << salary << "\nDate of hiring: ";
        hiring.showdate();
        cout << "Position: ";
        outputPosition(pos);
    }
};

int main() {
    Employee e1, e2, e3;

    e1.putemploy();
    e1.getemploy();
    e2.putemploy();
    e2.getemploy();
    e3.putemploy();
    e3.getemploy();

    return 0;
}