#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// ***
vector<vector<int>> multiplyMatrices(const vector<vector<int>>& matrixA, const vector<vector<int>>& matrixB) {
    int rowsA = matrixA.size();
    int colsA = matrixA[0].size();
    int colsB = matrixB[0].size();

    vector<vector<int>> result(rowsA, vector<int>(colsB, 0));

    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            for (int k = 0; k < colsA; ++k) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    return result;
}

int main() {

    setlocale(LC_ALL, "Russian");
    ifstream fileA("FileA.txt");
    ifstream fileB("FileB.txt");

    if (!fileA != 0 || !fileB != 0) {
        cout << "Не удалось открыть файл для записи." << endl;
        return 1;
    }

    int colsA, colsB;
    fileA >> colsA;
    fileB >> colsB;

    if (colsA <= 0 || colsB <= 0) {
        cout << "Неверные размеры матриц для умножения." << endl;
        
        ofstream fileC("FileC.txt");
        fileC << "Ошибка" << endl;

        return 1;
    }

    vector<vector<int>> matrixA, matrixB;
    int element;

    while (fileA >> element) {
        vector<int> row(colsA);
        row[0] = element;

        for (int i = 1; i < colsA; ++i) {
            fileA >> row[i];
        }

        matrixA.push_back(row);
    }

    while (fileB >> element) {
        vector<int> row(colsB);
        row[0] = element;

        for (int i = 1; i < colsB; ++i) {
            fileB >> row[i];
        }

        matrixB.push_back(row);
    }

    fileA.close();
    fileB.close();

    if (colsA != matrixB.size()) {
        cout << "Неверные размеры матриц для умножения." << endl;
        return 1;
    }

    vector<vector<int>> resultMatrix = multiplyMatrices(matrixA, matrixB);

    ofstream fileC("FileC.txt");

    if (!fileC.is_open()) {
        cout << "Не удалось открыть файл для записи." << endl;
        return 1;
    }

    fileC << colsB << endl;

    for (const vector<int>& row : resultMatrix) {
        for (int value : row) {
            fileC << value << " ";
        }
        fileC << endl;
    }

    fileC.close();

    cout << "Умножение матриц завершено. Результат сохранен в файле FileC.txt." << endl;

    return 0;
}
