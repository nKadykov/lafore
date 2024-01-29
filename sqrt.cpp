#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double number;
    double answer;
    cout << "Enter number: ";
    cin >> number;
    answer = sqrt(number);
    cout << "Square root is " << answer << endl;
    return 0;
}