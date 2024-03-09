#include <iostream>
#include <string>

class Distance {
    int feet;
    float inches;
public:
    class InchesEx 
    {
    public:
        std::string origin;
        float iValue;

        InchesEx(std::string ori, float in) {
            origin = ori;
            iValue = in;
        }
    };
    Distance(): feet(0), inches(0.0) {}
    Distance(int ft, float in) {
        if(in >= 12.0) {
            throw InchesEx("Constructor with 2 argument", in);
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
            throw InchesEx("function getdist()", inches);
        }
    }
    void showdist() {
        std::cout << feet << "\' - " << inches << "\"" << std::endl;
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
        dist1.showdist();
    }
    catch(Distance::InchesEx ix) {
        std::cout << "Inizialization error in " << ix.origin << ". Inches value of " << ix.iValue << " is too large." << std::endl;
    }

    return 0;
}