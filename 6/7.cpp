#include <iostream>
using namespace std;

class Angle {
    int grad;
    float min;
    char dir;
public:
    Angle() : grad(0), min(0), dir(' ') {}
    Angle(int g, int m, char d) : grad(g), min(m), dir(d) {}
    void output() {
        cout << grad << ' ' << min << '\'' << ' ' << dir << '\n';
    }
};

int main() {
    Angle lat(149, 34.8, 'W');
    Angle lon(17, 31.5, 'S');

    lat.output();
    lon.output();

    return 0;
}
