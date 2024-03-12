#include <iostream>
#include <algorithm>

const int MAX = 20;

int main() {
    int arr[MAX];
    for(int i = 0; i < MAX; i++) {
        arr[i] = i;
    }
    std::cout << "Array:\n";
    for(int i = 0; i < MAX; i++) {
        std::cout << arr[i] << ((i == MAX - 1) ? '\n' : ' ');
    }
    int first1, last1, first2;
    std::cout << "Enter first1, last1, first2: ";
    std::cin >> first1 >> last1 >> first2;
    if(first1 < 0 || first1 >= MAX) {
        std::cout << "Error: first1" << std::endl;
        exit(1);
    }
    if(last1 < 0 || last1 >= MAX) {
        std::cout << "Error: last1" << std::endl;
        exit(1);
    }
    if(first1 > last1) {
        std::cout << "Error: first1, last1" << std::endl;
        exit(1);
    }
    if(first2 == first1) {
        std::cout << "Error: first1, first2" << std::endl;
        exit(1);
    }
    int len = last1 - first1;
    if((first2 < 0 - len) || (first2 >= MAX)) {
        std::cout << "Error: first2" << std::endl;
        exit(1);
    }
    if(first2 < 0) {
        first1 = first1 - first2;
        first2 = 0;
        std::cout << "Error: first2" << std::endl;
    }
    if(first2 + len >= MAX) {
        last1 = first1 + (MAX - 1 - first2);
        std::cout << "Error: last2" << std::endl;
    }
    std::copy(arr + first1, arr + last1 + 1, arr + first2);
    for(int i = 0; i < MAX; i++) {
        std::cout << arr[i] << ((i == MAX - 1) ? '\n' : ' ');
    }
    return 0;
}