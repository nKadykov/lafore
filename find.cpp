#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int arr[] = {11, 22, 33, 44, 55, 66, 77, 88};
    int* ptr;
    ptr = find(arr, arr+8, 33); 
    cout << "33 is on position: " << ptr - arr + 1 << endl;
    return 0;
}