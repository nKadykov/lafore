#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
    set<string, less<string>> organic;
    set<string, less<string>>::iterator iter;
    organic.insert("Cirine");
    organic.insert("Xanthine");
    organic.insert("Curarine");
    organic.insert("Melamine");
    organic.insert("Cyanmide");
    organic.insert("Phenol");
    organic.insert("Aphrodine");
    organic.insert("Imidzole");
    organic.insert("Cinchonine");
    organic.insert("Palmitamide");
    organic.insert("Cyanmide");

    iter = organic.begin();
    while(iter != organic.end()) {
        cout << *iter++ << '\n';
    }

    string lower, upper;
    cout << "Enter size: ";
    cin >> lower >> upper;
    iter = organic.lower_bound(lower);
    while(iter != organic.upper_bound(upper)) {
        cout << *iter++ << '\n';
    }
    return 0;
}