#include <iostream>
#include <cstring>
using namespace std;

int main() {
    string s1 = "Qwe Qwe rty asd fgh fgh";
    int n;
    n = s1.find("Qwe");
    cout << "Qwe found: " << n << '\n';

    n = s1.find_first_of("rty");
    cout << "First rty: " << n << '\n';

    n = s1.find_first_not_of("Qzxcv");
    cout << "First not of: " << n << '\n';

    n = s1.find_last_of("fgh");
    cout << "Last fgh: " << n << '\n';

    n = s1.find_last_not_of("Qwerh");
    cout << "Last not of: " << n << '\n';

    return 0;
}