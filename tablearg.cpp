#include <iostream>
using namespace std;

void repchar(char, int);

int main() {
    repchar('-', 43);
    cout << "Distance: \n";
    repchar('=', 23);
    cout << "char -128...127\n";
    repchar('-', 43);
    return 0;
}

void repchar(char ch, int n) {
    for(int j = 0; j < n; j++) {
        cout << ch;
    }
    cout << '\n';
}