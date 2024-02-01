#include <iostream>
using namespace std;

struct part {
    int modelnumber;
    int partnumber;
    float cost;
};

int main() {
    part part1 = {6244, 373, 215.55F};
    part part2;

    cout << "Model " << part1.modelnumber;
    cout << ", detail " << part1.partnumber;
    cout << ", cost $" << part1.cost << endl;

    part2 = part1;

    cout << "Model " << part2.modelnumber;
    cout << ", detail " << part2.partnumber;
    cout << ", cost $" << part2.cost << endl;

    return 0;
}