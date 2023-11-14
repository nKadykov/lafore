#include <iostream>
#include <cstring>
using namespace std;

int main () {
    char charray[80];
    string word;

    cout << "Enter word: ";
    cin >> word;
    int wlen = word.length();
    cout << word.capacity() << ' ' << word.max_size() << '\n';
    
    cout << "One letter: ";
    for(int i = 0; i < wlen; i++) {
        cout << word.at(i);
    }
    word.copy(charray, wlen, 0);
    charray[wlen] = 0;
    cout << "\nArray have " << charray << '\n';
    return 0;
}