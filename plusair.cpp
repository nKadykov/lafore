#include <iostream>
#include <list>
#include <numeric>
using namespace std;

class Airtime {
    int hours;
    int minutes;
public:
    Airtime() : hours(0), minutes(0) {}
    Airtime(int h, int m) : hours(h), minutes(m) {}
    void display() const {
        cout << hours << ' ' << minutes;
    }
    void get() {
        char dummy;
        cout << "Enter time: ";
        cin >> hours >> dummy >> minutes;
    }
    Airtime operator+(const Airtime right) const {
        int temph = hours + right.hours;
        int tempm = minutes + right.minutes;
        if(tempm >= 60) {
            temph++;
            tempm--;
        }
        return Airtime(temph, tempm);
    }
    bool operator==(const Airtime& at2) const {
        return (hours == at2.hours) && (minutes == at2.minutes);
    }
    bool operator<(const Airtime& at2) const {
        return (hours < at2.hours) || (hours == at2.hours && minutes < at2.minutes);
    }
    bool operator!=(const Airtime& at2) const {
        return !(*this == at2) ;
    }
    bool operator>(const Airtime& at2) const {
        return !(*this < at2) && !(*this == at2);
    }
};

int main() {
    char answer;
    Airtime temp, sum;
    list<Airtime> airlist;
    do {
        temp.get();
        airlist.push_back(temp);
        cout << "Continue (y/n)? \n";
        cin >> answer;
    } while(answer != 'n');
    sum = accumulate(airlist.begin(), airlist.end(), Airtime(0, 0), plus<Airtime>());
    cout << "Sum = ";
    sum.display();
    cout << endl;
    return 0;
}