#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

bool checkFileSizes(const string& fileA, const string& fileB, const string& fileC) {
    ifstream finA(fileA);
    ifstream finB(fileB);
    ifstream finC(fileC);

    if (!finA || !finB || !finC) {
        cerr << "Ошибка при открытии файлов." << endl;
        return false;
    }

    int countA = 0, countB = 0, countC = 0;
    int num;
    while (finA >> num) {
        countA++;
    }
    while (finB >> num) {
        countB++;
    }
    while (finC >> num) {
        countC++;
    }

    if (countA != countB || countA != countC) {
        cerr << "Файлы ввода не имеют одинакового размера." << endl;
        return false;
    }

    return true;
}

void findMaxAndWriteToFile(const string& fileA, const string& fileB, const string& fileC, const string& fileD) {
    if (!checkFileSizes(fileA, fileB, fileC)) {
        return;
    }

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
        int maxNum = max(numA, max(numB, numC));
        foutD << maxNum << endl;
    }

    cout << "Максимальные элементы записаны в " << fileD << endl;

    finA.close();
    finB.close();
    finC.close();
    foutD.close();
}

int main() {
    setlocale(LC_ALL, "Russian");
    string fileA = "NameA.txt";
    string fileB = "NameB.txt";
    string fileC = "NameC.txt";
    string fileD = "NameD.txt";

    findMaxAndWriteToFile(fileA, fileB, fileC, fileD);

    return 0;
}
