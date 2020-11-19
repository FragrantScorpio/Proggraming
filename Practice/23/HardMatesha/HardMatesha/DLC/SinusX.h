#include <cmath>
#include "Factori.h"
//��� ��������� ���� ��� ���������� ������ � �� ��� �� ������� ��� � ���������
#ifndef BRABUS_H
#define BRABUS_H
double sinusx(double number, int perem) {
    double summa = number;
    for (int i = 1; i <= perem; i++) {
        summa += ((pow(number, 2 * i + 1)) / factor(2 * i + 1))* pow(-1, i);
    }
    return summa;
}

#endif // BRABUS_H