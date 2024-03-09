#include <iostream>

template<class Type>
Type mid(Type* arr, int size) {
    Type sum = 0;
    for(int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}

int main() {
    int intarr[] {1, 2, 3};
    long longarr[] {1, 2, 3};
    double doublearr[] {1.5, 2.5, 3.5};
    char chararr[] {1, 2, 3};

    std::cout << "Int: " << mid(intarr, 3) << std::endl;
    std::cout << "Long: " << mid(longarr, 3) << std::endl;
    std::cout << "Double: " << mid(doublearr, 3) << std::endl;
    std::cout << "Char: " << static_cast<int>(mid(chararr, 3)) << std::endl;

    return 0;
}