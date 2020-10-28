#include <math.h>;
#include <stdio.h>;
using namespace std;
int number, i, mnojitel;
double stepen;
int main() {
	setlocale(LC_CTYPE, "rus");
	cout << "Введите число ";
	cin >> number;
	cout << "Введите степень ";
	cin >> stepen;
	if (stepen == 0) {
		cout << 1;
	}
	else if (stepen == 0.5) { number = sqrt(number); }
	else {
		mnojitel = number;
		for (i = 2; i <= stepen; i++) {
			number = number * mnojitel;
		}
		cout << number;
	}
}