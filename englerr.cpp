#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int isFeet(string);

class Distance {
    int feet;
    float inches;
public:
    Distance() {
        feet = 0;
        inches = 0.0;
    }
    Distance(int ft, float in) {
        feet = ft;
        inches = in;
    }
    void showdist() {
        cout << feet << "\' - " << inches << '\"';
    }
    void getdist();
};

void Distance::getdist() {
    string instr;
    while(true) {
        cout << "\nEnter feet:";
        cin.unsetf(ios::skipws);

        cin >> instr;
        if(isFeet(instr)) {
            cin.ignore(10, '\n');
            feet = atoi(instr.c_str());
            break;
        }
        cin.ignore(10, '\n');
        cout << "\nFeet must be integer";
    }
    while(true) {
        cout << "\nEnter inches:";
        cin.unsetf(ios::skipws);
        cin >> inches;
        if(inches >= 12 || inches < 0) {
            cout << "\nInches must be between 0.0 and 11.99";
            cin.clear(ios::failbit);
        }
        if(cin.good()) {
            cin.ignore(10, '\n');
            break;
        }
        cin.clear();
        cin.ignore(10, '\n');
        cout << "\nEnter error";
    }
}

int isFeet(string str) {
    int slen = str.size();
    if(slen == 0 || slen > 5) {
        return 0;
    }
    for(int i = 0; i < slen; i++) {
        if((str[i] < '0' || str[i] > '9') && str[i] != '-') {
            return 0;
        }
    }
    double n = atof(str.c_str());
    if(n < -999 || n > 999) {
        return 0;
    }
    return 1;
}

int main() {
    Distance d;
    char ans;
    do {
        d.getdist();
        cout << "\nDistance = ";
        d.showdist();
        cout << "\nOne more (y / n)?";
        cin >> ans;
        cin.ignore(10, '\n');
    } while(ans != '\n');

    return 0;
}