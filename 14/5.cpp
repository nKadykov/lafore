#include <iostream>

template<class Type>
Type amax(Type* a, int size) {
    Type m = a[0];
    for(int i = 0; i < size; i++) {
        if(a[i] > m) {
            m = a[i];
        }
    }
    return m;
}

int main() {
    int intarr[] {1, 2, 3};
    char chararr[] {1, 2, 3};
    long longarr[] {1L, 2L, 3L};
    double doublearr[] {1.5, 2.5, 3.5};
    int intmax = amax(intarr, 3);
    char charmax = amax(chararr, 3);
    long longmax = amax(longarr, 3);
    double doublemax = amax(doublearr, 3);
    std::cout << intmax << std::endl;
    std::cout << static_cast<int>(charmax) << std::endl;
    std::cout << longmax << std::endl;
    std::cout << doublemax << std::endl;

    return 0;
}