﻿#include <iostream>;
using namespace std;

double x, y, answer1, answer2, answer4, answer3;
int main() {
	setlocale(LC_CTYPE, "rus");
	cout << "введите 2 дробных числа\n";
	cin >> x >> y;
	answer1 = x + y;
	cout << "Сложение \n" << answer1 << "\n";
	answer2 = x - y;
	cout << "Разность\n" << answer2 << "\n";
	answer3 = x / y;
	cout << "Деление\n" << answer3 << "\n";
	answer4 = x * y;
	cout << "Умножение\n" << answer4 << "\n";




}