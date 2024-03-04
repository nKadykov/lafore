#include <iostream>
#include <fstream>
#include <process.h>

int main(int argc, char* argv[]) {
    if(argc != 3) {
        std::cerr << "Format: 2.exe srcfile destfile\n";
        exit(-1);
    }
    char ch;
    std::ifstream in;
    in.open(argv[1]);
    if(!in) {
        std::cerr << "File " << argv[1] << " doesn't open\n";
        exit(-1);
    }
    std::ofstream out;
    out.open(argv[2]);
    if(!out) {
        std::cout << "File " << argv[2] << "doesn't open\n";
        exit(-1);
    }
    while(in) {
        in.get(ch);
        out.put(ch);
    }

    return 0;
}