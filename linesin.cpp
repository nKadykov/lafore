#include <iostream>
using namespace std;

const int MAX = 2000;
char str[MAX];

int main() {
    cout << "Enter string: ";
    cin.get(str, MAX, '$');
    cout << "You entered: \n" << str << '\n';
    return 0; 
}