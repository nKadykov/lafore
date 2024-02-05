#include <iostream>
using namespace std;

long hms_to_sec(int, int, int);

int main() {
    char yesno;
    char dummy = ':';
    int hour, minute, second;
    long result;
    while(yesno != 'n') {
        cout << "Enter time: ";
        cin >> hour >> dummy >> minute >> dummy >> second;
        result = hms_to_sec(hour, minute, second);
        cout << "Result: " << result << '\n';
        cout << "Continue? (y/n): ";
        cin >> yesno;
    }
}

long hms_to_sec(int hour, int minute, int second) {
    long result = hour * 3600 + minute * 60 + second;
    return result;
}