#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

int main() {
    std::vector<std::string> v;
    v.push_back("Qwerty");
    v.push_back("Asdfgh");
    v.push_back("Zxcvbn");

    std::cout << "Vector with " << v.size() << " size" << std::endl;
    for(int i = 0; i < v.size(); i++) {
        std::cout << i << ". " << v[i] << std::endl;
    }
    std::string str;
    std::cout << "Enter string: ";
    getline(std::cin, str);

    std::vector<std::string>::iterator iter;
    iter = find_if(v.begin(), v.end(), std::bind2nd(std::equal_to<std::string>(), str));
    if(iter == v.end()) {
        std::cout << "Absent" << std::endl;
    }
    else {
        std::cout << "Position: " << iter - v.begin() + 1 << std::endl;
    }

    return 0;
}