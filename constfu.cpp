#include <iostream>
using namespace std;

class aClass {
    int alpha;
public:
    void nonFunc() { alpha = 99; }
    // void conFunc() const { alpha = 99; }
};

int main() {
    aClass cl;
    cl.nonFunc();
    // cl.conFunc();

    return 0;
}