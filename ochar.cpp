#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str = "Time is great teacher, but it kills its students";
    ofstream outfile("TEXT.txt");
    for(int i = 0; i < str.size(); i++) {
        outfile.put(str[i]);
    }
    cout << "File is written";

    return 0;
}