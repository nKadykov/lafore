#include <iostream>
#include <list>
#include <algorithm>
#include <string>
using namespace std;

class Person {
    string lastName;
    string firstName;
    long phoneNumber;
public:
    Person(): lastName("empty"), firstName("empty"), phoneNumber(0) {}
    Person(string lana, string fina, long pho): lastName(lana), firstName(fina), phoneNumber(pho) {}
    friend bool operator<(const Person&, const Person&);
    friend bool operator==(const Person&, const Person&);
    friend bool operator!=(const Person&, const Person&);
    friend bool operator>(const Person&, const Person&);
    void display() const {
        cout << lastName << "\t" << firstName << "\t\tTelephone" << phoneNumber;
    }
    long get_phone() const {
        return phoneNumber;
    }
};

bool operator<(const Person& p1, const Person& p2) {
    if(p1.lastName == p2.lastName) {
        return (p1.firstName < p2.firstName) ? true : false;
    }
    return (p1.lastName < p2.lastName) ? true : false;
}

bool operator==(const Person& p1, const Person& p2) {
    if(p1.firstName == p2.firstName) {
        return (p1.lastName == p2.lastName) ? true : false;
    }
    return (p1.lastName == p2.lastName) ? true : false;
}

bool operator!=(const Person& p1, const Person& p2) {
    return !(p1 == p2);
}

bool operator<(const Person& p1, const Person& p2) {
    return !(p1 < p2) && !(p1 == p2);
}

int main() {
    list<Person> persList;
    list<Person>::iterator iter1;
    persList.push_back(Person("Deauvill", "William", 8435150));
    persList.push_back(Person("McDonald", "Stacey", 3327563));
    persList.push_back(Person("Bartoski", "Peter", 6946473));
    persList.push_back(Person("KuangThu", "Bruce", 4157300));
    persList.push_back(Person("Wellington", "John", 9207404));
    persList.push_back(Person("McDonald", "Amanda",  8435150));
    persList.push_back(Person("Fredericks", "Roger", 7049982));
    persList.push_back(Person("McDonald", "Stacey", 7764987));
}