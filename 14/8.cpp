#include <iostream>
#include <process.h>

const int LIMIT = 100;

class SafeArray {
    int arr[LIMIT];
public:
    class Limit {};
    int& operator[](int n) {
        if(n < 0 || n >= LIMIT) {
            throw Limit();
        }
        return arr[n];
    }
};

int main() {
    try {
        SafeArray s1;
        s1[1] = 1;
        std::cout << s1[1] << std::endl;
    }
    catch(SafeArray::Limit) {
        std::cout << "Out of limit" << std::endl;
    }
    return 0;
}