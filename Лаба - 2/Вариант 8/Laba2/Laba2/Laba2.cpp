#include <iostream>
#include <fstream>

using namespace std;

void matrixMultiplication(const string& fileA, const string& fileB, const string& fileC) {
    ifstream fileAStream(fileA), fileBStream(fileB);
    if (!fileAStream) {
        cerr << "Ошибка" << endl;
    }
    ofstream fileCStream(fileC);
    if (!fileCStream) {
        cerr << "Ошибка" << endl;
    }
    int n, m;

    fileAStream >> n;
    fileBStream >> m;
    if (n != m) {
        cerr << "Ошибка: количество столбцов матрицы A должно совпадать с количеством строк матрицы B." << endl;
        return;
    }

    int** A = new int* [n];
    for (int i = 0; i < n; ++i) {
        A[i] = new int[n];
    }


    int* B = new int[n];


    int* C = new int[n];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            fileAStream >> A[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        fileBStream >> B[i];
    }

    // -----
    for (int i = 0; i < n; ++i) {
        C[i] = 0;
        for (int j = 0; j < n; ++j) {
            C[i] += A[i][j] * B[j];
        }
    }

    // результат 
    fileCStream << n << endl;
    for (int i = 0; i < n; ++i) {
        fileCStream << C[i] << " ";
    }

    for (int i = 0; i < n; ++i) {
        delete[] A[i];
    }
    delete[] A;
    delete[] B;
    delete[] C;

    cout << "Произведение матриц успешно записано в файл " << fileC << endl;

    fileAStream.close();
    fileBStream.close();
    fileCStream.close();
}

int main() {

    setlocale(LC_ALL, "Russian");
    const string fileA = "matrix_A.txt"; 
    const string fileB = "matrix_B.txt"; 
    const string fileC = "matrix_C.txt"; 

    matrixMultiplication(fileA, fileB, fileC); 

    return 0;
}
