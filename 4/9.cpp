#include <iostream>
using namespace std;

struct Time {
    int hours;
    int minutes;
    int seconds;
};

int main() {
    Time t;
    cout << "Enter time: ";
    cin >> t.hours >> t.minutes >> t.seconds;
    long totalsecs = t.hours * 3600 + t.minutes * 60 + t.seconds;
    cout << "Total seconds: " << totalsecs;
    return 0;
}