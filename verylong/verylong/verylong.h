#pragma once
#include <iostream>
#include <cstring>
#include <cstdlib>

const int SZ = 1000; // максимальное число разрядов

class Verylong {
    char vlstr[SZ]; // число как строка
    int vlen; // длина строки Verylong
    Verylong multdigit(const int) const; // умножение сверхбольшого числа на цифру
    Verylong mult10(const Verylong) const; // умножение сверхбольшого числа на цифру
public:
    Verylong() : vlen(0) { // конструктор без аргументов
        vlstr[0] = '\0';
    }
    Verylong(const char s[SZ]) { // конструктор с одним аргументом для строки
        strcpy_s(vlstr, s);
        vlen = strlen(s);
    }
    Verylong(const unsigned long n) { // конструктор с одним аргументов для long int
        _ltoa_s(n, vlstr, 10); // перевод в строку
        _strrev(vlstr); // переворачивание строки
        vlen = strlen(vlstr); // поиск длины
    }
    void putvl() const; // вывод числа
    void getvl(); // получение числа от пользователя
    Verylong operator+(const Verylong); // сложение чисел
    Verylong operator*(const Verylong); // умножение чисел
};