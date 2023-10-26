#include <iostream>
using namespace std;

class Date {
    int month, day, year;
public:
    void getDate(int m, int d, int y) {
        month = m;
        day = d;
        year = y;
    }
    void showDate() const {
        if(month < 10)
            cout << '0';
        cout << month << '\\';
        if(day < 10)
            cout << '0';
        cout << day << '\\';
        if(year < 10)
            cout << '0';
        cout << year << '\n';
    }
};

int main() {
    Date date1, date2;
    date1.getDate(12, 31, 02);
    date2.getDate(12, 23, 12);
    date1.showDate();
    date2.showDate();

    return 0;
}