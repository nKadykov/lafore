#include <iostream>
#include <cstring>
using namespace std;
const int DAYS = 7;

void bsort(char**, int n);
void order(char**, char**);

int main() {
    char* arrptrs[DAYS] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Suturday", "Sunday"};
    for(int i = 0; i < DAYS; i++) {
        cout << arrptrs[i] << ' ';
    }
    cout << endl;
    bsort(arrptrs, DAYS);
    for(int i = 0; i < DAYS; i++) {
        cout << arrptrs[i] << ' ';
    }
    return 0;
}

void bsort(char** ptr, int n) {
    int i, j;
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            order(ptr + i, ptr + j);
        }
    }
}

void order(char** ch1, char** ch2) {
    if(strcmp(*ch1, *ch2) > 0) {
        char* tempptr = *ch1;
        *ch1 = *ch2;
        *ch2 = tempptr;
    }
}