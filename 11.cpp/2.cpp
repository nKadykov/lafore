#include <iostream>
using namespace std;
#include <iostream>
using namespace std;

class Publication {
    string str;
    float price;
public:
    virtual void getdata() {
        cout << "Enter string and price: ";
        cin >> str >> price;
    }
    virtual void putdata() {
        cout << "String: " << str << "\nPrice: " << price << '\n';
    }
};

class Book : public Publication {
    int page;
public:
    void getdata() {
        Publication::getdata();
        cout << "Enter pages: ";
        cin >> page;
    }
    void putdata() {
        Publication::putdata();
        cout << "Pages: " << page << '\n';
    }
};

class Tape : public Publication {
    float time;
public:
    void getdata() {
        Publication::getdata();
        cout << "Enter time: ";
        cin >> time;
    }
    void putdata() {
        Publication::putdata();
        cout << "Time: " << time << '\n';
    }
};

int main() {
    Publication* arr[100];
    int n = 0;
    char ch = 'y';
    do {
        cout << "Enter data for books or tape (b/t): ";
        cin >> ch;
        if(ch == 'b') {
            arr[n] = new Book;
        }
        else if(ch == 't') {
            arr[n] = new Tape;
        }
        arr[n]->getdata();
        n++;
        cout << "Continue? (y/n): ";
        cin >> ch;
    }
    while(ch != 'n');
    for(int i = 0; i < n; i++) {
        cout << "Element " << i + 1 << ":\n";
        arr[i]->putdata();
    }
    return 0;
}