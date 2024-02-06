#include <iostream>
using namespace std;

class Employee {
    int number;
    float salary;
public:
    Employee() : number(0), salary(0) {}
    Employee(int n, int s) : number(n), salary(s) {}
    void outputNumber() {
        cout << number << '\n';
    }
    void outputSalary() {
        cout << salary << '\n';
    }
};

int main() {
    Employee e1(1, 10000);
    Employee e2(2, 20000);
    Employee e3(3, 30000);

    e1.outputNumber();
    e1.outputSalary();
    e2.outputNumber();
    e2.outputSalary();
    e3.outputNumber();
    e3.outputSalary();

    return 0;
}