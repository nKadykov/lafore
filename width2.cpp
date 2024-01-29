#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    long pop1 = 4789426;
    long pop2 = 274124;
    long pop3 = 9761;
    cout << setw(10) << "City " << setw(12) << "Pop. " << endl << setw(10) << "Moscow " << setw(12) << pop1 << endl << setw(10) << "Kirov " << setw(12) << pop2 << endl << setw(10) <<  "Ugryumovka " << setw(12) << pop3 << endl;
    return 0; 
}