#include "DLC/Factori.h"
#ifndef BRUH_H
#define BRUH_H
// ������� � ����� ���� �� ��������� �� ������ ���
int smesya(int n, int k) {
    return (factor(n) / (factor(k) * factor(n - k)));
}

#endif // BRUH_H