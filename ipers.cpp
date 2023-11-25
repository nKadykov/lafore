#include <fstream>
#include <iostream>
using namespace std;

class Person {
protected:
    char name[80];
    short age;
public:
    void showData() {
        cout << "Name: " << name << '\n';
        cout << "Age: " << age << '\n';
    }
};

int main() {
    Person pers;
    ifstream infile("PERSON.txt", ios::binary);

    infile.read(reinterpret_cast<char*>(&pers), sizeof(pers));
    pers.showData();

    return 0;
}