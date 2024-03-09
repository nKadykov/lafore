#include <iostream>
#include <process.h>

const int LIMIT = 100;

class SafeArray {
    int arr[LIMIT];
public:
    class Limit {
    public:
        int ind;
        Limit(int i) : ind(i) {}
    };
    int& operator[](int n) {
        if(n < 0 || n >= LIMIT) {
            throw Limit(n);
        }
        return arr[n];
    }
};

int main() {
    try {
        SafeArray s1;
        s1[101] = 1;
        std::cout << s1[1] << std::endl;
    }
    catch(SafeArray::Limit l) {
        std::cout << "Index " << l.ind << " is out of limit" << std::endl;
    }
    return 0;
}