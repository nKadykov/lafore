#include <iostream>
#include <cstring>
using namespace std;

class Scrollbar {
    int size;
    mutable string owner;
public:
    Scrollbar(int sz, string own): size(sz), owner(own) {}
    void setSize(int sz) {
        size = sz;
    }
    void setOwner(string own) const {
        owner = own;
    }
    int getSize() const {
        return size;
    }
    string getOwner() const {
        return owner;
    }
};

int main() {
    const Scrollbar sbar(60, "Application 1");

    sbar.setOwner("Application 2");

    cout << sbar.getSize() << ", " << sbar.getOwner() << '\n';

    return 0;
}