#include <iostream>
using  namespace std;

void starline() {
    for(int j = 0; j < 45; j++) {
        cout << '*';
    }
    cout << '\n';
}

int main() {
    starline();
    cout << "Distance: \n";
    starline();
    cout  << "char -128...127\n";
    starline();

    return 0;
}