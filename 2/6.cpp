#include <iostream>
using namespace std;

int main() {
    double pound = 1.487;
    double frank = 0.172;
    double deutsch = 0.584;
    double yen = 0.00955;
    double dollar;
    cin >> dollar;
    cout << "Pound: " << dollar / pound << '\n';
    cout << "Frank: " << dollar / frank << '\n';
    cout << "Deutsch: " << dollar / deutsch << '\n';
    cout << "Yen: " << dollar / yen << '\n';
    return 0;
}