#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Person {
    string lastName;
    string firstName;
    long phoneNumber;
public:
    Person() : lastName("empty"), firstName("empty"), phoneNumber(0L) {}
    Person(string lana, string fina, long pho) : lastName(lana), firstName(fina), phoneNumber(pho) {}
    friend bool operator<(const Person&, const Person&);
    friend bool operator==(const Person&, const Person&);
    void display() const {
        cout << endl << lastName << '\t' << firstName << 
        "\t\t" << phoneNumber;
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
    return (p1.lastName == p2.lastName && p1.firstName == p2.firstName) ? true : false;
}

class comparePersons {
public:
    bool operator() (const Person* ptrP1, const Person* ptrP2) const {
        return (*ptrP1 < *ptrP2);
    }
};

class displayPerson {
public:
    void operator() (const Person* ptrP) const {
        ptrP->display();
    }
};

int main() {
    vector<Person*> vectPtrsPers;

    Person* ptrP1 = new Person("KuangThu", "Bruce", 4157300);
    Person* ptrP2 = new Person("Deauville", "William", 8435150);
    Person* ptrP3 = new Person("Wellington", "John", 9207404);
    Person* ptrP4 = new Person("Bartoski", "Peter", 6946473);
    Person* ptrP5 = new Person("Fredericks", "Roger", 7049982);
    Person* ptrP6 = new Person("McDonald", "Stacey", 7764987);

    vectPtrsPers.push_back(ptrP1);
    vectPtrsPers.push_back(ptrP2);
    vectPtrsPers.push_back(ptrP3);
    vectPtrsPers.push_back(ptrP4);
    vectPtrsPers.push_back(ptrP5);
    vectPtrsPers.push_back(ptrP6);

    for_each(vectPtrsPers.begin(), vectPtrsPers.end(), displayPerson());
    sort(vectPtrsPers.begin(), vectPtrsPers.end());
    cout << "\nPointers:";
    for_each(vectPtrsPers.begin(), vectPtrsPers.end(), displayPerson());
    sort(vectPtrsPers.begin(), vectPtrsPers.end(), comparePersons());
    cout << "\nPointers:";
    for_each(vectPtrsPers.begin(), vectPtrsPers.end(), displayPerson());
    while(!vectPtrsPers.empty()) {
        delete vectPtrsPers.back();
        vectPtrsPers.pop_back();
    }
    return 0;
}