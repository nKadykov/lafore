#include <iostream>
#include <fstream>
#include <iterator>

int main() {
    std::string file1, file2;
    std::cout << "Enter file1 file2: ";
    std::cin >> file1 >> file2;
    std::ifstream in(file1);
    if(!in) {
        std::cout << "Opening error" << std::endl;
    }
    std::ofstream out(file2);
    if(!out) {
        std::cout << "Writing error" << std::endl;
    }
    std::istream_iterator<int, char> is_iter(in);
    std::istream_iterator<int, char> end_of_stream;
    std::ostream_iterator<int, char> os_iter(out, " ");
    while(is_iter != end_of_stream) {
        *os_iter++ = *is_iter++;
    }
}