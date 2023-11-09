#pragma warning(disable:4786)
#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
    string names[] = {"Juanita", "Robert", "Mary", "Amanda", "Marie"};
    set<string, less<string>> nameSet(names, names + 5);
    set<string, less<string>>::iterator iter;

    nameSet.insert("Yvette");
    nameSet.insert("Larry");
    nameSet.insert("Robert");
    nameSet.insert("Barry");
    nameSet.erase("Mary");

    cout << "Size: " << nameSet.size() << '\n';
    iter = nameSet.begin();
    while(iter != nameSet.end()) {
        cout << *iter++ << '\n';
    }

    string searchName;

    cout << "Enter name: ";
    cin >> searchName;
    
    iter = nameSet.find(searchName);
    if(iter == nameSet.end()) {
        cout << "Name " << searchName << " is abscent in set\n";
    }
    else {
        cout << "Name " << *iter << " is in set\n";
    }
    return 0;
}