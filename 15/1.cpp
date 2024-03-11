#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<float> arr;
    char ch;
    do {
        float f;
        std::cout << "Enter float number: ";
        std::cin >> f;
        arr.push_back(f);
        std::cout << "Continue? (y/n): ";
        std::cin >> ch;
    }
    while(ch == 'y');
    sort(arr.begin(), arr.end());
    for(auto& x : arr) {
        std::cout << x << ' ';
    }
    return 0;
}