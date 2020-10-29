#include<iostream>;
#include<string>;
using namespace std;
int number, i,fails;//s=символы, number=число, fails= Неудачные проверки
int main(){
    setlocale(LC_CTYPE, "rus");
    cout << "Введите число билетов\n";
    cin >> number;
    cout << "Введите код билетов по очереди нажимая ввод\n";
    string s{};
for (i = 1; i <= number; i++)
{
    cin >> s;
    if (s[0] == 'a' and s[4] == '5' and s[5] == '5' and s[6] == '6' and s[7] == '6' and s[8] == '1')
    {
        cout << s << ' ';
    }
    else
    {
        fails++;
    }
}
if (fails == number)
{
    cout << "-1";
}
}