#include <iostream>
using namespace std;

class Counter {
    unsigned int count;
public:
    Counter(): count(0) {};
    unsigned int get_count() {
        return count;
    }
    void operator++() {
        ++count;
    }
};

int main() {
    Counter c1, c2;
    cout << "\nc1 = " << c1.get_count();
    cout << "\nc2 = " << c2.get_count();
    ++c1;
    ++c2;
    ++c2;
    cout << "\nc1 = " << c1.get_count();
    cout << "\nc2 = " << c2.get_count();
    return 0;
}