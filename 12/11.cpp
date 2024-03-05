#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstring>

class bMoney {
    long double sum;
public:
    bMoney() : sum(0) {}
    explicit bMoney(long double n) : sum(n) {}
    bMoney(const char[]);
    long double mstold(const char[]);
    void ldtoms(char[]);
    void getmoney();
    void putmoney();
    bMoney operator+(bMoney) const;
    bMoney operator-(bMoney) const;
    bMoney operator*(long double) const;
    long double operator/(bMoney) const;
    bMoney operator/(long double) const;
    friend bMoney operator*(long double, bMoney);
    friend long double operator/(long double, bMoney);
    friend std::istream& operator>>(std::istream&, bMoney&);
    friend std::ostream& operator<<(std::ostream&, bMoney&);
};

int main() {
    char result;
    bMoney m1, m2, m;
    long double n, res;

    do {
        std::cout << "1. ";
        std::cin >> m1;
        std::cout << "2. ";
        std::cin >> m2;
        std::cout << "Enter number: ";
        std::cin >> n;

        m = m1 + m2;
        std::cout << "1. m1 + m2 = " << m << std::endl;
        m = m1 - m2;
        std::cout << "2. m1 - m2 = " << m << std::endl;
        m = m1 * n;
        std::cout << "3. m1 * n = " << m << std::endl;
        res = m1 / m2;
        std::cout << "4. m1 / m2 = " << res << std::endl;
        m = m1 / n;
        std::cout << "5. m1 / n = " << m << std::endl; 
        m = n * m1;
        std::cout << "6. n * m1 = " << m << std::endl;
        res = n / m1;
        std::cout << "7. n / m1 = " << res << std::endl;
    }
    while(result == 'y');

    return 0;
}

bMoney::bMoney(const char s[]) {
    mstold(s);
}

long double bMoney::mstold(const char s[]) {
    char str[80];
    int j = 0;
    for(int i = 0; i < strlen(str); i++) {
        char ch = s[i];
        if((ch >= '0') && (ch <= '9')) {
            str[j++] = ch;
        }
        else if (ch == '.') {
            str[j++] = ch;
        }
    }
    str[j] = '\0';
    char *stop;
    sum = strtold(str, &stop);
    return sum;
}

void bMoney::ldtoms(char s[]) {
    wchar_t ustring[80];
    std::wstringstream woss;
	woss << std::setiosflags(std::ios::fixed) << std::setprecision(2) << sum;
	woss >> ustring;
    int i = 0, n = 0, j;
    int len = wcslen(ustring);
    char ch = ',';
    s[i++] = '$';
    if(len > 6) {
        if((len - 3) % 3 == 2) {
            s[i++] = ustring[n++];
            s[i++] = ustring[n++];
            s[i++] = ch;
        }
        else if((len - 3) % 3 == 1) {
            s[i++] = ustring[n++];
            s[i++] = ch;
        }
    }
    for(j = n; j < len - 3; j++) {
        s[i++] = ustring[j];
        if(((j - n - 1) % 3 == 0) && (j != len - 3 - 1)) {
            s[i++] = ch;
        }
    }
    s[i++] = ustring[j++];
    s[i++] = ustring[j++];
    s[i++] = ustring[j];
    s[i] = '\0';
}

void bMoney::getmoney() {
    char str[80];
    std::cout << "Enter sum: ";
    std::cin >> str;
    mstold(str);
}

void bMoney::putmoney() {
    char str[80];
    ldtoms(str);
    std::cout << str;
}

bMoney bMoney::operator+(bMoney bm) const {
    return bMoney(sum + bm.sum);
}

bMoney bMoney::operator-(bMoney bm) const {
    return bMoney(sum - bm.sum);
}

bMoney bMoney::operator*(long double n) const {
    return bMoney(n * sum);
}

long double bMoney::operator/(bMoney bm) const {
    return sum / bm.sum;
}


bMoney bMoney::operator/(long double n) const {
    return bMoney(sum / n);
} 

bMoney operator*(long double n, bMoney bm) {
    return bMoney(n * bm.sum);
}

long double operator/(long double n, bMoney bm) {
    return n / bm.sum;
}

std::istream& operator>>(std::istream& s, bMoney& bm) {
    char str[80];
    std::cout << "Enter sum: ";
    s >> str;
    bm.mstold(str);
    return s;
}

std::ostream& operator<<(std::ostream& s, bMoney& bm) {
    char str[80];
    bm.ldtoms(str);
    s << str;
    return s;
}