#include <iostream>
using namespace std;

class Smallobj {
private:
    int somedata;
public:
    void setdata(int d) {
        somedata = d;
    }
    void showdata() {
        cout << "Value is: " << somedata << endl;
    }
};

int main() {
    Smallobj s1, s2;
    s1.setdata(1066);
    s2.setdata(1776);
    s1.showdata();
    s2.showdata();
    return 0;
}