#pragma once
// ���� ��� ���������� ���������� ���� �� ���������� ��� 300 ��� ���
int factor(int F)
{
    if (F < 0) return 0;
    if (F == 0) return 1;
    else return F * factor(F - 1);
}