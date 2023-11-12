#include <iostream>
#include <iomanip>
using namespace std;
const int DISTRICT = 4;
const int MONTH = 3;

void display(double [DISTRICT][MONTH]);

int main() {
    double sales[DISTRICT][MONTH] = 
    {
        {1432.07, 234.05, 654.01},
        {322.00, 13838.32, 17589.88},
        {9328.34, 934.00, 4492.30},
        {12838.29, 2332.64, 32.93}
    };
    display(sales);
    return 0;
}

void display(double funsales[DISTRICT][MONTH]) {
    int d, m;
    cout << "\t\t\tMonth\n";
    cout << "\t1\t2\t3\n";
    for(d = 0; d < DISTRICT; d++) {
        cout << "\nDistrict" << d + 1;
        for(m = 0; m < MONTH; m++) {
            cout << setiosflags(ios::fixed) << setw(10) << setiosflags(ios::showpoint) << setprecision(2) << funsales[d][m];
        }
    }
}
