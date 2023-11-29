#include <fstream>
#include <iostream>
#include <process.h>
using namespace std;

const int MAX = 1000;
int buff[MAX];

int main() {
    for(int i = 0; i < MAX; i++) {
        buff[i] = i;
    }
    ofstream os;

    os.open("a:edata.dat", ios::trunc | ios::binary);
    if(!os) {
        cerr << "Error";
        exit(1);
    }

    cout << "\nWriting...";

    os.write(reinterpret_cast<char*>(buff), MAX * sizeof(int));
    if(!os) {
        cerr << "\nWriting error";
        exit(1);
    }
    os.close();

    for(int i = 0; i < MAX; i++) {
        buff[i] = 0;
    }

    ifstream is;
    is.open("a:edata.dat", ios::binary);
    if(!is) {
        cerr << "\nOpening error";
        exit(1);
    }
    
    cout << "\nReading...";
    is.read(reinterpret_cast<char*>(buff), MAX * sizeof(int));
    if(!is) {
        cerr << "\nReading error";
        exit(1);
    }

    for(int i = 0; i < MAX; i++) {
        if(buff[i] != i) {
            cerr << "\nData is incorrect";
            exit(1);
        }
    }
    cout << "\nData is right";

    return 0;
}