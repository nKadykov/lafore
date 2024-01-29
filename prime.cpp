#include <iostream>
#include <process.h>
using namespace std;

int main() {
    unsigned long n;
    unsigned long j;
    cin >> n;
    for(j = 2; j <= n / 2; j++) {
        if(n % j == 0) {
            cout << "Number is not prime; divides by " << j << endl;
            exit(0);
        }
    }
    cout << "Number is not prime\n";
    return 0;
}