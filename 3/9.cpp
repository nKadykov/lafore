#include <iostream>
using namespace std;

int main() {
    int n;
    int m;
    cout << "Enter numbers: ";
    cin >> n >> m;
    int result = 1;
    for(int i = n; i > (n - m); i--) {
        result *= i;
    }
    cout << "Result: " << result;
    return 0;
}