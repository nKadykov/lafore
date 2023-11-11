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
        cout << lastName << "\t" << firstName << "\t\tTelephone " << phoneNumber << '\n';
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

bool operator>(const Person& p1, const Person& p2) {
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

    cout << "Number: " << persList.size() << '\n';

    iter1 = persList.begin();
    while(iter1 != persList.end()) {
        (*iter1++).display();
    }
    string searchLastName, searchFirstName;
    cout << "Enter last name: ";
    cin >> searchLastName;
    cout << "Enter name: ";
    cin >> searchFirstName;

    Person searchPerson(searchLastName, searchFirstName, 0L);

    iter1 = find(persList.begin(), persList.end(), searchPerson);
    if(iter1 != persList.end()) {
        cout << "There is this man in list: \n";
        do {
            (*iter1++).display();
            ++iter1;
            iter1 = find(iter1, persList.end(), searchPerson);
        } while(iter1 != persList.end());
    }
    else {
        cout << "There is no this man\n";
    }

    cout << "\nEnter number of phone: ";

    long sNumber;
    cin >> sNumber;
    bool found_one = false;
    for(iter1 != persList.begin(); iter1 != persList.end(); ++iter1) {
        if(sNumber == (*iter1).get_phone()) {
            if(!found_one) {
                cout << "There is man (or men) with this number: ";
                found_one = true;
            }
            (*iter1).display();
        }
    }
    if(!found_one) {
        cout << "There is no man with this number";
    }
    return 0;
}