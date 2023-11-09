#pragma warning (disable:4786)
#include <iostream>
#include <cstring>
#include <map>
using namespace std;

int main() {
    string name;
    int pop;
    string states[] = {"Wyoming", "Colorado", "Nevada", "Montana", "Arizona", "Idaho"};
    int pops[] = {470, 2890, 787, 2718, 944};
    map<string, int, less<string> > mapStates;
    map<string, int, less<string> >::iterator iter;
    for(int i = 0; i < 6; i++) {
        name = states[i];
        pop = pops[i];
        mapStates[name] = pop;
    }
    cout << "Enter name of state:\n";
    cin >> name;
    pop = mapStates[name];
    cout << "Population: " << pop << "000\n";
    
    for(iter = mapStates.begin(); iter != mapStates.end(); iter++) {
        cout << (*iter).first << ' ' << (*iter).second << "000\n";
    }
    return 0;
}