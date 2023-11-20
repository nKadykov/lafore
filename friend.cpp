#include <iostream>
using namespace std;

class Beta;

class Alpha {
    int data;
public:
    Alpha() : data(3) {}
    friend int frifunc(Alpha, Beta);
};

class Beta {
    int data;
public:
    Beta() : data(7) {}
    friend int frifunc(Alpha, Beta);
};

int frifunc(Alpha a, Beta b) {
    return (a.data + b.data);
}

int main() {
    Alpha aa;
    Beta bb;

    cout << frifunc(aa, bb) << '\n';
    return 0;
}