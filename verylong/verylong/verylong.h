#pragma once
#include <iostream>
#include <cstring>
#include <cstdlib>

const int SZ = 1000; // ������������ ����� ��������

class Verylong {
    char vlstr[SZ]; // ����� ��� ������
    int vlen; // ����� ������ Verylong
    Verylong multdigit(const int) const; // ��������� ������������� ����� �� �����
    Verylong mult10(const Verylong) const; // ��������� ������������� ����� �� �����
public:
    Verylong() : vlen(0) { // ����������� ��� ����������
        vlstr[0] = '\0';
    }
    Verylong(const char s[SZ]) { // ����������� � ����� ���������� ��� ������
        strcpy_s(vlstr, s);
        vlen = strlen(s);
    }
    Verylong(const unsigned long n) { // ����������� � ����� ���������� ��� long int
        _ltoa_s(n, vlstr, 10); // ������� � ������
        _strrev(vlstr); // ��������������� ������
        vlen = strlen(vlstr); // ����� �����
    }
    void putvl() const; // ����� �����
    void getvl(); // ��������� ����� �� ������������
    Verylong operator+(const Verylong); // �������� �����
    Verylong operator*(const Verylong); // ��������� �����
};