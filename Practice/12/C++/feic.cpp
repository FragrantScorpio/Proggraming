#include<iostream>;
using namespace std;
int factor, number, i, x, y;
int main() {
	setlocale(LC_CTYPE, "rus");
	factor = 1;
	cout << "Введите число для факториала";
	cin >> number;
	if (number < 0) {
		cout << "Число должно быть положительным";
		return(0);
	}
	for (i = 0; i < number; i++)
	{
		x = x + 1;
		factor = factor * x;
	}
	cout << factor;
}
