#include <stdarg.h>
#include <iostream>

using namespace std;

int sum(int a, int b, ...)
{
    int fl = 0, A[101] = { 0 };
    va_list factor;
    va_start(factor, b);
    for (int i = 0; i < b; i++)
    {
        A[i] = va_arg(factor, int);
    }
    va_end(factor);

    for (int i = a - 1; i < b; i++) { 
        for (int j = 1; j <= A[i]; j++) {
            if (A[i] % j == 0) fl++;
        }
        if (fl == 2) cout << A[i] << " ";
        fl = 0;
    }
    cout << endl;
    return 0;
}

int main()
{
    setlocale(LC_CTYPE, "Russian");
    int n = 0, a = 0, b = 0;
    cout << "Введите количество интервалов: ";
    cin >> n;

    if (n <= 0) {
        cout << "Ошибка: количество интервалов должно быть положительным." << endl;
        return 1; 
    }

    for (int i = 0; i < n; i++) {
        cout << "a,b: ";
        cin >> a >> b;
        sum(a, b, 1, 3, 2, 9, 85, 7, 14, 1, 20, 25, 41, 2, 14, 7, 9, 36, 5, 3, 1, 27, 29, 20, 1869, 1, 1, 1, 7, 123, 17, 52, 34, 8, 6, 9, 84);
    }
    return 0;
}
