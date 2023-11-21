#include <iostream>
using namespace std;

class What {
    int alpha;
public:
    void tester() {
        this->alpha = 11;
        cout << this->alpha;
    }
};

int main() {
    What w;
    w.tester();

    return 0;
}