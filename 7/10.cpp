#include <iostream>
using namespace std;

const int SIZE = 10;

class Matrix {
    int width;
    int height;
    int mas[SIZE][SIZE];
public:
    Matrix() : width(SIZE), height(SIZE) {
    }
    Matrix(int m, int n) : width(m), height(n) {}
    void putel(int m, int n, int temp) {
        if(m < 0 || m >= width || n < 0 || n >= height) {
            cout << "Error\n";
        }
        else {
            mas[m][n] = temp;
        }
    }
    int getel(int m, int n) {
        if(m < 0 || m >= width || n < 0 || n >= height) {
            cout << "Error\n";
            exit(1);
        }
        else {
            return mas[m][n];
        }
    }
};

int main() {
    Matrix m(3, 4);
    int temp = 12345;
    m.putel(1, 2, temp);
    temp = m.getel(1, 2);
    cout << temp << '\n';
    return 0;
}