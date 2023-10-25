#include <iostream>
using namespace std;

class Time {
    int hour;
    int minute;
    int second;
public:
    Time() : hour(0), minute(0), second(0) {}
    Time(int h, int m, int s) { 
        hour = h;
        minute = m;
        second = s;
    }
    void showTime() const {
        if(hour < 10)
            cout << '0';
        cout << hour << ':';
        if(minute < 10)
            cout << '0';
        cout << minute << ':';
        if(second < 10)
            cout << '0';
        cout << second << '\n';
    }
    Time addTime(Time time1, Time time2) {
        Time temp;
        int add = 0;
        second = time1.second + time2.second;
        if(second > 59)
            add = 1;
        minute = time1.minute + time2.minute + add;
        if(minute > 59)
            add = 1;
        else
            add = 0;
        hour = time1.hour + time2.hour + add;
        if(hour > 23)
            hour = hour - 24;
        return temp;
    }
};

int main() {
    const Time time(1, 1, 9), time1(13, 23, 43), time2(12, 14, 15);
    time.showTime();
    Time temp;
    temp.addTime(time1, time2);
    temp.showTime();

    return 0;
}