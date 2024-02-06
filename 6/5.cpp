#include <iostream>
using namespace std;

class Date {
    int month;
    int day;
    int year;
public:
    Date() : month(0), day(0), year(0) {}
    void getdate() {
        char ch = '/';
        cin >> day >> ch >> month >> ch >> year;
    }
    void showdate() {
        cout << day << "/" << month << "/" << year;
    }
};

int main() {
    Date d;

    d.getdate();
    d.showdate();
    
    return 0;
}