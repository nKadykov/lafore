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
    bMoney(wchar_t s[]) {
        mstold(s);
    }
    void madd(bMoney m1, bMoney m2);
    void getmoney();
    void putmoney();
	long double mstold(wchar_t []);
	void ldtoms(wchar_t []);
};

int main()
{
	bMoney ms[10];
    wchar_t result;
    int i = 0;
    do {
        ms[i++].getmoney();
        wcout << "Continue? (y/n): ";
        wcin >> result;
    }
    while(result != 'n');
    bMoney all;
    for(int j = 0; j < i; j++) {
        all.madd(all, ms[j]);
    }
    wcout << "Sum: ";
    all.putmoney();

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
    wcout << money;
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