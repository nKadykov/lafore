#include <iostream>
using namespace std;

int main() {
    int p1, p2, p3, sh1, sh2, sh3, pens1, pens2, pens3, times;
    char oper;
    char point = '.';
    int sum;
    cout << "Enter first sum, operator and second sum: ";
    cin >> p1 >> point >> sh1 >> point >> pens1 >> oper;
    switch(oper) {
        case '+':
            cin >> p2 >> point >> sh2 >> point >> pens2;
            sum = (pens1 + pens2) + 12 * (sh1 + sh2) + 12 * 20 * (p1 + p2);
            pens3 = sum % 12;
            sum /= 12;
            sh3 = sum % 20;
            sum /= 20;
            p3 = sum;
            cout << "Result: " << p3 << '.' << sh3 << '.' << pens3;
            break;
        case '-':
            cin >> p2 >> point >> sh2 >> point >> pens2;
            sum = (pens1 - pens2) + 12 * (sh1 - sh2) + 12 * 20 * (p1 - p2);
            if(sum < 0) {
                cout << "First sum is lesser than second\n";
                break;
            }
            pens3 = sum % 12;
            sum /= 12;
            sh3 = sum % 20;
            sum /= 20;
            p3 = sum;
            cout << "Result: " << p3 << '.' << sh3 << '.' << pens3 << '\n';
            break;
        case '*':
            cin >> times;
            sum = p1 * 20 * 12 + sh1 * 12 + pens1;
            sum *= times;
            pens3 = sum % 12;
            sum /= 12;
            sh3 = sum % 20;
            sum /= 20;
            p3 = sum;
            cout << "Result: " << p3 << '.' << sh3 << '.' << pens3 << '\n';
            break;
        default:
            cout << "Error";
    }
    return 0;
}