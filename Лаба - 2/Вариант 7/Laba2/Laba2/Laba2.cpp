#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void interleaveFiles(const string& fileA, const string& fileB, const string& fileC, const string& fileD) {
    ifstream finA(fileA);
    ifstream finB(fileB);
    ifstream finC(fileC);
    ofstream foutD(fileD);

    if (!finA || !finB || !finC || !foutD) {
        cerr << "Ошибка при открытии файлов." << endl;
        return;
    }

    int numA, numB, numC;
    while (finA >> numA && finB >> numB && finC >> numC) {
        foutD << numA << " " << numB << " " << numC << " ";
    }

    cout << "Чередующиеся элементы записаны в файл " << fileD << endl;

    finA.close();
    finB.close();
    finC.close();
    foutD.close();
}

int main() {
    setlocale(LC_ALL, "Russian");
    string fileA = "A.txt";
    string fileB = "B.txt";
    string fileC = "C.txt";
    string fileD = "D.txt";

    interleaveFiles(fileA, fileB, fileC, fileD);

    return 0;
}
