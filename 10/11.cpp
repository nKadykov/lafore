#include <iostream>
using namespace std;

class Array {
    const int NUMARRAYS;
    const int MAXSIZE;
    int** arr;
public:
    Array(int n, int m) : NUMARRAYS(n), MAXSIZE(m) {
        arr = new int*[NUMARRAYS];
        for(int i = 0; i < NUMARRAYS; i++) {
            *(arr + i) = new int[MAXSIZE];
        }
    }
    ~Array() {
        for(int i = 0; i < NUMARRAYS; i++) {
            delete[] *(arr + i);
        }
        delete[] arr;
    }
    int& operator[](int n) {
        int i = n / MAXSIZE;
        int j = n % MAXSIZE;
        return *(*(arr + i) + j);
    }
};

int main() {
    int n;
    int m;

    cout << "Enter n and m: ";
    cin >> n >> m;
    Array arr(n, m);
    
    for(int i = 0; i < n * m; i++) {
        arr[i] = i * 10;
    }
    for(int i = 0; i < n * m; i++) {
        cout << arr[i] << ((i % n == n - 1) ? '\n' : ' ');
    }

    return 0;
}