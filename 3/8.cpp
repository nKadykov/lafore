#include <iostream>
using namespace std;

int main() {
    char ans = ' ';
    while(ans != 'n') {
        int p1, p2, p3, sh1, sh2, sh3, pens1, pens2, pens3;
        cout << "Enter first sum: ";
        cin >> p1 >> sh1 >> pens1;
        cout << "Enter second sum: ";
        cin >> p2 >> sh2 >> pens2;
        pens3 = pens1 + pens2;
        sh3 = sh1 + sh2;
        p3 = p1 + p2;
        if(pens3 > 11) {
            pens3 -= 12;
            sh3 += 1;
        }
        if(sh3 > 19) {
            sh3 -= 20;
            p3 += 1;
        }
        cout << "Sum: " << p3 << ' ' << sh3 << ' ' << pens3 << '\n';
        cout << "Continue? (y/n): ";
        cin >> ans;
    }
}