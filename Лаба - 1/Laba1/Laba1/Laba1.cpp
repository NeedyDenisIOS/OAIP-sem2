#include <iostream>
#include <cmath>

using namespace std;

double MyFunctionOne(double);
double MyFunctionTwo(double);
void conclusion();

double dihotomia(double a, double b, double (*func)(double));

int main() {
    setlocale(LC_ALL, "Russian");
    conclusion();
    return 0;
}

double MyFunctionOne(double x) {
    return exp(x) - 3 - 1 / x;
}

double MyFunctionTwo(double x) {
    return 0.2 - pow(x, 2);
}

double dihotomia(double a, double b, double (*func)(double)) {
    double x, e = 0.0001;

    while (fabs(b - a) > e) {
        x = (a + b) / 2;

        if ((*func)(x) * (*func)(a) < 0)
            b = x;
        else
            a = x;
    }

    return x;
}

void conclusion() {
    double a, b;
    cout << "Enter a, b:" << endl;
    cin >> a >> b;
    cout << dihotomia(a, b, MyFunctionOne) << endl;
    cout << dihotomia(a, b, MyFunctionTwo) << endl;
}
