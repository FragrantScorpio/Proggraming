#include<iostream>;
#include<math.h>;
int number, ostatok;
int main() {
	cout << "������� �����";
	cin >> number;
	ostatok = number % 1;
	if (ostatok != 0) {
		cout << "�������";
	}
	else { 
	cout << "���������"; }
}