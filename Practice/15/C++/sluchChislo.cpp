#include<iostream>;
#include <ctime>;
using namespace std;
int randomN,userN,fails,win,game;
int main() {
	setlocale(LC_CTYPE, "rus");
	srand(time(0));
	randomN = 1 + rand() % 100;
	cout << "Попробуйте угадать мое загаданное число, у вас 5 попыток\n";
	fails = 0;
	game = 1;
	win = 1;
	while (game == 1) {
		while (fails < 5) {
			cin >> userN;
			if (userN > 100 or userN < 0) {
				cout << "Введите число в верном диапазоне\n";
			}
			else if (userN > randomN) {
				cout << "Загаданое число меньше\n";
				fails++;
			}
			else if (userN < randomN) {
				cout << "Загаданое число больше\n";
				fails++;
			}
			else if (userN == randomN) {
				win++; cout << "Поздравляю, вы угадали число!\n";
				fails = 5;
			}
		}
		if (win == 0) {
			if (fails == 5) {
				cout << "Вы проиграли\n";
				cout << "Хотите снова?\n1.Да\n2.Нет\n";
				cin >> game;
				if (game == 1) { fails = 0; 
				cout << "Попробуйте угадать мое загаданное число, у вас 5 попыток\n";
				}
				else break;
			}
		}
		if (win == 1) {
			cout << "Хотите снова?\n1.Да\n2.Нет\n";
			cin >> game;
			if (game == 1) { fails = 0;
			cout << "Попробуйте угадать мое загаданное число, у вас 5 попыток\n";
			}
			else break;
		}

	}
}