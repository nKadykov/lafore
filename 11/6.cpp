#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

class bMoney
{
private:
	long double sum;
public:
    bMoney() : sum(0.0) {}
    explicit bMoney(long double s) : sum(s) {}
    bMoney(wchar_t s[]) {
        mstold(s);
    }
    void madd(bMoney m1, bMoney m2);
    void getmoney();
    void putmoney();
	long double mstold(wchar_t []);
	void ldtoms(wchar_t []);
    bMoney operator+(bMoney) const;
    bMoney operator-(bMoney) const ;
    bMoney operator*(long double) const;
    bMoney operator/(long double) const;
    long double operator/(bMoney) const;
    friend bMoney operator*(long double, bMoney);
    friend long double operator/(long double, bMoney);
};

int main()
{
    wchar_t result;
    bMoney a, b, sum, dif, pro1, pro2, quo2;
    long double quo1, n, quo3;
    int i = 0;
    do {
        a.getmoney();
        b.getmoney();
        cout << "Enter number: ";
        cin >> n;
        sum = a + b;
        dif = a - b;
        pro1 = a * n;
        pro2 = n * a;
        quo1 = a / b;
        quo2 = a / n;
        quo3 = n / a;
        sum.putmoney();
        dif.putmoney();
        pro1.putmoney();
        pro2.putmoney();
        cout << quo1 << '\n';
        quo2.putmoney();
        cout << quo3 << '\n';
        wcout << "Continue? (y/n): ";
        wcin >> result;
    }
    while(result != 'n');

	return 0;
}

void bMoney::madd(bMoney m1, bMoney m2) {
    sum = m1.sum + m2.sum;
}

void bMoney::getmoney() {
    wchar_t money[80];
    wcout << "Enter sum (example: '$1,234,567.99'): ";
    wcin >> money;
    mstold(money);
}

void bMoney::putmoney() {
    wchar_t money[80];
    ldtoms(money);
    wcout << money << '\n';
}

long double bMoney::mstold(wchar_t str[])
{
	wchar_t temp[80];
	int j = 0;
	for (int i = 0; i < wcslen(str); i++)
	{
		wchar_t ch = str[i];
		if ((ch >= '0') && (ch <= '9'))
			temp[j++] = ch;
		else if (ch == '.')
			temp[j++] = ch;
	}
	temp[j] = '\0';
	wchar_t *stop;
	sum = wcstold(temp, &stop);
	return sum;
}

void bMoney::ldtoms(wchar_t str[])
{
	wchar_t ustring[80];
	wstringstream woss;
	woss << setiosflags(ios::fixed) << setprecision(2) << sum;
	woss >> ustring;
	int i = 0, n = 0, j;
	int len = wcslen(ustring);
	wchar_t point = ',';
	str[i++] = '$';
    if(len > 6) {
        if ((len - 3) % 3 == 2)
        {
            str[i++] = ustring[n++];
            str[i++] = ustring[n++];
            str[i++] = point;
        }
        else if ((len - 3) % 3 == 1)
        {
            str[i++] = ustring[n++];
            str[i++] = point;
        }
    }

	for (j = n; j < len - 3; j++)
	{
		str[i++] = ustring[j];
		if (((j - n + 1) % 3 == 0) && (j != len - 3 - 1))
			str[i++] = point;
	}

	str[i++] = ustring[j++];
	str[i++] = ustring[j++];
	str[i++] = ustring[j];
	str[i]   = '\0';
}

bMoney bMoney::operator+(bMoney bm) const {
    long double result = sum + bm.sum;
    return bMoney(result);
}

bMoney bMoney::operator-(bMoney bm) const {
    long double result = sum - bm.sum;
    return bMoney(result);
}

bMoney bMoney::operator*(long double m) const {
    long double result = sum * m;
    return bMoney(result);
}

bMoney bMoney::operator/(long double n) const {
    long double result = sum / n;
    return bMoney(result);
}

long double bMoney::operator/(bMoney bm) const {
    return sum / bm.sum;
}

bMoney operator*(long double ld, bMoney bm) {
    return bMoney(ld * bm.sum);
}


long double operator/(long double ld, bMoney bm) {
    return ld / bm.sum;
}