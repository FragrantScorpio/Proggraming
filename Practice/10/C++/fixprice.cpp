#include<iostream>
#include<locale>

using namespace std;
int rasmer, l1, r1, l2, r2, x1, x2, z;
int main()
{
    setlocale(LC_ALL, "ru");
    cout << "Введите число и разницу\n";
    x1 = 0;
    x2 = 0;
    z = 0;
    cin >> rasmer >> l1 >> r1 >> l2 >> r2;
    if ((rasmer > (r1 + r2)) || (rasmer < (l1 + l2)))
    {
        cout << -1;
    }
    else
    {
        if ((rasmer - l1) >= l2)
        {
            if (rasmer <= (l1 + r2))
            {
                 cout << l1 << rasmer   - l1;
            }
            else
            {
                z = abs(rasmer - (l1 + r2));
                if ((l1 + z) < r1 && (r2 - z) > l2)
                {
                    cout << l1 + z << rasmer - (l1 + z);
                }
                else
                {
                    cout << -1;
                }
            }
        }
        else
        {
         cout << -1;
        }
    }
}