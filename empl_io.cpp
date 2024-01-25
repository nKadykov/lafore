#include <iostream>
#include <fstream>
#include <typeinfo>
#include <process.h>
using namespace std;

const int LEN = 32;
const int MAXEM = 100;

enum employee_type {tmanager, tscientist, tlaborer};

class Employee {
    char name[LEN];
    unsigned long  number;
    static int n;
    static Employee* arrap[];
public:
    virtual void getdata() {
        cin.ignore(10, '\n');
        cout << "\nEnter last name: ";
        cin >> name;
        cout << "\nEnter number: ";
        cin >> number;
    }
    virtual void putdata() {
        cout << "\nLast name: " << name;
        cout << "\nNumber: " << number;
    }
    virtual employee_type get_type();
    static void add();
    static void display();
    static void read();
    static void write();
};

int Employee::n;
Employee* Employee::arrap[MAXEM];

class Manager : public Employee {
    char title[LEN];
    double dues;
public:
    void getdata() {
        Employee::getdata();
        cout << "Enter title: ";
        cin >> title;
        cout << "Enter dues: ";
        cin >> dues;
    }
    void putdata() {
        Employee::putdata();
        cout << "\nTitle: " << title;
        cout << "\nDues: " << dues;
    }
};

class Scientist : public Employee {
    int pubs;
public:
    void getdata() {
        Employee::getdata();
        cout << "Enter number of publics: ";
        cin >> pubs;
    }
};

class Laborer : public Employee {
};

void Employee::add() {
    char ch;
    cout << "'m' for manager\n's' for scientist\n'l' for laborer\nYour choice";
    cin >> ch;
    switch(ch) {
        case 'm':
            arrap[n] = new Manager;
            break;
        case 's':
            arrap[n] = new Scientist;
            break;
        case 'l':
            arrap[n] = new Laborer;
            break;
        default:
            cout << "\nUnknown\n";
            return;
    }
    arrap[n++]->getdata();
};

void Employee::display() {
    for(int i = 0; i < n; i++) {
        cout << (i + 1);
        switch(arrap[i]->get_type()) {
            case tmanager:
                cout << "Type: manager";
                break;
            case tscientist:
                cout << "Type: scientist";
                break;
            case tlaborer:
                cout << "Type: laborer";
                break;
            default:
                cout << "Unknown type";
        }
        arrap[i]->putdata();
        cout << '\n';
    }
}

employee_type Employee::get_type() {
    if(typeid(*this) == typeid(Manager)) {
        return tmanager;
    }
    else if(typeid(*this) == typeid(Scientist)) {
        return tscientist;
    }
    else if(typeid(*this) == typeid(Laborer)) {
        return tlaborer;
    }
    else {
        cerr << "\nError";
        exit(1);
    }
    return tmanager;
}

void Employee::write() {
    int size;
    cout << "Writing " << n << " employees\n";
    ofstream out;
    employee_type etype;

    out.open("EMPLOY.dat", ios::trunc | ios::binary);
    if(!out) {
        cout << "\nCan't open file\n";
        return;
    }
    for(int i = 0; i < n; i++) {
        etype = arrap[i]->get_type();
        out.write((char*)&etype, sizeof(etype));
        switch(etype) {
            case tmanager:
                size = sizeof(Manager);
                break;
            case tscientist:
                size = sizeof(Scientist);
                break;
            case tlaborer:
                size = sizeof(Laborer);
                break;
        }
        out.write((char*)(arrap[i]), size);
        if(!out) {
            cout << "\nWriting is prohibited";
            return;
        }
    }
}

void Employee::read() {
    int size;
    employee_type etype;
    ifstream inf;
    inf.open("EMPLOY.dat", ios::binary);
    if(!inf) {
        cout << "Can't open file\n";
        return;
    }
    n = 0;
    while(true) {
        inf.read((char*)&etype, sizeof(etype));
        if(inf.eof()) {
            break;
        }
        if(!inf) {
            cout << "\nCan't read type\n";
            return;
        }
        switch(etype) {
            case tmanager:
                arrap[n] = new Manager;
                size = sizeof(Manager);
                break;
            case tscientist:
                arrap[n] = new Scientist;
                size = sizeof(Scientist);
                break;
            case tlaborer:
                arrap[n] = new Laborer;
                size = sizeof(Laborer);
                break;
            default:
                cout << "\nUnknown type in file\n";
                return;
        }
        inf.read((char*)arrap[n], size);
        if(!inf) {
            cout << "\nReading is prohibited\n";
            return;
        }
        n++;
    }
    cout << "Reading " << n << " employees\n";
}

int main() {
    system("chcp 1251 > nul");

    char ch;
    while(true) {
        cout << "\'a\' - input data\n\'d\' - data of all\n\'w\' - write data in file\n\'r\' - read data in file\n\'x\' - exit\nYour choise: ";
        cin >> ch;
        switch(ch) {
            case 'a':
                Employee::add();
                break;
            case 'd':
                Employee::display();
                break;
            case 'w':
                Employee::write();
                break;
            case 'r':
                Employee::read();
                break;
            case 'x':
                exit(0);
            default:
                cout << "\nUnknown";
        }

        return 0;
    }
}