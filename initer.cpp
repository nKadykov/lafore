#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;

int main() {
    list<float> fList(5);
    cout << "Enter numbers:\n";
    istream_iterator<float> cin_iter(cin);
    istream_iterator<float> end_of_stream;
    copy(cin_iter, end_of_stream, fList.begin());
    cout << '\n';
    ostream_iterator<float> ositer(cout, "--");
    copy(fList.begin(), fList.end(), ositer);
    return 0;
}
