#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


vector<int> outdata(vector<int> sorting, int sizing) {
	int count = 0;
	sort(sorting.begin(), sorting.end(), greater<int>());// с помощью библиотеки алгоритмов, мы сократили код, и все еще можем отсортировать наши значения
	if ((sorting.size() < 5))// тут частные случаи при значениях меньше 5, и дальше при больше 5, чтоб согласовано было с условием
	{
		for (int i = 0; i < sizing; i++)
		{
			if (i < 5)// тут для случая где сигналов меньше пяти
			{
			cout << sorting[i] << ' ';
			}
			else
			{
				break;
			}
		}
	}
	else
	{
		for (int i = sorting.size()- 5; i < sorting.size(); i++)//тут где больше 5
		{
			cout << sorting[i] << ' ';
		}
	}
	cout << "\n";
	return sorting;
}


int main() {
	setlocale(LC_CTYPE, "rus");
	cout << "Прием! Сколько пришло сигналов Cэр?\n";
	int sizing;
	cin >> sizing;
	cout << "Опишите их\n";
	vector<int> maine(sizing); vector<int> sorting(0); vector<int> exeption(0);
	for (int i = 0; i < sizing; i++)
	{
		cin >> maine[i];
	}
	cout << "Вот отсортированный вариант Сэр!\n";
	for (int i = 0; i < maine.size(); i++)
	{
		sorting.push_back(maine[i]);int sizing = sorting.size();outdata(sorting, sizing);

	}
}
