#include <iostream>
using namespace std;

class Distance {
    int feet;
    float inches;
public:
    Distance() : feet(0), inches(0.0) {}
    Distance(int ft, float in) : feet(ft), inches(in) {}
    friend istream& operator >> (istream& s, Distance& d);
    friend ostream& operator << (ostream& s, Distance& d);
};

istream& operator >> (istream& s, Distance& d) {
    cout << "Enter feet: ";
    s >> d.feet;
    cout << "Enter inches: ";
    s >> d.inches;
    return s;
}

ostream& operator << (ostream& s, Distance& d) {
    s << d.feet << "\' - " << d.inches << "\"";
    return s;
}

int main() {
    Distance dist1, dist2;
    Distance dist3(11, 6.25);
    cout << "Enter two distances" << endl;
    cin >> dist1 >> dist2;
    cout << "dist1 = " << dist1 << endl;
    cout << "dist2 = " << dist2 << endl;
    cout << "dist3 = " << dist3 << endl;

    return 0;
}