#include <iostream>
using namespace std;

const int SIZE = 10;

int main() {
    int a0[SIZE];
    int a1[SIZE];
    int a2[SIZE];
    int a3[SIZE];
    int a4[SIZE];
    int a5[SIZE];
    int a6[SIZE];
    int a7[SIZE];
    int a8[SIZE];
    int a9[SIZE];
    int* arr[] = {a0, a1, a2, a3, a4, a5, a6, a7, a8, a9};
    
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            arr[i][j] = (i * 10 + j) * 10;
        }
    }
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            cout << arr[i][j] << ((j == SIZE - 1) ? '\n' : ' ');
        }
    }

    return 0;
}