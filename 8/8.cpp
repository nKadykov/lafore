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
    bMoney operator+(bMoney);
    bMoney operator-(bMoney);
    bMoney operator*(long double);
    long double operator/(bMoney);
    bMoney operator/(long double);
};

int main()
{
    wchar_t result;
    bMoney a, b, sum, dif, pro, quo2;
    long double quo1;
    long double n;
    int i = 0;
    do {
        a.getmoney();
        b.getmoney();
        cout << "Enter number: ";
        cin >> n;
        sum = a + b;
        dif = a - b;
        pro = a * n;
        quo1 = a / b;
        quo2 = a / n;
        sum.putmoney();
        dif.putmoney();
        pro.putmoney();
        cout << "Quotient 1: " << quo1 << '\n';
        quo2.putmoney();
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
		else if (ch == L'.')
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

bMoney bMoney::operator+(bMoney bm) {
    long double result = sum + bm.sum;
    return bMoney(result);
}

bMoney bMoney::operator-(bMoney bm) {
    long double result = sum - bm.sum;
    return bMoney(result);
}

bMoney bMoney::operator*(long double m) {
    long double result = sum * m;
    return bMoney(result);
}

long double bMoney::operator/(bMoney bm) {
    long double result = sum / bm.sum;
    return result;
}

bMoney bMoney::operator/(long double n) {
    long double result = sum / n;
    return bMoney(result);
}