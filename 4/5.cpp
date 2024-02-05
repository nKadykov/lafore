#include <iostream>
using namespace std;

struct Date {
    int month;
    int day;
    int year;
};

int main() {
    Date d;
    char ch = '/';
    cout << "Enter date: ";
    cin >> d.day >> ch >> d.month >> ch >> d.year;
    cout << "Date is: " << d.day << ch << d.month << ch << d.year;
    return 0;
}