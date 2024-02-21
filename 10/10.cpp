#include <iostream>
using namespace std;

const int NUMARRAYS = 10;
const int MAXSIZE = 10;

int main() {
    int* arr[NUMARRAYS];
    for(int i = 0; i < NUMARRAYS; i++) {
        *(arr + i) = new int[MAXSIZE];
    }
    
    for(int i = 0; i < NUMARRAYS; i++) {
        for(int j = 0; j < MAXSIZE; j++) {
            *(*(arr + i) + j) = (i * 10 + j) * 10;
        }
    }
    for(int i = 0; i < NUMARRAYS; i++) {
        for(int j = 0; j < MAXSIZE; j++) {
            cout << *(*(arr + i) + j) << ((j + 1) % (NUMARRAYS) ? ' ' : '\n');
        }
    }

    return 0;
}