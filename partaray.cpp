#include <iostream>
using namespace std;
const int SIZE = 4;

 struct Part {
    int modelnumber;
    int partnumber;
    float cost;
 };

int main() {
    int n;
    Part apart[SIZE];
    for(n = 0; n < SIZE; n++) {
        cout << "Enter number of model: ";
        cin >> apart[n].modelnumber;
        cout << "Enter number of part: ";
        cin >> apart[n].partnumber;
        cout << "Enter cost: ";
        cin >> apart[n].cost;
    }
    for(n = 0; n < SIZE; n++) {
        cout << "\nModel " << apart[n].modelnumber;
        cout << "\nPart " << apart[n].partnumber;
        cout << "\nCost " << apart[n].cost;
    }
    return 0;
}