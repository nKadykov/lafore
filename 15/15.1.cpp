#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<float> v;
    int i = 0;
    int a = 0;
    while(1) {
        cin >> a;
        v.push_back(a);
        if(v[i] == 0) {
            break;
        }
        i++;  
    }
    sort(v.begin(), v.end(), greater<float>());
    vector<float>::iterator it;
    for(auto& x : v) {
        cout << x << ' ';
    } 
}