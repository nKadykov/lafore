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
    void showData(void) {
        cout << "\nName: " << name;
        cout << "\nAge: " << age;
    }
};

int main() {
    Person pers;
    ifstream infile;
    infile.open("GROUP.txt", ios::in | ios::binary);

    infile.seekg(0, ios::end);

    int endposition = infile.tellg();
    int n = endposition / sizeof(Person);
    cout << "\nIn file " << n << " persons";

    cout << "\nEnter number of person: ";
    cin >> n;
    int position = (n - 1) * sizeof(Person);

    infile.seekg(position);

    infile.read(reinterpret_cast<char*>(&pers), sizeof(pers));
    pers.showData();
    
    return 0;
}