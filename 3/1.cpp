#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cin >> n;
    for(int i = n; i <= 100 * n; i += 10 * n) {
        for(int j = i; j < (i + 10 * n); j += n) {
            cout << setw(3) << j << ' ';
        }
        cout << '\n';
    }
    return 0; 
}