#include <iostream>

using namespace std;
struct IntArray {
    int* data;
    int size;
};
void create(IntArray& arr, int size) {
    arr.data = new int[size];
    arr.size = size;
}
void create(IntArray* arr, int size)
{
    create(*arr, size);
}

void get(IntArray& arr, int index) {
    if (index < 0 or index > arr.size) { cout << "Размер за рамками возможного"; exit(0); }
}
void get(IntArray* arr, int index) { get(*arr, index); }
void set(IntArray& arr, int index, int value) {
    int temp;
    if (index < 0 or index > arr.size) { cout << "Размер за рамками возможного"; exit(0); }
    temp = index;
    arr.data[index] = value;
}
void set(IntArray* arr, int index, int value) { set(*arr, index, value); }

void print(IntArray& arr) {
    cout << "[";
    for (int i = 0; i < arr.size; i++)
    {
        if (i < arr.size - 1)
        {
            cout << *(arr.data + i) << " ";
        }
        else
        {
            cout << *(arr.data + i);
        }
    }
    cout << "]" << "\n";
};
void print(IntArray* arr) { print(*arr); };

void resize(IntArray& arr, int newSize) {
if (newSize == arr.size)
    {
        return;
    }
    else if (newSize > arr.size)
    {
        int* newArray = new int[newSize];
        memcpy(newArray, arr.data, sizeof(int) * arr.size);
        for (int i = arr.size; i < newSize; ++i)
            newArray[i] = 0;delete[] arr.data;
        arr.data = newArray;
        arr.size = newSize;
    }
    else
    {
        int* newArray = new int[newSize];
        memcpy(newArray, arr.data, sizeof(int) * newSize);
        delete[] arr.data;
        arr.data = newArray;
        arr.size = newSize;
    }
}


void resize(IntArray* arr, int newSize) { resize(*arr, newSize); };
void destroy(IntArray& arr) { if (!arr.data) { delete[] arr.data; arr.data = nullptr; } arr.size = 0; }
void destroy(IntArray* arr) {
    destroy(*arr);
}

int main()
{
    setlocale(LC_CTYPE, "rus");
    {
        IntArray arr; int size = 30; create(arr, size);
        for (int i = 0; i < size; ++i)
        {
            set(arr, i, i + 1);
        }
        print(arr); resize(arr, 50);
        print(arr); resize(arr, 10);
        print(arr); destroy(arr);
    }
    cin.get();
    return 0;
}