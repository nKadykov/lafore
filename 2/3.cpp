#include <iostream>

int main() {
    int var = 10;
    std::cout << var << '\n';
    var *= 2;
    std::cout << var-- << '\n';
    std::cout << var << '\n';

    return 0;
}