#include <iostream>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <list>
using namespace std;

int main() {
    list<int> iList;
    ifstream infile("iter.dat");

    istream_iterator<int> file_iter(infile);
    istream_iterator<int> end_of_stream;

    copy(file_iter, end_of_stream, back_inserter(iList));

    ostream_iterator<int> ositer(cout, "--");
    copy(iList.begin(), iList.end(), ositer);
    return 0;
}