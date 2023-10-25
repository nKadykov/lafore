#include <iostream>
using namespace std;

class foo {
    static int count;
public:
    foo() { count++; }
    int getcount() { return count; }
};

int foo::count = 0;

int main() {
    foo f1, f2, f3;
    cout << "Objects: " << f1.getcount() << '\n';
    cout << "Objects: " << f2.getcount() << '\n';
    cout << "Objects: " << f3.getcount() << '\n';

    return 0;
}