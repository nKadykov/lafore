#include <iostream>
using namespace std;
const int DAYS = 7;

int main() {
    char* arrptrs[DAYS] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Suturday", "Sunday"};
    for(int i = 0; i < DAYS; i++) {
        cout << arrptrs[i] << '\n';
    }
    return 0;
}