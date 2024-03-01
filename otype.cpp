#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[]) {
    if(argc != 2) {
        cerr << "Command: otype name_file";
        exit(-1);
    }
    char ch;
    ifstream infile;
    infile.open(argv[1]);
    if(!infile) {
        cerr << "Can't open " << argv[1];
        exit(-1);
    }
    while(!infile.get(ch)) {
        cout << ch;
    }
    return 0;
}