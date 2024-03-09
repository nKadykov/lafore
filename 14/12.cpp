#include <iostream>
#include <fstream>

class Dofile {
    std::fstream file;
public:
    class File {
    public:
        int num;
        File(int n): num(n) {}
    };
    Dofile(const char* filename) {
        file.open(filename, std::ios::trunc | std::ios::out | std::ios::in | std::ios::binary);
        if(!file) {
            throw File(1);
        }
    }
    void write(int* data, int n) {
        file.write(reinterpret_cast<char*>(data), n * sizeof(int));
        if(!file) {
            throw File(2);
        }
    }
    void read(int* data, int n) {
        file.read(reinterpret_cast<char*>(data), n * sizeof(int));
        if(!file) {
            throw File(3);
        }
    }
    void seek() {
        file.seekg(0);
    }
};

int main() {
    const int MAX = 1000;
    int buff[MAX];
    for(int j = 0; j < MAX; j++) {
        buff[j] = j;
    }
    try {
        Dofile f("12.dat");
        f.write(buff, MAX);
        for(int i = 0; i < MAX; i++) {
            buff[i] = 0;
        }
        f.seek();
        f.read(buff, MAX);
    }
    catch(Dofile::File err) {
        switch(err.num) {
            case 1:
                std::cerr << "Open error" << std::endl;
                break;
            case 2:
                std::cerr << "Write error" << std::endl;
                break;
            case 3:
                std::cerr << "Read error" << std::endl;
                break;
        }
        exit(1);
    }
    for(int i = 0; i < MAX; i++) {
        if(buff[i] != i) {
            std::cerr << "Data incorrect" << std::endl;
            exit(1);
        }
    }
    std::cout << "Data correct" << std::endl;

    return 0;
}