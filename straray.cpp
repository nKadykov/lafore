#include <iostream>
using namespace std;

int main() {
    const int DAYS = 7;
    const int MAX = 12;
    char star[DAYS][MAX] = 
    {
        "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"
    };
    for(int i = 0; i < DAYS; i++) {
        cout << star[i] << '\n';
    }
    return 0;
}