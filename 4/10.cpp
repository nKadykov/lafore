#include <iostream>
using namespace std;

struct Sterling {
    int pound;
    int shilling;
    int pence;
};

int main() {
    double sum;
    cout << "Enter sum: ";
    cin >> sum;
    sum *= 100;
    int p = static_cast<int>(sum);
    Sterling s;
    s.pence = p % 12;
    p /= 12;
    s.shilling = p % 20;
    p /= 20;
    s.pound = p;
    
    cout << "Sum is: " << s.pound << "." << s.shilling << "." << s.pence;

    return 0;
}