// HardMatesha.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cmath>
#include "DLC/Factori.h"
#include "DLC/Pereperd.h"
#include "DLC/SinusX.h"
using namespace std;


int main()
{
    // первая формула с факториалом
    int F = 10;
    cout << "n" << "\t" << "n!" << endl;
    for (int i = 1; i <= F; i++) {
        cout << i << "\t" << factor(i) << endl;
    }
    cout << endl;
    // вторая формула с сигмой
    double x = 0;
    int k = 5;
    cout << "x" << "\t" << "sin(x)" << endl;
    for (; x <= M_PI / 4 + M_PI / 180; ) {
        cout << setprecision(4) << x << "\t" << setprecision(4) << sinusx(x, k) << endl;
        x += M_PI / 180;
    }
    cout << "\n";
    // третья формула С
    int n = 10;
    cout << "k" << "\t" << "C(k, 10)" << endl;
    for (int k = 1; k <= 10; k++) {
        cout << k << "\t" << smesya(n, k) << endl;
    }
}