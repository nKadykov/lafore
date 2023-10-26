#include <iostream>
using namespace std;

int main() {
    void order(int&, int&);
    int n1 = 99, n2 = 11;
    int n3 = 22,n4 = 88;
    order(n1, n2);
    order(n3, n4);
    cout << "n1 = " << n1 << '\n';
    cout << "n2 = " << n2 << '\n';
    cout << "n3 = " << n3 << '\n';
    cout << "n4 = " << n4 << '\n';

    return 0;
}

void order(int& numb1, int& numb2) {
    if(numb1 > numb2) {
        int temp = numb1;
        numb1 = numb2;
        numb2 = temp;
    }
}