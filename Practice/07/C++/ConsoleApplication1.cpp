#include<math.h>;
#include<iostream>;
#include<cstdio>;
using namespace std;
int a, b, c, S, a1, b1, c1, A, B, C, way, hp;
int main() {
	setlocale(LC_CTYPE, "rus");
	cout << "Каким способом будете решать?\n"
		<< "1:длинны сторон\n"
		<< "2:координаты краев\n"
		<< "(Введите номер способа) \n";
	cin >> way;
	if (way == 1) {
		cout << "Введите длинны 3х сторон\n";
		cin >> a >> b >> c;
		hp = (c + a + b) / 2;// Находим полупериметр из трех значений
		S = sqrt(hp * (hp - a) * (hp - b) * (hp - c));//Дальше площадь через него
		cout << S;
	}
	else {
		if (way == 2) {
			if ((a < b + c) & (b < a + c) & (c < a + b)) {
				cout << "Введите координаты трех точек по X,Y\n";//тут посложнее
				cin >> a >> a1 >> b >> b1 >> c >> c1;
				A = sqrt((b - a) * (b - a) + (b1 - a1) * (b1 - a1));// нахожу длинну каждого отрезка по пифагору, отнимаю конец отрезка от начала(в двух координатах)
				B = sqrt((c - b) * (c - b) + (c1 - b1) * (c1 - b1));// возвожу в квадрат и складываю , потом под корень, и получаю длинну отрезка
				C = sqrt((a - c) * (a - c) + (a1 - c1) * (a1 - c1));
				hp = (A + B + C) / 2;//после чего так же через полупериметр нахожу площадь
				S = sqrt(hp * (hp - A) * (hp - B) * (hp - C));
				cout << S;
			}
			else {
				cout << "Такого треугольника не существует";
			}
		}
		else { cout << "Такого способа нету"; }
	}





}




