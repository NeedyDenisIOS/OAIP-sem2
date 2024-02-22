#include <iostream> 
#include <stdio.h>
#include <stdarg.h>
using namespace std;
double func1(double x);
double func2(double x);

void var13_1();
void dihotomia(double a, double b, double (*func)(double));

void main()
{
    var13_1();

}
void var13_1()
{
    double a, b;
    cout << "Enter a, b " << endl;
    cin >> a;
    cin >> b;
    dihotomia(a, b, func1);
    dihotomia(a, b, func2);

}

double func1(double x)
{
    return 5 * x - 1 + pow(x, 3);
}

double func2(double x)
{
    return pow(x, 2) + (1 / x);
}

void dihotomia(double a, double b, double (*func)(double))
{
    double e = 0.0001, x;
    do
    {
        x = (a + b) / 2;
        if ((*func)(a) * (*func)(x) <= 0)
            b = x;
        else
            a = x;
    } while (abs(a - b) > 2 * e);
    cout << "x = " << x << endl;
}
