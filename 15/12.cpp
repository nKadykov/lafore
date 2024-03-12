#include <iostream>
#include <ctype.h>
#include <map>
#include <fstream>
#include <string>
#include <iomanip>
#include <iterator>

int main() {
    std::string file;
    std::cout << "Enter file: ";
    std::cin >> file;
    std::ifstream infile(file);
    if(!infile) {
        std::cout << "Opening error" << std::endl;
    }
    std::map<std::string, int> freq;
    std::map<std::string, int>::iterator iter;
    std::istream_iterator<std::string, char> is_iter(infile);
    std::istream_iterator<std::string, char> end_of_stream;
    std::string word;
    int n;
    while(is_iter != end_of_stream) {
        word = *is_iter++;
        int i = word.size() - 1;
        while(i >= 0 && ispunct(word[i])) {
            i--;
        }
        word = word.substr(0, i + 1);
        if(word.empty()) {
            continue;
        }
        for(i = 0; i < word.size(); i++) {
            word[i] = tolower(word[i]);
        }
        freq[word]++;
        n++;
    }
    for(iter = freq.begin(); iter != freq.end(); iter++) {
        std::cout << "Word: " << (*iter).first << " number: " << (*iter).second << std::endl;
    }
    return 0;
}