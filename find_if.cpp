#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

bool isDon(string);

string names[] = {"Sergey", "Tatyana", "Elena", "Dmitriy", "Michail", "Vladimir"};

int main() {
    string* ptr;
    ptr = find_if(names, names+5, isDon);
    if(ptr == names+5) {
        cout << "Dmitriy is not in list";
    }
    else {
        cout << "Dmitriy is in position " << ptr - names << " int list\n";
    }
    return 0;
}

bool isDon(string name) {
    return name == "Dmitriy";
}