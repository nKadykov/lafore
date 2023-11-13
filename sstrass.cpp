#include <iostream>
#include <cstring>
using namespace std;

int main() {
    string s1("Fish");
    string s2 = "Meet";
    string s3;
    s3 = s1;
    cout << "s3 >> " << s3 << '\n';
    s3 = "Not " + s1 + " not ";
    s3 += s2;
    cout << "s3 >> " << s3 << '\n';
    s1.swap(s2);
    cout << s1 << " not " << s2 << '\n';
    return 0;
}