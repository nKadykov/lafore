#include <iostream>
using namespace std;

int main() {
    float arr[100];
    char ch;
    int num = 0;
    do {
        cout << "Enter number: ";
        cin >> *(arr + num++);
        cout << "Continue? (y/n): ";
        cin >> ch;
    }
    while(ch != 'n');
    float total = 0.0;
    for(int i = 0; i < num; i++) {
        total += *(arr + i);
    }
    float average = total / num;
    cout << "Average is " << average << endl;
    return 0;
}