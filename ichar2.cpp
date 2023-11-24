#include <fstream>
#include <iostream>
using namespace std;

int main() {
    ifstream infile("TEST.txt");
    cout << infile.rdbuf();

    return 0;
}