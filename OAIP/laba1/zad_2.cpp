#include <iostream>
#include <ctime>
#include <stdarg.h>

using std::cout; using std::cin; using std::endl;

void foundMinElement(int*, int, ...);
void createMatrix(int);

void foundMinElement(int* counts, int n, ...)
{
    va_list list_of_matrix;
    va_start(list_of_matrix, n);
    for (int k = 0; k < n; k++)
    {
        int matrix = va_arg(list_of_matrix, int);
        int sum = 0;
        int count = counts[k];
        for (int i = 0; i < count; i++)
        {
            for (int j = 0; j < count; j++)
            {
                if (i > j)
                {
                    sum += matrix[i][j];
                }
            }
        }
        cout << sum << endl;
    }
    va_end(list_of_matrix);
}

void createMatrix(int count)
{
    int*** vect_matr = new int[count];
    int* counts = new int[count];
    for (int h = 0; h < count; h++)
    {
        int n = NULL; cout << endl << "Введите размер матрицы: "; cin >> n;
        int** matrix = new int* [n];
        for (int i = 0; i < n; i++)
        {
            *(matrix + i) = new int[n];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                *(*(matrix + i) + j) = rand() % 10 + 1;
                cout << *(*(matrix + i) + j) << "\t";
            }
            cout << endl;
        }
        vect_matr[h] = matrix;
        counts[h] = n;
        cout << endl;
    }
    cout << endl;
    foundMinElement(counts, count, vect_matr[0], vect_matr[1], vect_matr[2]); //количество индексов должно совпадать с количеством элементов в counts
}

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "ru");

    int count = NULL; cout << endl << "Введите количество матриц: " << endl; cin >> count;
    createMatrix(count);
}