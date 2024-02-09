#include <iostream>
using namespace std;

class Money {
    long double sum;
public:
    void mstold(string money) {
        long double number;
        string n;
        for(int i = 0; i < money.size(); i++) {
            if(money[i] >= '0' && money[i] <= '9' || money[i] == '.') {
                n += money[i];
            }
        }
        sum = stold(n);
    }
    void getmoney() {
        cout << "Money: " << sum;
    }
};

int main() {
    string money;
    cout << "Enter number: ";
    char dollar = '$';
    char point = ',';
    cin >> money;
    Money m;
    m.mstold(money);
    m.getmoney();
    return 0;
}