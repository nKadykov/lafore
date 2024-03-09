#include <iostream>

int main() {
    const unsigned long SIZE = 10000;
    char* ptr;

    try {
        ptr = new char[SIZE];
    }
    catch(std::bad_alloc) {
        std::cout << "Exception bad_alloc: no memory" << std::endl;
        return(1);
    }
    delete[] ptr;
    std::cout << "Memory use is successful" << std::endl;

    return 0;
}