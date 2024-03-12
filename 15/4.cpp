#include <iostream>
#include <set>
#include <cstring>
#include <iomanip>

class Person {
    std::string lastName;
    std::string firstName;
    long phoneNumber;
public:
    Person(): lastName("empty"), firstName("empty"), phoneNumber(0L) {}
    Person(std::string lana, std::string fina, long pho): lastName(lana), firstName(fina), phoneNumber(pho) {}
    friend bool operator<(const Person&, const Person&);
    void display() const {
        std::cout << setiosflags(std::ios::left) << std::setw(15) << lastName << std::setw(15) << firstName << "Telephone: " << phoneNumber << std::endl;
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

class comparePersons {
public:
    bool operator() (const Person* pt1, const Person* pt2) const {
        return *pt1 < *pt2;
    }
};

int main() {
    std::multiset<Person*, comparePersons> s; // мультимножество указателей на объекты Person
    std::multiset<Person*, comparePersons>::iterator iter; // итератор

    Person* pt1 = new Person("KuangThu", "Bruce", 4157300); // создание персон
    Person* pt2 = new Person("McDonald", "Stacey", 3327563);
    Person* pt3 = new Person("Deauville", "Deauville", 8435150);
    Person* pt4 = new Person("Wellington", "John", 9207404);
    Person* pt5 = new Person("Bartoski", "Peter", 6946473);
    Person* pt6 = new Person("McDonald", "Amanda", 8435150);
    Person* pt7 = new Person("Fredericks", "Roger", 7049982);
    Person* pt8 = new Person("McDonald", "Stacey", 7764987);
    s.insert(pt1); // внесение персон в мультимножество
    s.insert(pt2);
    s.insert(pt3);
    s.insert(pt4);
    s.insert(pt5);
    s.insert(pt6);
    s.insert(pt7);
    s.insert(pt8);
    std::cout << "Set ordered:" << std::endl;
    for(iter = s.begin(); iter != s.end(); iter++) {
        (**iter).display(); // вывод мультимножества
    }
    iter = s.begin();
    while(iter != s.end()) {
        delete *iter; // удаление указателя
        s.erase(iter++); // удаление персоны из мультимножества
    }

    return 0;
}