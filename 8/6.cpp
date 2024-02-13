#include <iostream>
using namespace std;

class Time {
    int hour, min, sec;
public:
    Time() : hour(0), min(0), sec(0) {}
    Time(int h, int m, int s) : hour(h), min(m), sec(s) {}
    Time(int s) {
        hour = s / 3600;
        min = (s / 60) % 60;
        sec = s % 60;
    }
    void output() const {
        cout << hour << ":" << min << ":" << sec << '\n';
    }    
    void sum(Time, Time);
    Time operator+(Time);
    Time operator-(Time);
    Time operator*(float);
    Time operator++();
    Time operator++(int);
    Time operator--();
    Time operator--(int);
    operator float() const;
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

    Time t6(5, 5, 5);
    Time t7(2, 2, 2);
    Time t8;
    float f = 5;
    t8 = t6 - t7;
    t8.output();
    t8 = t6 * f;
    t8.output();
    
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
    if(h > 23) {
        h -= 24;
    }
    return Time(h, m, s);
}

Time Time::operator-(Time t) {
    int s, m, h;
    s = sec - t.sec;
    m = min - t.min;
    h = hour - t.hour;
    if(s < 0) {
        s += 60;
        m--;
    }
    if(m < 0) {
        m += 60;
        h--;
    }
    if(h < 0) {
        h += 24;
    }
    return Time(h, m, s);
}

Time Time::operator*(float m) {
    float f = (3600 * hour + 60 * min + sec) * m;
    return Time(f);
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

void Time::sum(Time t1, Time t2) {
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

Time::operator float() const {
    return (3600 * hour + 60 * min + sec);
}