#include "verylong.h"

void Verylong::putvl() const {
    char temp[SZ];
    strcpy_s(temp, vlstr);
    std::cout << _strrev(temp);
}

void Verylong::getvl() {
    std::cin >> vlstr;
    vlen = strlen(vlstr);
    _strrev(vlstr);
}

Verylong Verylong::operator+(const Verylong v) {
    char temp[SZ];
    int j;

    int maxlen = (vlen > v.vlen) ? vlen : v.vlen;
    int carry = 0;
    for (j = 0; j < maxlen; j++) {
        int d1 = (j > vlen - 1) ? 0 : vlstr[j] - '0';
        int d2 = (j > v.vlen - 1) ? 0 : v.vlstr[j] - '0';
        int digitsum = d1 + d2 + carry;
        if (digitsum >= 10) {
            digitsum -= 10;
            carry = 1;
        }
        else {
            carry = 0;
        }
        temp[j] = digitsum + '0';
    }
    if (carry == 1) {
        temp[j++] = '1';
    }
    temp[j] = '\0';
    return Verylong(temp);
}

Verylong Verylong::operator*(const Verylong v) {
    Verylong pprod;
    Verylong tempsum;
    for (int j = 0; j < v.vlen; j++) {
        int digit = v.vlstr[j] - '0';
        pprod = multdigit(digit);
        for (int k = 0; k < j; k++) {
            pprod = mult10(pprod);
        }
        tempsum = tempsum + pprod;
    }
    return tempsum;
}

Verylong Verylong::mult10(const Verylong v) const {
    char temp[SZ];
    for (int j = v.vlen - 1; j >= 0; j--) {
        temp[j + 1] = v.vlstr[j];
    }
    temp[0] = '0';
    temp[v.vlen + 1] = '\0';
    return Verylong(temp);
}

Verylong Verylong::multdigit(const int d2) const {
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
    return Verylong(temp);
}