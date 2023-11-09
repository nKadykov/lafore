#include <iostream>
#include <set>
#include <string>
using namespace std;

class Person {
    string lastName;
    string firstName;
    long phoneNumber;
public:
    Person() : lastName("empty"), firstName("empty"), phoneNumber(0) {}
    Person(string lana, string fina, long pho): lastName(lana), firstName(fina), phoneNumber(pho) {}
    friend bool operator<(const Person&, const Person&);
    friend bool operator==(const Person&, const Person&);
    void display() const {
        cout << lastName << '\t' << firstName << "\t\tTelephone: " << phoneNumber << '\n';
    }
};

bool operator<(const Person& p1, const Person& p2) {
    if(p1.lastName == p2.lastName) {
        return (p1.firstName < p2.firstName) ? true : false;
    }
    return (p1.lastName < p2.lastName) ? true : false;
}

bool operator==(const Person& p1, const Person& p2) {
    return (p1.lastName == p2.lastName && p1.firstName == p2.firstName) ? true : false;
}

int main() {
    Person pers1("Deauville", "William", 8435150);
    Person pers2("McDonald", "Stacey", 3327563);
    Person pers3("Bartoski", "Peter",  6946473);
    Person pers4("KuangThu", "Bruce", 4157300);
    Person pers5("Wellington", "John", 9207404);
    Person pers6("McDonald", "Amanda",  8435150);
    Person pers7("Frederick", "Roger",  7049982);
    Person pers8("McDonald", "Stacey",  7764987);

    multiset<Person, less<Person> > persSet;
    multiset<Person, less<Person> >::iterator iter;

    persSet.insert(pers1);
    persSet.insert(pers2);
    persSet.insert(pers3);
    persSet.insert(pers4);
    persSet.insert(pers5);
    persSet.insert(pers6);
    persSet.insert(pers7);
    persSet.insert(pers8);

    cout << "Number: " << persSet.size() << '\n';

    iter = persSet.begin();

    while(iter != persSet.end()) {
        (*iter++).display();
    }

    string searchLastName, searchFirstName;
    cout << "Enter last name: ";
    cin >> searchLastName;
    cout << "Enter name: ";
    cin >> searchFirstName;
    Person searchPerson(searchLastName, searchFirstName, 0);
    int countPersons = persSet.count(searchPerson);
    cout << "Number of persons: " << countPersons << '\n';
    iter = persSet.lower_bound(searchPerson);
    while(iter != persSet.upper_bound(searchPerson)) {
        (*iter++).display();
    }
    return 0;
}