#include <fstream>
#include <iostream>
using namespace std;

class Person {
protected:
    char name[80];
    int age;
public:
    void getData() {
        cout << "\nEnter name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;
    }
    void showData() {
        cout << "\nName: " << name;
        cout << "\nAge: " << age;
    }
};

int main() {
    char ch;
    Person pers;
    fstream file;

    file.open("GROUP.txt", ios::app | ios::out | ios::in | ios:: binary);

    do {
        cout << "\nEnter data about man: ";
        pers.getData();

        file.write(reinterpret_cast<char*>(&pers), sizeof(pers));
        cout << "Continue enter (y/n)?";
        cin >> ch;
    } while(ch == 'y');
    file.seekg(0);

    file.read(reinterpret_cast<char*>(&pers), sizeof(pers));
    while(!file.eof()) {
        cout << "\nPerson: ";
        pers.showData();
        file.read(reinterpret_cast<char*>(&pers), sizeof(pers));
    }

    return 0;
}