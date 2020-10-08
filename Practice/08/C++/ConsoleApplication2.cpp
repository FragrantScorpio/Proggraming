#include <iostream>;
#include <math.h>;
using namespace std;
char b;
int a,c,answer;
int main() {
	setlocale(LC_CTYPE, "rus");
	cout << "Добро пожаловать в мой калькулятор\n";
	cin >> a >> b >> c;
	if (b == '*')
	{
		answer = a * c;
		cout << answer;
	}
	else {
		if (b == '+') {
			answer = a + c;
			cout << answer;
		}
		else {
			if (b == '-') {
				answer = a - c;
				cout << answer;
			}
			else {
				if (b == '/') {
					if (c != 0) {
						answer = a / c;
						cout << answer;
					}

					else cout << "Нельзя делить на ноль лол";
				}
				else cout << "Неправильный ввод(введите число, знак, число)";
			}
			}
		}
	


}

