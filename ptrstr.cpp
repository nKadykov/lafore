#include <iostream>
using namespace std;

int main() {
    void disptr(char*);
    char str[] = "Time";

    disptr(str);

    return 0;
}

void disptr(char* ps) {
    while(*ps) {
        cout << *ps++;
    }
    cout << '\n';
}