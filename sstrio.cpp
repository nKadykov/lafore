#include <iostream>
#include <cstring>
using namespace std;

int main() {
    string full_name, nickname, address;
    string greeting("Hello, ");

    cout << "Enter your name:";
    getline(cin, full_name);
    cout << "Your name: " << full_name << '\n';

    cout << "Your nickname: ";
    cin >> nickname;

    greeting += nickname;
    cout << greeting << '\n';
    cout << "Enter your address:\n";
    getline(cin, address, '$');
    cout << "Your address: " << address << '\n';
    return 0;
}