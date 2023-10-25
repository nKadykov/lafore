#include <iostream>
using namespace std;

class Distance {
    int feet;
    float inches;
public:
    Distance() : feet(0), inches(0.0) {}
    Distance(int ft, float in) : feet(ft), inches(in) {}
    void getdist() {
        cout << "\nEnter feet: ";
        cin >> feet;
        cout << "Enter inches: ";
        cin >> inches;
    }
    void showdist() const {
        cout << feet << "\ - " << inches << '\"';
    }
    Distance add_dist(const Distance&) const;
};

Distance Distance::add_dist(const Distance& d2) const {
    Distance temp;
    temp.inches = inches + d2.inches;
    if(temp.inches >= 12.0) {
        temp.inches -= 12.0;
        temp.feet = 1;
    }
    temp.feet += feet + d2.feet;
    return temp;
}

int main() {
    const Distance football(300, 0);
    cout << "Length is: ";
    // football.getlist(); Error
    football.showdist();
    cout << '\n';
    
    return 0;
}