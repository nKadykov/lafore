#include <iostream>
using namespace std;

class Person {
protected:
    string name;
public:
    void setName() {
        cout << "Enter name:";
        cin >> name;
    }
    void printName() {
        cout << name << '\n';
    }
    string getName() {
        return name;
    }
};

int main() {
    void bsort(Person**, int);
    Person* persPtr[100];
    int n = 0;
    char choice;

    do {
        persPtr[n] = new Person;
        persPtr[n]->setName();
        n++;
        cout << "Continue enter (y/n)?";
        cin >> choice;
    } while(choice == 'y');
    cout << "\nList:";
    for(int i = 0; i < n; i++) {
        persPtr[i]->printName();
    }
    bsort(persPtr, n);
    cout << "\nSorted list:\n";
    for(int i = 0; i < n; i++) {
        persPtr[i]->printName();
    }

    return 0;
}

void bsort(Person** pp, int n) {
    void order(Person**, Person**);

    for(int i = 0; i < n; i++) {
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