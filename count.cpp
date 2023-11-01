#include <iostream>
#include <algorithm>
using namespace std;

int arr[] = {11, 22, 33, 44, 55, 66, 77};

int main() {
    int n = count(arr, arr+8, 33);
    cout << "33 number: " << n;
    return 0; 
}