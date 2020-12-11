#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

void print_factorization(unsigned int number)
{
    map  <unsigned int, unsigned int> deletes;// создали словарь
    int div = 2;
    while (number > 1) // пока число больше одного
    {
        for (unsigned int i = 2; i <= number; i++)
        {
            if (!(number % i))// оно будет проверять делится ли нацело заданное число на i(стандартное i это двойка чтоб не зациклилось навечно) 
            {
                number /= i;

                deletes[i] = deletes.count(i) ? deletes[i] + 1 : 1;//идёт проверка, повторяются ли делители, и если да, то справа от делителя прибавляется единица(это будет в будущем степень)
                break;
            }
        }
    }
    cout << "1"; //потому что он почему-то пишет множитель впереди, а при умножении на 1 ничего не поменяется, так что фактически верно)))
    for (auto current : deletes)//читает весь наш словарь с помощью auto 
    {
        if (current.second > 1)// если наше число повторилось больше одного раза, то оно будет выводится в консоль ввиде степени
        {
            cout << "" << current.first << "^" << current.second;
        }
        else
        {
            cout << "*" << current.first;//а если не повторилось, то просто выведится число
        }
    }
}
int main()
{
    unsigned int num;
    cin >> num;
    print_factorization(num);
}