#include <iostream>

const int LEN = 80;

class Employee {
    char name[LEN];
    unsigned long number;
public:
    friend std::istream& operator>>(std::istream& s, Employee& e);
    friend std::ostream& operator<<(std::ostream& s, Employee& e);
};

std::istream& operator>>(std::istream& s, Employee& e) {
    std::cout << "Enter name: ";
    std::cin >> e.name;
    std::cout << "Enter number: ";
    std::cin >> e.number;
    return s;
}

std::ostream& operator<<(std::ostream& s, Employee& e) {
    std::cout << "Name: " << e.name << std::endl;
    std::cout << "Number: " << e.number << std::endl;
    return s;
}

template<class Type>
struct Link {
    Type data;
    Link* next;
};

template<class Type>
class Linklist {
    Link<Type>* first;
public:
    Linklist() {
        first = NULL;
    }
    void additem(Type d);
    void display();
};

template<class Type>
void Linklist<Type>::additem(Type d) {
    Link<Type>* newlink = new Link<Type>;
    newlink->data = d;
    newlink->next = first;
    first = newlink;
}

template<class Type>
void Linklist<Type>::display() {
    Link<Type>* current = first;
    while(current != NULL) {
        std::cout << current->data;
        current = current->next;
    }
}

int main() {
    Linklist<Employee> lemp;
    Employee emptemp;
    char result;

    do {
        std::cin >> emptemp;
        lemp.additem(emptemp);
        std::cout << "Continue? (y/n): ";
        std::cin >> result;
    }
    while(result != 'n');
    lemp.display();
    
    return 0;
}