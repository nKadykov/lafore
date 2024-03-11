#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

int main() {
    char ch;
    std::vector<std::string> names;
    do {
        std::string name;
        std::cin >> name;
        names.push_back(name);
        std::cout << "Continue? (y/n): ";
        std::cin >> ch;
    }
    while(ch == 'y');
    for(auto x : names) {
        std::cout << x << ' ';
    }
    return 0;
}