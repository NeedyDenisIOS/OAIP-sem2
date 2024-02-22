#include <iostream>
#include <cstdarg>

using namespace std;

int mn(int count, ...);

int main()
{
    cout << mn(2, 10, 5) << endl;
    cout << mn(5, 3, 21, 56, 22, 7) << endl;
    cout << mn(3, -10, -5, -15) << endl;

    return 0;
}

int mn(int count, ...)
{
    va_list args;
    va_start(args, count);

    int min_value = va_arg(args, int);

    for (int i = 1; i < count; ++i)
    {
        int value = va_arg(args, int);
        if (value < min_value)
        {
            min_value = value;
        }
    }

    va_end(args);

    return min_value;
}
