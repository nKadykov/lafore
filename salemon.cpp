#include <iostream>
#include <iomanip>
using namespace std;

const int DISTRICT = 4;
const int MONTH = 3;

int main() {
    int d, m;
    double sales[DISTRICT][MONTH];
    for(d = 0; d < DISTRICT; d++) {
        for(m = 0; m < MONTH; m++) {
            cout << "Enter sales for district " << d + 1;
            cout << ", for month " << m + 1 << ": ";
            cin >> sales[d][m];
        }
    }
    cout << "           Month\n";
    cout << "           1        2        3";
    for(d = 0; d < DISTRICT; d++) {
        cout << "\nDistrict: " << d + 1;
        for(m = 0; m < MONTH; m++) {
            cout << setiosflags(ios::fixed) << setiosflags(ios::showpoint) << setprecision(2) << setw(10) << sales[d][m];
        }
    }
    return 0;
}