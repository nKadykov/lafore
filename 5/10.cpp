#include <iostream>
using namespace std;

struct Sterling {
    int pound;
    int shilling;
    int pence;
};

Sterling function1(int, int, int);
Sterling function2(Sterling, Sterling);
void function3(Sterling);

int main() {
    int pound = 1;
    int shilling = 1;
    int pence = 1;

    Sterling s1 = function1(pound, shilling, pence);
    Sterling s21 {2, 2, 2};
    Sterling s22 {2, 2, 2};
    Sterling s2 = function2(s21, s22);
    function3(s1);
    function3(s2);
    
    return 0;
}

Sterling function1(int pounds, int shillings, int pence) {
    Sterling money;
    money.pound = pounds;
    money.shilling = shillings;
    money.pence = pence;
    return money;
}

Sterling function2(Sterling s1, Sterling s2) {
    Sterling s;
    int sum = 20 * 12 * (s1.pound + s2.pound) + 12 * (s1.shilling + s2.shilling) + (s1.pence + s2.pence);
    s.pound = sum / 20 / 12;
    sum %= (20 * 12);
    s.shilling = sum / 12;
    s.pence = sum % 12;
    return s; 
}

void function3(Sterling s) {
    cout << "Sterling: " << s.pound << "." << s.shilling << "." << s.pence << '\n';
}