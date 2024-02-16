#include <iostream>
#include <process.h>
using namespace std;
const int LIMIT = 100;

class SafeArray {
    int arr[LIMIT];
public:
    int& operator[](int n) {
        if(n < 0 || n >= LIMIT) {
            cout << "Error index!\n";
            exit(1);
        }
        return arr[n];
    }
};

class Safehilo : public SafeArray {
    int low;
    int up;
public:
    Safehilo() : low(0), up(99) {}
    Safehilo(int l, int u) : low(l), up(u) {
        if((low > up) || (up - low >= LIMIT)) {
            cout << "Boundaries error\n";
            exit(1);
        }
    }
    int& operator[](int n) {
        if(n < low || n > up) {
            cout << "Incorrect index\n";
            exit(1);
        }
        return SafeArray::operator[](n - low);
    }
};

int main() {
    int low, up;
    cout << "Enter boundaries (low, up): ";
    cin >> low >> up;
    Safehilo sa1(low, up);

    for(int i = low; i <= up; i++) {
        sa1[i] = i * 10;
    }

    for(int i = low; i <= up; i++) {
        int temp = sa1[i];
        cout << "Element " << i << " is " << temp << '\n';
    }
    return 0;
}