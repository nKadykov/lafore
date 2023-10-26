#include <iostream>
using namespace std;

class Employee {
    int employeeNumber;
    float employeeSalary;
public:
    void setEmployee(int number, float salary) {
        employeeNumber = number;
        employeeSalary = salary;
    }
    void showEmployee() const {
        cout << employeeNumber << ' ' << employeeSalary << '\n';
    }
};

int main() {
    Employee employee1, employee2, employee3;
    employee1.setEmployee(1, 1000), employee2.setEmployee(2, 1500), employee3.setEmployee(3, 2000);
    employee1.showEmployee(), employee2.showEmployee(), employee3.showEmployee();

    return 0;
}