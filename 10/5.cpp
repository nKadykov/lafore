#include <iostream>
using namespace std;
const int SIZE = 3;

void addarrays(float*, float*, float*);
void display(float*);

int main() {
    float arr1[SIZE] = {1, 2, 3};
    float arr2[SIZE] = {1, 2, 3};
    float arr3[SIZE];

    addarrays(arr1, arr2, arr3);

    display(arr1);
    display(arr2);
    display(arr3);

    return 0;
}

void addarrays(float* arr1, float* arr2, float* arr3) {
    for(int i = 0; i < SIZE; i++) {
        *(arr3 + i) = *(arr1 + i) + *(arr2 + i);

    }
}

void display(float* arr) {
    for(int i = 0; i < SIZE; i++) {
        cout << *(arr + i) << ' ';
    }
    cout << endl;
}