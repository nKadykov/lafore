#include <iostream>
#include <process.h>
using namespace std;
const int LIMIT = 100;

template <class Type>
class SafeArray {
    Type arr[LIMIT];
public:
    Type& operator[](int n) {
        if(n < 0 || n >= LIMIT) {
            cout << "\nError index!";
            exit(1);
        }
        return arr[n];
    }
};

int main() {
    SafeArray<int> a1;
    a1[0] = 1;
    std::cout << a1[0] << std::endl;
    SafeArray<double> a2;
    a2[0] = 1.2;
    std::cout << a2[0] << std::endl;

    return 0;
}