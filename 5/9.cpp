#include <iostream>
using namespace std;

int count = 0;

void function();

int main() {
    for(int i = 0; i < 10; i++) {
        function();
    }
    return 0;
}

void function() {
    static int c = 0;
    cout << "Global: " << count << '\n';
    cout << "Static: " << c << '\n';
    count++;
    c++; 
}