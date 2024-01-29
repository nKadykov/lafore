#include <iostream>
using namespace std;

int main() {
    int count = 10;
    cout << "count = " << count << endl;
    cout << "count = " << ++count << endl;
    cout << "count = " << count << endl;
    cout << "count = " << count++ << endl; 
    cout << "count = " << count;
    return 0;
}