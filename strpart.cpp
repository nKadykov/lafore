#include <iostream>
#include <cstring>
using namespace std;

class Part {
    char partname[30];
    int partnumber;
    double cost;
public:
    void setpart(char pname[], int pn, double c) {
        strcpy(partname, pname);
        partnumber = pn;
        cost = c;
    }
    void showpart() {
        cout << "\nName: " << partname;
        cout << ", number = " << partnumber;
        cout << ", cost = " << cost;
    }
};

int main() {
    Part part1, part2;

    part1.setpart("Part1", 4474, 217.55);
    part2.setpart("Part2", 9924, 419.25);
    cout << "\nSecond part: ";
    part1.showpart();
    cout << "\nSecond part: ";
    part2.showpart();
    return 0;
}