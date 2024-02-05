#include <iostream>
using namespace std;

struct phone {
    int cityCode;
    int stationNumber;
    int subNumber;
};

int main() {
    phone number1 {212, 767, 8900};
    phone number2;

    cout << "Enter city code, number of station and number of sub: ";
    cin >> number2.cityCode >> number2.stationNumber >> number2.subNumber;

    cout << "My number: (" << number1.cityCode << ") " << number1.stationNumber << "-" << number1.subNumber << '\n';
    cout << "Your number: (" << number2.cityCode << ") " << number2.stationNumber << "-" << number2.subNumber;
    return 0;
}