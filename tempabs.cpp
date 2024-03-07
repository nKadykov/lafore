#include <iostream>

template<class T>
T abs(T n) {
    return (n < 0) ? -n : n;
}

int main() {
    int int1 = 5;
    int int2 = -6;
    long long1 = 70000L;
    long long2 = -80000L;
    double double1 = 9.95;
    double double2 = -10.15;

    std::cout << "abs(" << int1 << ") = " << abs(int1) << std::endl;
    std::cout << "abs(" << int2 << ") = " << abs(int2) << std::endl;
    std::cout << "abs(" << long1 << ") = " << abs(long1) << std::endl;
    std::cout << "abs(" << long2 << ") = " << abs(long2) << std::endl;
    std::cout << "abs(" << double1 << ") = " << abs(double1) << std::endl;
    std::cout << "abs(" << double2 << ") = " << abs(double2) << std::endl;

    return 0;
}