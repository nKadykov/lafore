#include <iostream>
#include <process.h>
using namespace std;
const int LIMIT = 100;

class SafeArray {
    int arr[LIMIT];
public:
    int& operator[](int n) {
        if(n < 0 || n >= LIMIT) {
            cout << "\nError index!";
            exit(1);
        }
        return arr[n];
    }
};

int main() {
    SafeArray sa1;

    for(int i = 0; i < LIMIT; i++) {
        sa1[i] = i * 10;
    }

    for(int i = 0; i < LIMIT; i++) {
        int temp = sa1[i];
        cout << "Element " << i << " is " << temp << '\n';
    }
    return 0;
}