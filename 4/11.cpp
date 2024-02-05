#include <iostream>
using namespace std;

struct Time {
    int hours;
    int minutes;
    int seconds;
};

int main() {
    Time t1, t2, t3;
    char dummy = ':';

    cout << "Enter first time: ";
    cin >> t1.hours >> dummy >> t1.minutes >> dummy >> t1.seconds;
    cout << "Enter second time: ";
    cin >> t2.hours >> dummy >> t2.minutes >> dummy >> t2.seconds;

    int sum = t1.hours * 3600 + t1.minutes * 60 + t1.seconds + t2.hours * 3600 + t2.minutes * 60 + t2.seconds;
    t3.hours = sum / 3600;
    sum %= 3600;
    t3.minutes = sum / 60;
    t3.seconds = sum % 60;

    cout << "Total time: " << t3.hours << ':' << t3.minutes << ':' << t3.seconds;

    return 0;
}