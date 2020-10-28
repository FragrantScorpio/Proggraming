#include<iostream>;
#include<math.h>;
int number, ostatok;
int main() {
	cout << "Введите число";
	cin >> number;
	ostatok = number % 1;
	if (ostatok != 0) {
		cout << "Простое";
	}
	else { 
	cout << "Составное"; }
}