#include<iostream>;
using namespace std;
int number, stepen, perestepen;
double deperem, denumber;
int main() {
	setlocale(LC_CTYPE, "rus");
	deperem = 0;
	denumber = 0;
	perestepen = 0;
	cout << "Введите число\n";
	cin >> number;
	for (stepen = 1; stepen <= number ; stepen++) {
		deperem = pow(2,denumber);
		if ((denumber<=number) && (deperem<=number)) {
			perestepen++;
		}
		else {
			 number =  denumber;
		}
		denumber++;
	}
	cout << perestepen;
}