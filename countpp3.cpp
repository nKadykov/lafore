#include <iostream>
using namespace std;

class Counter {
    unsigned int count;
public:
    Counter(): count(0) {}
    Counter(int x): count(x) {}
    unsigned int get_count() {
        return count;
    }
    Counter operator++() {
        ++count;
        return Counter(count);
    }
};

int main() {
    Counter c1, c2;

    cout << "\nc1 = " << c1.get_count();
    cout << "\nc2 = " << c2.get_count();

    ++c1;

    c2 = ++c1;
    
    cout << "\nc1 = " << c1.get_count();
    cout << "\nc2 = " << c2.get_count();

    return 0;
}