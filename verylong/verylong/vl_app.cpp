#include "verylong.h"

int main() {
    unsigned long numb, j;
    Verylong fact = 1; // ������������� ������� ������ Verylong

    std::cout << "Enter number: ";
    std::cin >> numb; // ���� ����� ���� long int

    for (j = numb; j > 0; j--) { // ���������
        fact = fact * j;
    }
    std::cout << "Factorial = ";
    fact.putvl(); // ������� �������� ����������
    std::cout << std::endl;

    return 0;
}