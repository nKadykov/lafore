#include <iostream>
using namespace std;

struct Employee {
    int number;
    float salary;
};

int main() {
    Employee e1;
    Employee e2;
    Employee e3;

    cout << "Enter number and salary of first employee: ";
    cin >> e1.number >> e1.salary;
    cout << "Enter number and salary of second employee: ";
    cin >> e2.number >> e2.salary;
    cout << "Enter number and salary of third employee: ";
    cin >> e3.number >> e3.salary;

    cout << "Information about first employee:\nNumber: " << e1.number << "\nSalary: " << e1.salary << '\n';
    cout << "Information about second employee:\nNumber: " << e2.number << "\nSalary: " << e2.salary << '\n';
    cout << "Information about third employee:\nNumber: " << e3.number << "\nSalary: " << e3.salary;

    return 0;
}