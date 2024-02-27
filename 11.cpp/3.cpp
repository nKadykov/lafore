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
    Array(Array& a) {
        size = a.size;
        ptr = new int[size];
        for(int i = 0; i < size; i++) {
            *(ptr + i) = *(a.ptr + i);
        }
    }
    ~Array() {
        delete[] ptr;
    }
    int& operator[] (int j) {
        return *(ptr + j);
    }
    Array operator= (Array a) {
        delete[] ptr;
        size = a.size;
        ptr = new int[size];
        for(int i = 0; i < size; i++) {
            *(ptr + i) = *(a.ptr + i);
        }
        return *this;
    }
};

int main() {
    const int ASIZE = 10;
    Array arr1(ASIZE);

    for(int i = 0; i < ASIZE; i++) {
        arr1[i] = i * i;
    }
    for(int i = 0; i < ASIZE; i++) {
        cout << arr1[i] << ' ';
    }
    cout << endl;

    Array arr2(arr1);

    for(int i = 0; i < ASIZE; i++) {
        cout << arr2[i] << ' ';
    }
    cout << endl;

    Array arr3 = arr1;
    for(int i = 0; i < ASIZE; i++) {
        cout << arr3[i] << ' ';
    }

    return 0;
}