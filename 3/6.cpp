#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

int main() {
    unsigned int numb;
    unsigned long fact;
    while(numb != 0) {
        cout << "Enter integer: ";
        cin >> numb;
        if(numb != 0) {
            fact = 1;
            for(int j = numb; j > 0; j--) {
                fact *= j;
            }
            cout << "Factorial is " << fact << endl;
        }
    }
    return 0;
}