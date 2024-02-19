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

class Publication2 : public Publication {
    int day;
    int month;
    int year;
public:
    void getdata() {
        Publication::getdata();
        char ch = '/';
        cout << "Enter date (11/11/2000): ";
        cin >> day >> ch >> month >> ch >> year;
    }
    void putdata() {
        Publication::putdata();
        cout << "Date: " << day << '/' << day << '/' << year << '\n';
    }
};

class Book : public Publication2 {
    int page;
public:
    void getdata() {
        Publication2::getdata();
        cout << "Enter pages: ";
        cin >> page;
    }
    void putdata() {
        Publication2::putdata();
        cout << "Pages: " << page << '\n';
    }
};

class Type : public Publication2 {
    float time;
public:
    void getdata() {
        Publication2::getdata();
        cout << "Enter time: ";
        cin >> time;
    }
    void putdata() {
        Publication2::putdata();
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