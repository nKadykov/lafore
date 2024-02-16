#include <iostream>
using namespace std;

class Sales {
    enum {MONTH = 3};
    float sale[MONTH];
public:
    void getdata();
    void putdata() const;
};

void Sales::getdata() {
    cout << "Enter sales in 3 months\n";
    for(int j = 0; j < MONTH; j++) {
        cout << "Month " << j + 1 << ": ";
        cin >> sale[j];
    }
}

void Sales::putdata() const {
    for(int i = 0; i < MONTH; i++) {
        cout << "Sales in " << i + 1 << ": ";
        cout << sale[i] << '\n';
    }
}

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

class Book : public Publication, public Sales {
    int page;
public:
    void getdata() {
        Publication::getdata();
        cout << "Enter pages: ";
        cin >> page;
        Sales::getdata();
    }
    void putdata() {
        Publication::putdata();
        cout << "Pages: " << page << '\n';
        Sales::putdata();
    }
};

class Type : public Publication, public Sales {
    float time;
public:
    void getdata() {
        Publication::getdata();
        cout << "Enter time: ";
        cin >> time;
        Sales::getdata();
    }
    void putdata() {
        Publication::putdata();
        cout << "Time: " << time << '\n';
        Sales::putdata();
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