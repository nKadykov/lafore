#include "verylong.h"

void Verylong::putvl() const { // вывод сверхбольшого числа на экран
    char temp[SZ];
    strcpy_s(temp, vlstr); // создание копии
    std::cout << _strrev(temp); // переворот копии и вывод
}

void Verylong::getvl() { // получение сверхбольшого числа от пользовател€
    std::cin >> vlstr; //  получение строки от пользовател€
    vlen = strlen(vlstr); // нахождение длины строки
    _strrev(vlstr); // переворот строки
}

Verylong Verylong::operator+(const Verylong v) { // сложение
    char temp[SZ];
    int j;

    int maxlen = (vlen > v.vlen) ? vlen : v.vlen; // поиск самого длинного числа
    int carry = 0; // установка 1, если сумма больше или равна 10
    for (j = 0; j < maxlen; j++) {
        int d1 = (j > vlen - 1) ? 0 : vlstr[j] - '0'; // получение разр€да
        int d2 = (j > v.vlen - 1) ? 0 : v.vlstr[j] - '0';
        int digitsum = d1 + d2 + carry; // сложение разр€дов
        if (digitsum >= 10) {
            digitsum -= 10;
            carry = 1;
        }
        else {
            carry = 0;
        }
        temp[j] = digitsum + '0'; // вставка символа в строку
    }
    if (carry == 1) { // если перенос в конце
        temp[j++] = '1'; // последн€€ цифра равна 1
    }
    temp[j] = '\0'; // вставка ограничител€ строки
    return Verylong(temp); // вернуть объект Verylong
}

Verylong Verylong::operator*(const Verylong v) { // умножение сверхбольших чисел
    Verylong pprod; // произведение разр€да
    Verylong tempsum; // сумма
    for (int j = 0; j < v.vlen; j++) { // дл€ каждого разр€да
        int digit = v.vlstr[j] - '0'; // получить разр€д
        pprod = multdigit(digit);
        for (int k = 0; k < j; k++) {
            pprod = mult10(pprod); // умножение на степень 10
        }
        tempsum = tempsum + pprod; // прибавление к текущей сумме
    }
    return tempsum; // возврат текущей суммы
}

Verylong Verylong::mult10(const Verylong v) const { // умножение аргумента на 10
    char temp[SZ];
    for (int j = v.vlen - 1; j >= 0; j--) { // сдвиг на один разр€д
        temp[j + 1] = v.vlstr[j];
    }
    temp[0] = '0'; // обнуление самого младшего разр€да
    temp[v.vlen + 1] = '\0'; // установка ограничител€ строки
    return Verylong(temp); // возврат результата
}

Verylong Verylong::multdigit(const int d2) const { // умножение числа на цифру
    char temp[SZ];
    int j, carry = 0;
    for (j = 0; j < vlen; j++) {
        int d1 = vlstr[j] - '0';
        int digitprod = d1 * d2;
        digitprod += carry;
        if (digitprod >= 10) {
            carry = digitprod / 10;
            digitprod -= carry * 10;
        }
        else {
            carry = 0;
        }
        temp[j] = digitprod + '0';
    }
    if (carry != 0) {
        temp[j++] = carry + '0';
    }
    temp[j] = '\0';
    return Verylong(temp); // возврат сверхбольшого числа
}