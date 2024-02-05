#include <iostream>
using namespace std;

enum etype {laborer, secretary, manager, accountant, executive, researcher};

struct Date {
    int month;
    int day;
    int year;
};

struct Employee {
    int number;
    float salary;
    etype pos;
    Date hiring;
};

void outputPosition(char pos) {
    switch(pos) {
        case 'l':
            cout << "laborer";
            break;
        case 's':
            cout << "secretary";
            break;
        case 'm':
            cout << "manager";
            break;
        case 'a':
            cout << "accountant";
            break;
        case 'e':
            cout << "executive";
            break;
        case 'r':
            cout << "resarcher";
            break;
    }
}

int main() {
    Employee e1;
    Employee e2;
    Employee e3;

    char p1;
    char p2;
    char p3;
    char ch = '/';

    cout << "Enter number, salary, position and haring date of first employee: ";
    cin >> e1.number >> e1.salary >> p1 >> e1.hiring.day >> ch >> e1.hiring.month >> ch >> e1.hiring.year;
    cout << "Enter number, salary, position and haring date of second employee: ";
    cin >> e2.number >> e2.salary >> p2 >> e2.hiring.day >> ch >> e2.hiring.month >> ch >> e2.hiring.year;
    cout << "Enter number, salary, position and haring date of third employee: ";
    cin >> e3.number >> e3.salary >> p3 >> e3.hiring.day >> ch >> e3.hiring.month >> ch >> e3.hiring.year;

    cout << "Information about first employee:\nNumber: " << e1.number << "\nSalary: " << e1.salary << "\nPosition: ";
    outputPosition(p1);
    cout << "\nDate: " << e1.hiring.day << '/' << e1.hiring.month << '/' << e1.hiring.year << '\n';
    cout << "Information about second employee:\nNumber: " << e2.number << "\nSalary: " << e2.salary << "\nPosition: ";
    outputPosition(p2);
    cout << "\nDate: " << e2.hiring.day << '/' << e2.hiring.month << '/' << e2.hiring.year << '\n';
    cout << "Information about third employee:\nNumber: " << e3.number << "\nSalary: " << e3.salary << "\nPosition: ";
    outputPosition(p3);
    cout << "\nDate: " << e3.hiring.day << '/' << e3.hiring.month << '/' << e3.hiring.year << '\n';

    return 0;
}