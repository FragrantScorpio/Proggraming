#include <iostream>;
using namespace std;
int x, y, answer1, answer2, answer4;
double answer3;
int main() {
	setlocale(LC_CTYPE, "rus");
	cout << "введите 2 целых числа\n";
	cin >> x >> y;
		answer1 = x + y;
		cout << "Сложение 2х целых \n" << answer1 << "\n";
		answer2 = x - y;
		cout << "Разность 2х целых\n" << answer2 << "\n";
		answer3 = x / y;
		cout << "Деление 2х целых\n" << answer3 << "\n";
		answer4 = x * y;
		cout << "Умножение 2х целых\n" << answer4 << "\n";
    
		


}