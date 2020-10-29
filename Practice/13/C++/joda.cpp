#include<iostream>;
#include<math.h>;
int number, ostatok;
int main() {
	setlocale(LC_CTYPE,"rus");
	cout << "Ââåäèòå ÷èñëî";
	cin >> number;
	ostatok = number % 1;
	if (ostatok != 0) {
		cout << "Ïðîñòîå";
	}
	else { 
	cout << "Ñîñòàâíîå"; }
}
