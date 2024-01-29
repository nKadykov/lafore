#include <iostream>
using namespace std;

int main() {
    float rad;
    const float PI = 3.14259F;
    cout << "Enter radius of circle: ";
    cin >> rad;
    float area = PI * rad * rad;
    cout << "Area of circle is " << area << endl;
    return 0;
}