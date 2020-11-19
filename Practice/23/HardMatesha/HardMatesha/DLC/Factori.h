#pragma once
// файл для вычисления факториала чтоб не записывать его 300 тыщ раз
int factor(int F)
{
    if (F < 0) return 0;
    if (F == 0) return 1;
    else return F * factor(F - 1);
}