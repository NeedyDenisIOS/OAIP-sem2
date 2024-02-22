#include <iostream>
#include <cstdarg>
#include <cmath>

using namespace std;

bool isPerfectSquare(int num) {
    int squareRoot = static_cast<int>(sqrt(num));
    return squareRoot * squareRoot == num;
}

int kvadr(int count, ...) {
    va_list args;
    va_start(args, count);

    int perfectSquareCount = 0;

    for (int i = 0; i < count; ++i) {
        int num = va_arg(args, int);
        perfectSquareCount += isPerfectSquare(num);
    }

    va_end(args);

    return perfectSquareCount;
}

int main() {
    setlocale(LC_ALL, "Russian");

    int result1 = kvadr(2, 4, 16);
    int result2 = kvadr(3, 16, 25, 38);
    int result3 = kvadr(4, 8, 10, 49, 64);

    cout << "Количество точных квадратов в первом вызове: " << result1 << endl;
    cout << "Количество точных квадратов во втором вызове: " << result2 << endl;
    cout << "Количество точных квадратов в третьем вызове: " << result3 << endl;

    return 0;
}
