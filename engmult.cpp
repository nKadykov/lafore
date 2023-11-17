#include <iostream>
#include <cstring>
using namespace std;

class Type {
    string dimension;
    string grade;
public:
    Type() : dimension("N/A"), grade("N/A") {}
    Type(string di, string gr) : dimension(di), grade(gr) {}
    void gettype() {
        cout << "Enter dimension: ";
        cin >> dimension;
        cout << "Enter grade: ";
        cin >> grade;
    }
    void showtype() const {
        cout << "\nDimension: " << dimension;
        cout << "\nSort: " << grade;
    }
};

class Distance {
    int feet;
    float inches;
public:
    Distance() : feet(0), inches(0.0) {}
    Distance(int ft, float in) : feet(ft), inches(in) {}
    void getdist() {
        cout << "Enter feet: ";
        cin >> feet;
        cout << "Enter inches: ";
        cin >> inches;
    }
    void showdist() const {
        cout << feet << "\' - " << inches << inches << '\"';
    }
};

class Lumber : public Type, public Distance {
    int quantity;
    double price;
public:
    Lumber() : Type(), Distance(), quantity(0), price(0.0) {}
    Lumber(string di, string gr, int ft, float in, int qu, float prc) : Type(di, gr), Distance(ft, in), quantity(qu), price(prc) {}
    void getlumber() {
        Type::gettype();
        Distance::getdist();
        cout << "Enter quantity: ";
        cin >> quantity;
        cout << "Enter price: ";
        cin >> price;
    }
    void showlumber() {
        Type::showtype();
        cout << "\nLength: ";
        Distance::showdist();
        cout << "\nPrice " << quantity << ", $" << (price * quantity) << " dollars";
    }
};

int main() {
    Lumber siding;

    cout << "\nInformation about lumber:\n";
    siding.getlumber();

    Lumber studs("2 x 4", "const", 8, 0.0, 200, 4.45F);

    cout << "\nSiding: ";
    siding.showlumber();

    cout << "Lumber: ";
    studs.showlumber();

    return 0;
}