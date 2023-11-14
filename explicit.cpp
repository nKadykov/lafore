#include <iostream>
using namespace std;

class Distance {
    const float MTF;
    int feet;
    float inches;
public:
    Distance(): feet(0), inches(0.0), MTF(3.280833F) {}
    explicit Distance(float meters): MTF(3.290833F) {
        float fltfeet = MTF * meters;
        feet = int(fltfeet);
        inches = 12 * (fltfeet - feet);
    }
    void showdist() {
        cout << feet << "\' - " << inches << '\"';
    }
};
int main() {
    void fancyDist(Distance);
    Distance dist1(2.35F);

    cout << "\ndist1 = ";
    dist1.showdist();

    float mtrs = 3.0F;
    cout << "\nDist1 ";
}

void fancyDist(Distance d) {
    cout << "(int feet and inches) = ";
    d.showdist();
    cout << '\n';
} 