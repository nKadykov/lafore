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
};

int main() {
    const Time t1(5, 59, 59);
    const Time t2(4, 30, 30);

    Time t3;
    t3.sum(t1, t2);
    cout << "Time = ";
    t3.output();
    
    return 0;
}