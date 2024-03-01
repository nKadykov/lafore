#include <iostream>
#include <fstream>
#include <process.h>
using namespace std;

int main(int argc, char* argv[]) {
    if(argc != 2) {
        cerr << "Format: oprint name_file" << endl;
        exit(-1);
    }
    char ch;
    ifstream infile;
    infile.open(argv[1]);
    if(!infile) {
        cerr << "Can't open " << argv[1] << endl;
        exit(-1);
    }
    ofstream outfile;
    outfile.open("PRN");
    while(!infile.get(ch)) {
        outfile.put(ch);
    }
    outfile.put('\x0C');
    return 0;
}