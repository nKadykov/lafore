#include <iostream>
using namespace std;

struct Time {
    int hours;
    int minutes;
    int seconds;
};

void swap(int&, int&);
void swapTime(Time&, Time&);

int main() {
    Time t1, t2;
    int a, b;
    char ch = ':';

    cout << "Enter numbers:\na: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    swap(a, b);
    cout << "a: " << a << ", b: " << b << '\n';
    
    cout << "Enter time 1 and 2:\nTime 1: ";
    cin >> t1.hours >> ch >> t1.minutes >> ch >> t1.seconds;
    cout << "Time 2: ";
    cin >> t2.hours >> ch >> t2.minutes >> ch >> t2.seconds;
    swap(t1, t2);
    cout << "Time 1: " << t1.hours << ch << t1.minutes << ch << t1.seconds << '\n';
    cout << "Time 2: " << t2.hours << ch << t2.minutes << ch << t2.seconds;

    return 0;
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void swapTime(Time& t1, Time& t2) {
    Time temp;
    temp = t1;
    t1 = t2;
    t2 = temp;
}