#include <fstream>
#include <iostream>
using namespace std;

int main() {
    const int MAX = 80;
    char buffer[MAX];
    ifstream infile("TEST.TXT");
    while(!infile.eof()) {
        infile.getline(buffer, MAX);
        cout << buffer << '\n';
    }

    return 0;
}