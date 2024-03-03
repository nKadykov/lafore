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
    virtual void putdata() const {
        cout << "String: " << str << "\nPrice: " << price << '\n';
    }
    virtual bool isOversize() const = 0;
};

class Book : public Publication {
    int page;
public:
    void getdata() {
        Publication::getdata();
        cout << "Enter pages: ";
        cin >> page;
    }
    void putdata() const {
        Publication::putdata();
        cout << "Pages: " << page << '\n';
    }
    bool isOversize() const {
        if(page > 800) {
            return true;
        }
        else {
            return false;
        }
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
    void putdata() const {
        Publication::putdata();
        cout << "Time: " << time << '\n';
    }
    bool isOversize() const {
        if(time > 90) {
            return true;
        }
        else {
            return false;
        }
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
        cout << "Data about " << i + 1 << "th publication: \n";
        arr[i]->putdata();
        if(arr[i]->isOversize()) {
            cout << "Is oversize\n";
        }
    }
    return 0;
}