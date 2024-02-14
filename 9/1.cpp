#include <iostream>
using namespace std;

class Publication {
    string str;
    float price;
public:
    void getdata() {
        cout << "Enter string and price: ";
        cin >> str >> price;
    }
    void putdata() {
        cout << "String: " << str << "\nPrice: " << price << '\n';
    }
};

class Book : public Publication {
    int page;
public:
    void getdata() {
        cout << "Enter pages: ";
        cin >> page;
    }
    void putdata() {
        cout << "Pages: " << page << '\n';
    }
};

class Type : public Publication {
    float time;
public:
    void getdata() {
        cout << "Enter time: ";
        cin >> time;
    }
    void putdata() {
        cout << "Time: " << time << '\n';
    }
};

int main() {
    Book b;
    Type t;
    b.getdata();
    b.putdata();
    t.getdata();
    t.putdata();
    return 0;
}