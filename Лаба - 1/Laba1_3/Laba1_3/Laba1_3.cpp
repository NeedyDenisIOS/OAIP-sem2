#include <iostream> 
#include <cmath>

using namespace std;

double MyFunctionOne(double); // -8 = 12
double MyFunctionTwo(double); // 0,1 = 1
void conclusion();

double dihotomia(double a, double b, double (*func)(double));

int main() {
    setlocale(LC_ALL, "Russian");
    conclusion();
    return 0;
}

double MyFunctionOne(double x) {
    return cos(x) + x - 7;
}

double MyFunctionTwo(double x) {
    return exp(x) - 1 / x;
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
