#include <iostream>
#include <fstream>
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
    void showdist() {
        cout << feet << "\' - " << inches << '\"' << endl;
    }
};

int main() {
    Distance dist;
    char ch;
    fstream file;
    file.open("1.dat", ios::binary | ios::app | ios::out | ios::in);
    do {
        cout << "Distance: ";
        dist.getdist();
        file.write((char*)&dist, sizeof(dist));
        cout << "Continue? (y/n): ";
        cin >> ch;
    }
    while(ch == 'y');
    file.seekg(0);
    file.read((char*)&dist, sizeof(dist));
    int count = 0;
    while(!file.eof()) {
        cout << "Distance " << ++count << " : ";
        dist.showdist();
        file.read((char*)&dist, sizeof(dist));
    }
    file.close();

    return 0;
}