#include <iostream>
#include <iomanip>
using namespace std;
const int DISTRICT = 4;
const int MONTH = 3;

int main() {
    int d, m;
    double sales [DISTRICT][MONTH] = {
        { 1432.07, 234.50, 654.01 },
        { 322.00, 13838.32, 17589.88 },
        { 9328.34, 934.00, 4492.30 },
        { 12838.29, 2332.63, 32.93 }
    };
    cout << '\n';
    cout <<  "\t\tМесяц\n";
    cout << "\t\t1\t2\t3\n";
    for(d = 0; d < DISTRICT; d++) {
        cout << "\nDistrict";
        for(int m = 0; m < MONTH; m++) {
            cout << setw(10) << setiosflags(ios::fixed) << setiosflags(ios::showpoint) << setprecision(2) << sales[d][m];
        }
    }
    return 0;
}
