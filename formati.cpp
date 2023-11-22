#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main() {
    char ch;
    int j;
    double d;
    string str1;
    string str2;

    ifstream infile("fdata.txt");

    infile >> ch >> j >> d >> str1 >> str2;

    cout << ch << '\n' << j << '\n' << d << '\n' << str1 << '\n' << str2 << '\n';

    return 0;
}