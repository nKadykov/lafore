#include <iostream>
using namespace std;

enum etype {laborer, secretary, manager, accountant, executive, researcher};

int main() {
    char first;
    cout << "Enter first letter of position\n(laborer, secretary, manager, accountant, executive, researcher); ";
    cin >> first;
    etype pos;
    switch(first) {
        case 'l':
            pos = laborer;
            break;
        case 's':
            pos = secretary;
            break;
        case 'm':
            pos = manager;
            break;
        case 'a':
            pos = accountant;
            break;
        case 'e':
            pos = executive;
            break;
        case 'r':
            pos = researcher;
            break;
    }
    cout << "Position: ";
    switch(pos) {
        case 0:
            cout << "laborer";
            break;
        case 1:
            cout << "secretary";
            break;
        case 2:
            cout << "manager";
            break;
        case 3:
            cout << "accountant";
            break;
        case 4:
            cout << "executive";
            break;
        case 5:
            cout << "researcher";
            break;
    }

    return 0;
}