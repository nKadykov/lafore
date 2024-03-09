#include <iostream>

class Distance {
    int feet;
    float inches;
public:
    class InchesEx {};
    Distance() : feet(0), inches(0.0) {}
    Distance(int ft, float in) {
        if(in >= 12.0) {
            throw InchesEx();
        }
        feet = ft;
        inches = in;
    }
    void getdist() {
        std::cout << "Enter feet: ";
        std::cin >> feet;
        std::cout << "Enter inches: ";
        std::cin >> inches;
        if(inches >= 12.0) {
            throw InchesEx();
        }
    }
    void showdist() {
        std::cout << feet << "\' - " << inches << '\"' << std::endl;
    }
};

int main() {
    try {
        Distance dist1(17, 3.5);
        Distance dist2;
        dist2.getdist();
        std::cout << "dist1 = ";
        dist1.showdist();
        std::cout << "dist2 = ";
        dist2.showdist();
    }
    catch(Distance::InchesEx) {
        std::cout << "Initialization error: inches value is too large" << std::endl;
    }

    return 0;
}