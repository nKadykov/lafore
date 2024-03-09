#include <iostream>
#include <string>
#include <cstdlib>

int isFeet(std::string);

class Distance {
    int feet;
    float inches;
public:
    class ExDist {
    public:
        int num;
        ExDist(int n) : num(n) {}
    };
    Distance() : feet(0), inches(0.0) {}
    Distance(int ft, float in) {
        if(ft < -999 || ft > 999) {
            throw ExDist(7);
        }
        feet = ft;
        if(in >= 12.0 || in < 0.0) {
            throw ExDist(8);
        }
        inches = in;
    }
    void showdist() {
        std::cout << feet << "\' - " << inches << '\"' << std::endl;
    }
    void getdist();
};

void Distance::getdist() {
    std::string instr;
    while(true) {
        std::cout << "Enter feet: ";
        std::cin.unsetf(std::ios::skipws);

        std::cin >> instr;
        if(isFeet(instr)) {
            std::cin.ignore(10, '\n');
            feet = atoi(instr.c_str());
            break;
        }
        std::cin.ignore(10, '\n');
        throw ExDist(1);
    }
    while(true) {
        std::cout << "Enter inches: ";
        std::cin.unsetf(std::ios::skipws);
        std::cin >> inches;
        if(inches >= 12 || inches < 0) {
            throw ExDist(2);
            std::cin.clear(std::ios::failbit);
        }
        if(std::cin.good()) {
            std::cin.ignore(10, '\n');
            break;
        }
        std::cin.clear();
        std::cin.ignore(10, '\n');
        throw ExDist(3);
    }
}

int isFeet(std::string str) {
    int slen = str.size();
    if(slen == 0 || slen > 5) {
        throw Distance::ExDist(4);
    }
    for(int i = 0; i < slen; i++) {
        if((str[i] < '0' || str[i] > '9') && str[i] != '-') {
            throw Distance::ExDist(5);
        }
    }
    double n = atof(str.c_str());
    if(n < -999 || n > 999) {
        throw Distance::ExDist(6);
    }
    return 1;
}

int main() {
    try {
        Distance dist1(10, 1);
        Distance dist2(1000, 1);
        Distance dist3(10, 13);
    }
    catch(Distance::ExDist err) {
        switch(err.num) {
            case 7:
                std::cout << "Feet between -999..999" << std::endl;
                break;
            case 8:
                std::cout << "Inches greater or equal 0 and lesser 12" << std::endl;
        }
    }
    Distance d;
    char result;
    do {
        try {
            d.getdist();
        }
        catch(Distance::ExDist err) {
            switch(err.num) {
                case 1:
                    std::cout << "Feet is integer lesser 1000" << std::endl;
                    break;
                case 2:
                    std::cout << "Inches between 0 and 11.99" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(10, '\n');
                    break;
                case 3:
                    std::cout << "Inches incorrect" << std::endl;
                    break;
                case 4:
                    std::cout << "Too much or nothing" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(10, '\n');
                    break;
                case 5:
                    std::cout << "Feet only digits and minus" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(10, '\n');
                    break;
                case 6:
                    std::cout << "Feet between -999..999" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(10, '\n');
                    break;
            }
            std::cout << "Again" << std::endl;
            result = 'y';
            continue;
        }
        std::cout << "Distance = ";
        d.showdist();
        std::cout << "Continue? (y/n): ";
        std::cin >> result;
        std::cin.ignore(10, '\n');
    }
    while(result != 'n');

    return 0;
}