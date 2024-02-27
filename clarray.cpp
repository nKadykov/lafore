#include <iostream>
using namespace std;

class Array {
    int* ptr;
    int size;
public:
    Array(int s) {
        size = s;
        ptr = new int[s];
    }
    ~Array() {
        delete[] ptr;
    }
    int& operator[] (int j) {
        return *(ptr + j);
    }
};

int main() {
    const int ASIZE = 10;
    Array arr(ASIZE);

    for(int i = 0; i < ASIZE; i++) {
        arr[i] = i * i;
    }

    for(int i = 0; i < ASIZE; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;

    return 0;
}