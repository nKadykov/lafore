#include <iostream>
#include <vector>

class Fraction { // класс дроби
    int dividend; // числитель
    int divisor; // знаменатель
public:
    Fraction() {} // конструктор без аргументов
    Fraction(int a, int b) : dividend(a), divisor(b) {} // конструктор с двумя аргументами
    Fraction operator+(Fraction) const; // перегрузка оператора сложения
    Fraction operator-(Fraction) const; // перегрузка оператора вычитания
    Fraction operator*(Fraction) const; // перегрузка оператора умножения
    Fraction operator/(Fraction) const; // перегрузка оператора деления
    void putdata() { // метод получения данных от пользователя
        int ch = '/';
        std::cin >> dividend >> ch >> divisor;
    }
    void getdata() { // метод вывода данных на экран
        std::cout << "Result: " << dividend << '/' << divisor << '\n';
    }
    Fraction lowterms(); // метод сокращения дроби
    friend std::istream& operator>>(std::istream& s, Fraction& f); // перегрузка оператора извлечения
    friend std::ostream& operator<<(std::ostream& s, Fraction& f); // перегрузка оператора вставки
};

int main() {
    Fraction s1(2, 5), s2(1, 6), result;
    char ch = 'y';
    result = s1 + s2; // демонстрация операции сложения
    result.getdata();
    result = s1 - s2; // демонстрация операции вычитания
    result.getdata();
    result = s1 * s2; // демонстрация операции умножения
    result.getdata();
    result = s1 / s2; // демонстрация операции деления
    result.getdata();
    Fraction f;
    std::cout << "Enter fraction: ";
    std::cin >> f; // демонстрация операции извлечения
    std::cout << "Your fraction: ";
    std::cout << f; // демонстрация операции вставки
    return 0;
}

Fraction Fraction::operator+(Fraction f) const {
    int a = dividend * f.divisor + divisor * f.dividend;
    int b = divisor * f.divisor;
    return Fraction(a, b).lowterms();
}

Fraction Fraction::operator-(Fraction f) const {
    int a = dividend * f.divisor - divisor * f.dividend;
    int b = divisor * f.divisor;
    return Fraction(a, b).lowterms();
}

Fraction Fraction::operator*(Fraction f) const {
    int a = dividend * f.dividend;
    int b = divisor * f.divisor;
    return Fraction(a, b).lowterms();
}

Fraction Fraction::operator/(Fraction f) const {
    int a = dividend * f.divisor;
    int b = divisor * f.dividend;
    return Fraction(a, b).lowterms();
}

Fraction Fraction::lowterms() {
    long tnum, tden, temp, gcd;
    tnum = labs(dividend);
    tden = labs(divisor);
    if(tden == 0) {
        std::cout << "Incorrect divisor!";
    }
    else if(tnum == 0) {
        dividend = 0;
        divisor = 1;
        return Fraction(dividend, divisor);
    }
    while(tnum != 0) {
        if(tnum < tden) {
            temp = tnum;
            tnum = tden;
            tden = temp;
        }
        tnum = tnum - tden;
    }
    gcd = tden;
    dividend = dividend / gcd;
    divisor = divisor / gcd;
    return Fraction(dividend, divisor);
}

std::istream& operator>>(std::istream& s, Fraction& f) {
    char ch = '/';
    s >> f.dividend >> ch >> f.divisor;
    return s;
}

std::ostream& operator<<(std::ostream& s, Fraction& f) {
    s << f.dividend << '/' << f.divisor;
    return s;
}