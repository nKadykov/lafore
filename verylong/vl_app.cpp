#include "verylong.h"

int main() {
    unsigned long numb, j;
    Verylong fact = 1;

    std::cout << "Enter number: ";
    std::cin >> numb;

    for(j = numb; j > 0; j--) {
        fact = fact * j;
    }
    std::cout << "Factorial = ";
    fact.putvl();
    std::cout << std::endl;
    return 0;
}