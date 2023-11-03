#include <iostream>
#include <vector>
using namespace std;

int main() {
    int arr[] = {100, 110, 120, 130};
    vector<int> v(arr, arr + 4);

    cout << "Before insert\n";
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    }
    v.insert(v.begin() + 2, 115);

    cout << "\nAfter insert:\n";

    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    }

    v.erase(v.begin() + 2);

    cout << "\nAfter erase:\n";

    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    }
    return 0;
}