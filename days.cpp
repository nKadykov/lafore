#include <iostream>
using namespace std;

int main() {
    int month, day, total_days;
    int days_per_month[12] = {31, 28, 31, 30, 31, 31, 30, 31, 30, 31};
    cout << "Enter month: ";
    cin >> month;
    cout << "Enter day: ";
    cin >> day;
    total_days = day;
    for(int i = 0; i < month - 1; i++) {
        total_days += days_per_month[i];
    }
    cout << "Days: " << total_days << '\n';
    return 0;
}