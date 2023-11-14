#include <iostream>
#include <cstring>
using namespace std;

class Time24 {
    int hours;
    int minutes;
    int seconds;
public:
    Time24(): hours(0), minutes(0), seconds(0) {}
    Time24(int h, int m, int s): hours(h), minutes(m), seconds(s) {}
    void display() const {
        if(hours < 10) {
            cout << '0';
        }
        cout << hours << ':';
        if(minutes < 10) {
            cout << '0';
        }
        cout << minutes << ':';
        if(seconds < 10) {
            cout << '0';
        }
        cout << seconds;
    }
    int getHrs() const {
        return hours;
    }
    int getMins() const {
        return minutes;
    }
    int getSecs() const {
        return seconds;
    }
};

class Time12 {
    bool pm;
    int hrs;
    int mins;
public:
    Time12(): pm(true), hrs(0), mins(0) {}
    Time12(Time24);
    Time12(bool ap, int h, int m): pm(ap), hrs(h), mins(m) {}
    void display() const {
        cout << hrs << ':';
        if(mins < 10) {
            cout << '0';
        }
        cout << mins << ' ';
        string am_pm = pm ? "p.m." : "a.m.";
        cout << am_pm;
    }
};

Time12::Time12(Time24 t24) {
    int hrs24 = t24.getHrs();

    pm = t24.getHrs() < 12 ? false : true;
    
    mins = (t24.getSecs() < 30) ? t24.getMins() : t24.getMins() + 1;
    if(mins == 60) {
        mins = 0;
        ++hrs24;
        if(hrs24 == 12 || hrs24 == 24) {
            pm = (pm == true) ? false : true;
        }
    }
    hrs = (hrs24 < 13) ? hrs24 : hrs24 - 12;
    if(hrs == 0) {
        hrs = 12;
        pm = false;
    }
}

int main() {
    int h, m, s;

    while(true) {
        cout << "\nEnter 24-hour time: \n";
        cout << "Hours(0 to 23): ";
        cin >> h;
        if(h > 23) {
            return 1;
        }
        cout << "Minutes: ";
        cin >> m;
        cout << "Seconds: ";
        cin >> s;
        Time24 t24(h, m, s);
        cout << "You entered: ";
        t24.display();

        Time12 t12 = t24;
        cout << "\n12 hour time: ";
        t12.display();
    }
    return 0;
}