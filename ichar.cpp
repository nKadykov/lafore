#include <fstream>
#include <iostream>
using namespace std;

int main() {
    char ch;
    ifstream infile("TEST.txt");
    while(infile) {
        infile.get(ch);
        cout << ch;
    }
    return 0;
}