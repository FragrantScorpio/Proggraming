#include <iostream>;
using namespace std;
int a, b;
int main() {
	setlocale(LC_CTYPE, "rus");
	cout << "введите 2 числа для обмена";
	cin >> a >> b;
	a = b + a;
	b = a - b;
	a = a - b;
	cout << a << " " << b;
	

}