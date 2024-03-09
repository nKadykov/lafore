#include <iostream>

template<class T>
void swaps(T& a, T& b) {
    T temp;
    temp = a;
    a = b;
    b = temp;
}

int main() {
    int a1 = 1, b1 = 2;
    float a2 = 1, b2 = 2;
    char a3 = 1, b3 = 2;
    long a4 = 1, b4 = 2;
    std::cout << a1 << ' ' << b1 << std::endl;
    swaps(a1, b1);
    std::cout << a1 << ' ' << b1 << std::endl;
    std::cout << a2 << ' ' << b2 << std::endl;
    swaps(a2, b2);
    std::cout << a1 << ' ' << b1 << std::endl;
    std::cout << static_cast<int>(a3) << ' ' << static_cast<int>(b3) << std::endl;
    swaps(a3, b3);
    std::cout << static_cast<int>(a3) << ' ' << static_cast<int>(b3) << std::endl;
    std::cout << a4 << ' ' << b4 << std::endl;
    swaps(a4, b4);
    std::cout << a4 << ' ' << b4 << std::endl;

    return 0;
}