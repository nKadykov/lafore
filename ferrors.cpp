#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream file;
    file.open("a:test.dat");

    if(!file) {
        cout << "\nCan't open GROUP.DAT";
    }
    else {
        cout << "\nFile is open";
    }
    cout << "\nError code = " << file.rdstate();
    cout << "\ngood() = " << file.good();
    cout << "\neof() = " << file.eof();
    cout << "\nfail() = " << file.fail();
    cout << "\nbad() = " << file.bad();
    file.close();

    return 0;
}