#include <iostream>
#include <algorithm>
using namespace std;

int source1[] = {2, 3, 4, 6, 8};
int source2[] = {1, 3, 5};
int dest[8];

int main() {
    merge(source1, source1+5, source2, source2+3, dest);
    for(int j = 0; j < 8; j++) {
        cout << dest[j] << ' ';
    }
    return 0;
}