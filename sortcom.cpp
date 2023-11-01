#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

char* names[] = {"Sergey", "Tatyana", "Elena", "Dmitriy", "Michail", "Vladimir"};

bool alpha_comp(char*, char*);

int main() {
    sort(names, names+6, alpha_comp);
    for(int j = 0; j < 6; j++) {
        cout << names[j] << '\n';
    }
    return 0;
}

bool alpha_comp(char* s1, char* s2) {
    return (strcmp(s1, s2) < 0) ? true : false;
}