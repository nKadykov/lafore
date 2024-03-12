#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main() {
    int arr[] {0, 2, 4, 6, 8}; // инициализация массива
    std::set<int> s {1, 3, 5, 7, 9}; // инициализация множества
    std::vector<int> v(10); // инициализация вектора
    merge(arr, arr + 5, s.begin(), s.end(), v.begin()); // слияние массива и множества в вектор
    for(auto x : v) { // вывод содержимого вектора на экран
        std::cout << x << ' ';
    }
    return 0;
}