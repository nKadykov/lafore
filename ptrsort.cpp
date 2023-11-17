#include <iostream>
using namespace std;

int main() {
    void bsort(int*, int);
    const int N = 10;
    int arr[N] = {37, 84, 62, 91, 11, 65, 57, 28, 19, 49};

    bsort(arr, N);

    for(int i = 0; i < N; i++) {
        cout << arr[i] << ' ';
    }

    return 0;
}

void bsort(int* ptr, int n) {
    void order(int*, int*);
    int i, k;

    for(i = 0; i < n - 1; i++) {
        for(k = i + 1; k < n; k++) {
            order(ptr + i, ptr + k);
        }
    }
}

void order(int* numb1, int* numb2) {
    if(*numb1 > *numb2) {
        int temp = *numb1;
        *numb1 = *numb2;
        *numb2 = temp;
    }
}