#include <iostream>
#include <fstream>
#include <typeinfo>
#include <fstream>
#include <process.h>

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
        std::cin.ignore(10, '\n');
        std::cout << "Enter last name: ";
        std::cin >> name;
        std::cout << "Enter number: ";
        std::cin >> number;
    }
    virtual void putdata() {
        std::cout << "Last name: " << name << std::endl;
        std::cout << "Number: " << number << std::endl;
    }
    virtual employee_type get_type();
    static void add();
    static void display();
    static void read();
    static void write();
    static void find(); // поиск рабоника по его номеру в файле
};

int Employee::n;
Employee* Employee::arrap[MAXEM];

int main() {
    char ch;
    while(true) {
        std::cout << "a - input data\nd - data of all\nw - write data in file\nr - read data in file\nx - exit\nf - find employee with number\nYour choise: ";
        std::cin >> ch;
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
            case 'f':
                Employee::find();
                break;
            case 'x':
                exit(0);
            default:
                std::cout << "\nUnknown";
        }

        return 0;
    }
}

class Manager : public Employee {
    char title[LEN];
    double dues;
public:
    void getdata() {
        Employee::getdata();
        std::cout << "Enter title: ";
        std::cin >> title;
        std::cout << "Enter dues: ";
        std::cin >> dues;
    }
    void putdata() {
        Employee::putdata();
        std::cout << "\nTitle: " << title;
        std::cout << "\nDues: " << dues;
    }
};

class Scientist : public Employee {
    int pubs;
public:
    void getdata() {
        Employee::getdata();
        std::cout << "Enter number of publics: ";
        std::cin >> pubs;
    }
};

class Laborer : public Employee {
};

void Employee::add() {
    char ch;
    std::cout << "'m' for manager\n's' for scientist\n'l' for laborer\nYour choice: ";
    std::cin >> ch;
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
            std::cout << "Unknown\n";
            return;
    }
    arrap[n++]->getdata();
};

void Employee::display() {
    for(int i = 0; i < n; i++) {
        std::cout << (i + 1);
        switch(arrap[i]->get_type()) {
            case tmanager:
                std::cout << "Type: manager" << std::endl;
                break;
            case tscientist:
                std::cout << "Type: scientist" << std::endl;
                break;
            case tlaborer:
                std::cout << "Type: laborer" << std::endl;
                break;
            default:
                std::cout << "Unknown type" << std::endl;
        }
        arrap[i]->putdata();
        std::cout << '\n';
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
        std::cerr << "\nError";
        exit(1);
    }
    return tmanager;
}

void Employee::write() {
    int size;
    std::cout << "Writing " << n << " employees\n";
    std::ofstream out;
    employee_type etype;

    out.open("12.dat", std::ios::trunc | std::ios::binary);
    if(!out) {
        std::cout << "\nCan't open file\n";
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
            std::cout << "\nWriting is prohibited";
            return;
        }
    }
}

void Employee::read() {
    int size;
    employee_type etype;
    std::ifstream inf;
    inf.open("12.dat", std::ios::binary);
    if(!inf) {
        std::cout << "Can't open file\n";
        return;
    }
    n = 0;
    while(true) {
        inf.read((char*)&etype, sizeof(etype));
        if(inf.eof()) {
            break;
        }
        if(!inf) {
            std::cout << "\nCan't read type\n";
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
                std::cout << "\nUnknown type in file\n";
                return;
        }
        inf.read((char*)arrap[n], size);
        if(!inf) {
            std::cout << "\nReading is prohibited\n";
            return;
        }
        n++;
    }
    std::cout << "Reading " << n << " employees\n";
}

void Employee::find() {
    unsigned long number;
    std::cout << "Enter number: ";
    std::cin >> number;

    Employee* e;
    int size;
    employee_type etype;
    std::ifstream in("16.dat", std::ios::binary);

    if(!in) {
        std::cout << "Can't open file\n";
        exit(-1);
    }

    while(true) {
        in.read(reinterpret_cast<char*>(&etype), sizeof(etype));
        if(in.eof()) {
            break;
        }
        if(!in) {
            std::cout << "Can't read\n";
            exit(-1);
        }

        switch(etype) {
            case tmanager:
                e = new Manager;
                size = sizeof(Manager);
                break;
            case tscientist:
                e = new Scientist;
                size = sizeof(Scientist);
                break;
            case tlaborer:
                e = new Laborer;
                size = sizeof(Laborer);
                break;
            default:
                std::cout << "Unknown type\n";
                exit(-1); 
        }

        in.read(reinterpret_cast<char*>(e) + sizeof(void*), size - sizeof(void*));
        if(!in) {
            std::cout << "Can't read data\n";
            exit(-1);
        }
        if(e->number == number) {
            switch(e->get_type()) {
                case tmanager:
                    std::cout << "Type: manager\n";
                    break;
                case tscientist:
                    std::cout << "Type: scientist\n";
                    break;
                case tlaborer:
                    std::cout << "Type: laborer\n";
                    break;
                default:
                    std::cout << "Unknown type\n";
            }
        }
        else {
            delete e;
        }
    }
    std::cout << "Can't find employee with this number\n";
}