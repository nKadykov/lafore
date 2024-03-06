#include "verylong.h"

int main() {
    unsigned long numb, j;
    Verylong fact = 1; // инициализация объекта класса Verylong

    std::cout << "Enter number: ";
    std::cin >> numb; // ввод числа типа long int

    for (j = numb; j > 0; j--) { // факториал
        fact = fact * j;
    }
    std::cout << "Factorial = ";
    fact.putvl(); // вывести значение факториала
    std::cout << std::endl;

    return 0;
}