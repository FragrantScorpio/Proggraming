#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std;
template<class T> using vectorT = vector<T>;// template class T это шаблон для вектора, чтоб он мог принимать значение любого типа

template<class T> using matrixT = vector<vectorT<T>>;

template<class T>
bool BiggerN(const T& first, const T& second)
{
    return first > second;
}

template<class T>
bool Less(const T& first, const T& second)
{
    return first < second;
}
template<class T>
bool Sorted(const vectorT<T>& vector, const bool& asc)
{
    const auto sort = asc ? BiggerN<T> : Less<T>; //происходит вопрос отсортирован ли объект

    for (size_t i = 1; i < vector.size(); ++i)
    {
        if (sort(vector[i - 1], vector[i]))
        {
            return false;
        }
    }

    return true;
}

template<class T>
vectorT<T> BozoSort(const vectorT<T>& vector, const bool& asc) //сама сортировка методом клоуна бозо, где он берет случайные значения, меняет местами пока что-то не получится, 
                                                               //тут оно для первого варианта вывода где просто вектор

{
    vectorT<T> result = vector;
    if (vector.size() < 2)
    {
        return result;
    }

    const size_t size = result.size();
    while (!Sorted(result, asc))
    {
        swap(result[std::rand() % size], result[std::rand() % size]);
    }
    return result;
}

template<class T>
vectorT<T> BozoSort(const matrixT<T>& matrix, const bool& asc) //для второго где вектор в векторе
{
    vectorT<T> result;
    for (const vectorT<T>& row : matrix)
    {
        for (const T& item : row)
        {
            result.push_back(item);
        }
    }

    return BozoSort(result, asc);
}

template<class T>
vectorT<T> BozoSort(const T& a, const T& b, const T& c, const bool& asc) //и для третьего, где просто три значения
{
    vectorT<T> vector = { a, b, c };
    return BozoSort(vector, asc);
}

template<class T>
void print(const vectorT<T>& vector)//это для вывода
{
    for (size_t i = 0; i < vector.size() - 1; ++i)
    {
        cout << vector[i] << " ";
    }

    cout << vector[vector.size() - 1] << std::endl;
}


template<class T>
void out()//это вывод
{
    setlocale(LC_CTYPE, "rus");
    unsigned int n;
    cout << "введите колво символов а затем символы через пробел\n";
   
    cin >> n;

    matrixT<T> matrix;
    vectorT<T> vector;
    vectorT<T> buffer;

    for (unsigned int i = 1; i <= n; ++i)
    {
        T value;
        cin >> value;

        buffer.push_back(value);
        vector.push_back(value);

        if (i % static_cast<unsigned int>(sqrt(n)) == 0)
        {
            matrix.push_back(buffer);
            buffer.clear();
        }
    }

     print(BozoSort(vector, true));
     print(BozoSort(vector, false));
     print(BozoSort(matrix, true));
     print(BozoSort(matrix, false));
     print(BozoSort(vector[0], vector[1], vector[2], true));
     print(BozoSort(vector[0], vector[1], vector[2], false));
}

int main()// из-за этого почему-то прекращает выдавать ошибку, я так и не понял почему, (помог друг но объяснить не сумел)
{
    std::srand(time(nullptr));
    out<double>();
    out<std::string>();
}
