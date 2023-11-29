#include <fstream>
#include <iostream>
using namespace std;

class Person {
protected:
    char name[40];
    int age;
public:
    void getData(void) {
        cout << "\nEnter last name: ";
        cin >> name;
        cout << "\nEnter age: ";
        cin >> age;
    }
    void showData(void) {
        cout << "\nName: " << name;
        cout << "\nAge: " << age;
    } 
    void diskIn(int);
    void diskOut();
    static int diskCount();
};

void Person::diskIn(int pn) {
    ifstream infile;
    infile.open("PERSFILE.dat", ios::binary);
    infile.seekg(pn * sizeof(Person));

    infile.read((char*)this, sizeof(*this));
}

void Person::diskOut() {
    ofstream outfile;
    outfile.open("PERSFILE.dat", ios::app | ios::binary);
    outfile.write((char*)this, sizeof(*this));
}

int Person::diskCount() {
    ifstream infile;
    infile.open("PERSFILE.dat", ios::binary);
    infile.seekg(0, ios::end);

    return (int)infile.tellg() / sizeof(Person);
}

int main() {
    Person p;
    char ch;

    do {
        cout << "Enter data about man:\n";
        p.getData();
        p.diskOut();
        cout << "Enter (y/n)?";
        cin >> ch;
    } while(ch == 'y');
    
    int n = Person::diskCount();
    cout << "In file " << n << " man(a)\n";
    for(int i = 0; i < n; i++) {
        cout << "\nPerson " << i;
        p.diskIn(i);
        p.showData();
    }
    cout << '\n';

    return 0;
}