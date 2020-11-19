#include "DLC/Factori.h"
#ifndef BRUH_H
#define BRUH_H
// формула с сайта чтоб не впихивать ее лишний раз
int smesya(int n, int k) {
    return (factor(n) / (factor(k) * factor(n - k)));
}

#endif // BRUH_H