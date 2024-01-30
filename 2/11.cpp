#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << setiosflags(ios::left) << setw(15) << "First name" << setw(15) << "Name" << setw(15) << "Adress" << setw(15) << "City"<< '\n';
    for(int i = 0; i < 60; i++) {
        cout << '-';
    }
    cout << '\n';
    cout << setiosflags(ios::left) << setw(15) << "Petrov" << setw(15) << "Vasiliy" << setw(15) << "Klenovaya" << setw(15) << "Saint-Petersvourg"<< '\n';
    cout << setiosflags(ios::left) << setw(15) << "Ivanov" << setw(15) << "Sergey" << setw(15) << "Osinovaya" << setw(15) << "Nahodka"<< '\n';
    cout << setiosflags(ios::left) << setw(15) << "Sidorov" << setw(15) << "Ivan" << setw(15) << "Beresovaya" << setw(15) << "Kaliningrad"<< '\n';
    return 0;
}