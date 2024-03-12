#include <iostream>
#include <list>
#include <algorithm>

int main() {
    std::list<int> l;
    char ch;

    do {
        int n;
        std::cout << "Enter number: ";
        std::cin >> n;
        l.push_back(n);
        std::cout << "Continue? (y/n): ";
        std::cin >> ch;
    }
    while(ch == 'y');

    std::list<int>::iterator iter1 = l.begin();
    std::list<int>::reverse_iterator iter2 = l.rbegin();

    int count = 0;
    while(count++ < l.size() / 2) {
        std::swap(*iter1++, *iter2++);
    }
    std::cout << "Result: ";
    for(iter1 = l.begin(); iter1 != l.end(); iter1++) {
        std::cout << *iter1 << ' ';
    }

    return 0;
}