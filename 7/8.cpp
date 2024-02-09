#include <iostream>
using namespace std;

const int LIMIT = 7;

class Safearray {
    int arr[LIMIT];
public:
    void putel(int index, int element) {
        if((index < LIMIT) && (index > 0)) {
            arr[index] = element;
        }
        else {
            cout << "Out of limit'\n";
        }
    }
    int getel(int index) {
        if((index < LIMIT) && (index > 0)) {
            return arr[index];
        }
        else {
            cout << "Out of limit'\n";
        }
        return 0;
    }
};

int main() {
    Safearray sa1;
    int temp = 12345;
    sa1.putel(7, temp);
    temp = sa1.getel(7);
    cout << temp;
    return 0;
}