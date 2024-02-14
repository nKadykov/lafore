#include <iostream>
#include <process.h>
using namespace std;
const int LIMIT = 100;

class SafeArray {
    int low;
    int up;
    int arr[LIMIT];
public:
    SafeArray() : low(0), up(99) {}
    SafeArray(int l, int u) : low(l), up(u) {
        if(up - low > LIMIT) {
            cout << "Error boundaries!\n";
            exit(1);
        }
    }
    int& operator[](int n) {
        n -= low;
        if(n < (low - low) || n > (up - low)) {
            cout << "Error index!\n";
            exit(1);
        }
        return arr[n];
    }
};

int main() {
    int low;
    int up;
    cout << "Enter boundaries: ";
    cin >> low >> up;
    SafeArray sa1(low, up);

    for(int i = 0; i <= (up - low); i++) {
        int n = i + 100;
        sa1[n] = i * 10;
    }

    for(int i = 0; i <= (up - low); i++) {
        int n = i + 100;
        int temp = sa1[n];
        cout << "Element " << i << " is " << temp << '\n';
    }
    return 0;
}