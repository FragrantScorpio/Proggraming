﻿#include <iostream>; // я только щас понял что надо комментарии писать, можно в предыдущих заданиях без них? Только в таких вот по серьезнее
using namespace std;
int t;// для времени лучше целое чтоб убрать лишнюю погрешность
double x0, v0, x(t), a, answer;
int main() {
	setlocale(LC_CTYPE, "RUS");
	cout << "Введите данные для вычисления(x0,v0,t)";
	cin >> x0 >> v0 >> t;
	a = 9.8;
	answer = x0 + (v0 * t) - ((a * (t*t))/2);
	cout << answer;



	

}
