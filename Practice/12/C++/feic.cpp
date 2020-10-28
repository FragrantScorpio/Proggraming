#include<iostream>;
using namespace std;
int factor, number, i,x,y;
int main() {
	factor = 1;
	cout << "Введите число для факториала";
	cin >> number;
	for(i=0;  i<number; i++)
	{
		x = x + 1;
		factor = factor * x;
	}
	cout << factor;
}