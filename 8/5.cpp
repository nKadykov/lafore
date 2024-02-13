#include <iostream>
using namespace std;

class Time {
    int hour, min, sec;
public:
    Time() : hour(0), min(0), sec(0) {}
    Time(int h, int m, int s) : hour(h), min(m), sec(s) {}
    void output() const {
        cout << hour << ":" << min << ":" << sec << '\n';
    }    
    void sum(Time t1, Time t2) {
        sec = t1.sec + t2.sec;
        if(sec > 59) {
            sec -= 60;
            min++;
        }
        min += t1.min + t2.min;
        if(min > 59) {
            min -= 60;
            hour++;
        }
        hour += t1.hour + t2.hour;
    }
    Time operator+(Time);
    Time operator++();
    Time operator++(int);
    Time operator--();
    Time operator--(int);
};

int main() {
    Time t1(5, 59, 59);
    Time t2(4, 30, 30);

    Time t3;
    t3 = t1 + t2;
    cout << "Time = ";
    t3.output();

    Time t4(0, 0, 0);
    Time t5(23, 59, 59);
    t5++;
    t4.output();
    t5--;
    t5.output();
    --t4;
    t4.output();
    t4++;
    t4.output();
    
    return 0;
}

Time Time::operator+(Time t) {
    int s, m, h;
    s = sec + t.sec;
    if(s > 59) {
        s -= 60;
        m++;
    }
    m += min + t.min;
    if(m > 59) {
        m -= 60;
        h++;
    }
    h += hour + t.hour;
    return Time(h, m, s);
}

Time Time::operator++() {
    sec++;
    if(sec == 60) {
        sec -= 60;
        min++;
    }
    if(min == 60) {
        min -= 60;
        hour++;
    }
    if(hour == 24) {
        hour = 0;
    }
    return Time(hour, min, sec);
}

Time Time::operator++(int) {
    sec++;
    if(sec == 60) {
        sec -= 60;
        min++;
    }
    if(min == 60) {
        min -= 60;
        hour++;
    }
    if(hour == 24) {
        hour = 0;
    }
    return Time(hour, min, sec);
}

Time Time::operator--() {
    sec--;
    if(sec == -1) {
        sec = 59;
        min--;
    }
    if(min == -1) {
        min = 59;
        hour--;
    }
    if(hour == -1) {
        hour = 23;
    }
    return Time(hour, min, sec);
}

Time Time::operator--(int) {
    sec--;
    if(sec == -1) {
        sec = 59;
        min--;
    }
    if(min == -1) {
        min = 59;
        hour--;
    }
    if(hour == -1) {
        hour = 23;
    }
    return Time(hour, min, sec);
}