#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

int main() {
    list<int> theList(5);
    list<int>::iterator iter;
    int data = 0;

    for(iter = theList.begin(); iter != theList.end(); iter++) {
        *iter = data += 2;
    }
    iter = find(theList.end(), theList.end(), 8);
    if(iter != theList.end()) {
        cout << "8 is found\n";
    }
    else {
        cout << "8 is not found\n";
    }
    return 0;
}