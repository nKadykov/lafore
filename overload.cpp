#include <iostream>
using namespace std;

void repchar();
void repchar(char);
void repchar(char, int);

int main() {
    repchar();
    repchar('=');
    repchar('+', 30);

    return 0;
}

void repchar() {
    for(int j = 0; j < 45; j++) {
        cout << '*';
    }
    cout << '\n';
}

void repchar(char ch) {
    for(int j = 0; j < 45; j++) {
        cout << ch;
    }
    cout << '\n';
}

void repchar(char ch, int n) {
    for(int j = 0; j < n; j++) {
        cout << ch;
    }
    cout << '\n';
}