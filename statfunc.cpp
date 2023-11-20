#include <iostream>
using namespace std;

class Gamma {
    static int total;
    int id;
public:
    Gamma() {
        total++;
        id = total;
    }
    ~Gamma() {
        total--;
        cout << "Delete ID " << id << '\n';
    }
    static void showtotal() {
        cout << "Total: " << total << '\n';
    }
    void showid() {
        cout << "ID: " << id << '\n';
    }
};

int Gamma::total = 0;

int main() {
    Gamma g1;
    Gamma::showtotal();

    Gamma g2, g3;
    Gamma::showtotal();

    g1.showid();
    g2.showid();
    g3.showid();
    
    return 0;
}