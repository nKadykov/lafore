#include <iostream>
using namespace std;

float circarea(float rad) {
    const float PI = 3.14259F;
    float area = PI * rad * rad;
    return area;
}

int main() {
    float rad;
    cout << "Enter radius of circle: ";
    cin >> rad;
    float area = circarea(rad);
    cout << "Area of circle is " << area << endl;
    return 0;
}