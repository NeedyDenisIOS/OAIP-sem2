#include <iostream>
#include <fstream>
#include <string>

using namespace std; 

int main() {
    setlocale(LC_ALL, "");
    ifstream inputFile("FILE1.txt");
    ofstream outputFile("FILE2.txt");

    if (!inputFile.is_open()) {
        cerr << "Невозможно открыть файл" << endl;
        return 1;
    }

    if (!outputFile.is_open()) {
        cerr << "Невозможно создать файл" << endl;
        inputFile.close();  // Закрываем открытый входной файл
        return 1;
    }

    // Пропустить 3 строки перед началом копирования
    for (int i = 0; i < 3; ++i) {
        string line;
        if (!getline(inputFile, line)) {
            cerr << "Недостаточно линий в файле" << endl;
            inputFile.close();
            outputFile.close();
            return 1;
        }
    }

    // Копирование оставшихся строк из input.txt в output.txt
    string line;
    while (getline(inputFile, line)) {
        outputFile << line << endl;
    }

    // Закрытие файлов
    inputFile.close();
    outputFile.close();

    cout << "Линии успешно скопированы в новый файл" << endl;

    return 0;
}
