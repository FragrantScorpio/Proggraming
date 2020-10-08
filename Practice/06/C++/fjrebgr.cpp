#include <iostream>;
#include<cstdio>;
#include<math.h>;
using namespace std;
int a, b, c,D, answer,x1,x2;
int main()
{
	setlocale(LC_CTYPE, "rus");
	cout << "Введите 3 члена для уравнения(a,b,c)";
	cin >> a >> b >> c;
	if (a != 0) {// Проверка не равняется ли 0 a или b
		if (b != 0) {// если оба не равняются 0 тогда проводиться обычный дискриминант
			D = (b * b) - (4 * a * c); // Вычисляем дискриминант
			x1 = (-b + sqrt(D)) / (2 * a);// И два корня
			x2 = (-b - sqrt(D)) / (2 * a);
			cout << x1 << " " << x2;
		}
		else {// если b=0 тогда выполняется a*x^2=-c и дальше обычное уравнение
			answer = c - (c * 2); answer = answer / a; x1 = sqrt(answer); cout << x1;
		}
	}
	else {//если a=0 а b не равно 0, тогда выполняется b*x=-с и так же обычное уравнение
		if (b != 0) { answer = c - (c * 2); x1 = answer / b; cout << x1; }

		else { cout << "Уравнение не имеет корней;" }//если оба числа равны 0 то нет решений
	};
	







}