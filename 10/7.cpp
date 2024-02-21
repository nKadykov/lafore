#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    float salary;
public:
    void setData() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter salary: ";
        cin >> salary;
    }
    void printData() {
        cout << "Name: " << name << ' ' << "Salary: " << salary << '\n';
    }
    string getName() {
        return name;
    }
    float getSalary() {
        return salary;
    }
};

void salsort(Person**, int n);

int main() {
    void bsort(Person**, int);
    Person* persPtr[100];
    int n = 0;
    char choice;
    do {
        persPtr[n] = new Person;
        persPtr[n]->setData();
        n++;
        cout << "Continue? (y/n): ";
        cin >> choice;
    } while(choice != 'n');
    cout << "List:\n";
    for(int i = 0; i < n; i++) {
        persPtr[i]->printData();
    }
    bsort(persPtr, n);
    cout << "Sorted list:\n";
    for(int i = 0; i < n; i++) {
        persPtr[i]->printData();
    }
    salsort(persPtr, n);
    cout << "Salary sorted list:\n";
    for(int i = 0; i < n; i++) {
        persPtr[i]->printData();
    }

    return 0;
}

void salsort(Person** pp, int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if((*(pp + i))->getSalary() > (*(pp + j))->getSalary()) {
                Person* tempptr = *(pp + i);
                (*(pp + i)) = (*(pp + j));
                (*(pp + j)) = tempptr;
            }
        }
    }
}

void bsort(Person** pp, int n) {
    void order(Person**, Person**);

    for(int i = 0; i < n - 1; i++) {
        for(int k = i + 1; k < n; k++) {
            order(pp + i, pp + k);
        }
    }
}

void order(Person** pp1, Person** pp2) {
    if((*pp1)->getName() > (*pp2)->getName()) {
        Person* tempptr = *pp1;
        *pp1 = *pp2;
        *pp2 = tempptr;
    }
}