#include <iostream>
using namespace std;

class Part {
    int modelnumber;
    int partnumber;
    float cost;
public:
    void setpart(int mn, int pn, float c) {
        modelnumber = mn;
        partnumber = pn;
        cost = c;
    }
    void showpart() {
        cout << "Model " << modelnumber;
        cout << ", detail " << partnumber;
        cout << ", cost " << cost << '\n';
    }
};

int main() {
    Part part1;
    part1.setpart(6244, 373, 217.55F);
    part1.showpart();

    return 0;
}