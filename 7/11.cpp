#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

class Money
{
private:
	long double sum;
public:
	long double mstold(wchar_t []);
	void ldtoms(wchar_t []);
};

int main()
{
	Money ms;
	wchar_t money[80];
	long double res;
	wchar_t ans;
	do {
		wcout << "Enter sum (example: '$1,234,567.99'):\n";
		wcin >> money;
		res = ms.mstold(money);
		wcout << "Number with type long double: " << setiosflags(ios::fixed)
			<< setprecision(2) << res << endl;
		ms.ldtoms(money);
		wcout << "String: " << money << endl;
		wcout << "Continue (y/n)? "; 
		wcin >> ans;
	} while (ans != 'n');

	return 0;
}

long double Money::mstold(wchar_t str[])
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

void Money::ldtoms(wchar_t str[])
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