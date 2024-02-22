#include <iostream>
#include <cstdarg> 

using namespace std;

int fmax(int n, ...);
double fmax(double n, ...);

int main()
{
    cout << fmax(4, 2, 3, 4, 5) << endl;
    cout << fmax(5, 8, 21, 56, 22, 7) << endl;
    cout << fmax(2.0, 1.7, 5.5) << endl;
    cout << fmax(3.0, 3.33, -1.44, 7.99) << endl;

    return 0;
}

int fmax(int n, ...)
{
    va_list args;
    va_start(args, n);

    int min = n;
    for (int i = 0; i < n; ++i)
    {
        int value = va_arg(args, int);
        if (value < min)
        {
            min = value;
        }
    }

    va_end(args);

    return min;
}

double fmax(double n, ...)
{
    va_list args;
    va_start(args, n);

    double min = n;
    for (int i = 0; i < static_cast<int>(n); ++i)
    {
        double value = va_arg(args, double);
        if (value < min)
        {
            min = value;
        }
    }

    va_end(args);

    return min;
}
