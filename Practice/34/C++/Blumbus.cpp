#include <iostream>

using namespace std;
void create(int** dynam, const int num, const int start, const int step) {
    int* dynamic = new int[num];
    *dynamic = start;
    for (int i = 1; i < num; i++)
    {
        *(dynamic + i) = *(dynamic + i - 1) + step;
    }
    *dynam = dynamic;
}



void sort(int* dynam, int num) {
    int temp = 0;
    for (int i = 0; i < num - 1; ++i)
    {
        for (int i2 = 0; i2 < num - 1; ++i2)
        {
            if (dynam[i2 + 1] < dynam[i2])
            {
                temp = dynam[i2 + 1];
                dynam[i2 + 1] = dynam[i2];
                dynam[i2] = temp;
            }
        }
    }
}

void print(int* dynam, int num) {
    cout << "[";
    for (int i = 0; i < num; i++) { cout << dynam[i]; if (i != num - 1) { cout << ", "; } }
    cout << "]";
}
void kill(int** dynam) {
    if (*dynam) {
        delete[] * dynam;
        *dynam = nullptr;
 }
   if (dynam == nullptr) {
        return;
    }
 
}
int main() {
    setlocale(LC_CTYPE, "rus");
    int num, step, start;
    cout << "Введите размер массива\n";
    cin >> num;
    cout << "Введите начальный член\n";
    cin >> start;
    cout << "Введите шаг арифм прогрессии\n";
    cin >> step;
    int* dynamic;
    create(&dynamic, num, start, step);
    sort(dynamic, num);
    print(dynamic, num);
    kill(&dynamic);
    return 0;
}