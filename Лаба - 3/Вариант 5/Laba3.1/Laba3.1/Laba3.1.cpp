#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Функция для записи строки в файл
void writeToTextFile(const char* filename, const char* data) {
    ofstream file(filename);
    if (file.is_open()) {
        file << data;
        cout << "Данные успешно записаны в файл" << endl;
        file.close();
    }
    else {
        cerr << "Невозможно открыть файл" << endl;
    }
}

// Функция для чтения из файла и вывода подстроки, соответствующей записи целого числа
void readFromFile(const char* filename) {
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        getline(file, line); // Считываем строку из файла
        file.close();

        cout << "Полученные данные: " << line << endl;

        // Поиск подстроки, которая соответствует записи целого числа
        string numberSubstring;
        for (char c : line) {
            if (isdigit(c) || c == '+' || c == '-') {
                numberSubstring += c;
            }
            else {
                if (!numberSubstring.empty()) {
                    cout << "Целочисленная подстрока: " << numberSubstring << endl;
                    return;
                }
            }
        }

        // Если целочисленная подстрока находится в конце строки
        if (!numberSubstring.empty()) {
            cout << "Целочисленная подстрока: " << numberSubstring << endl;
        }
        else {
            cerr << "Целочисленная подстрока отсуствует" << endl;
        }
    }
    else {
        cerr << "Невозможно прочитать файл" << endl;
    }
}

int main() {
    setlocale(LC_ALL, "");
    const char* filename = "data.txt";
    char data[100];

    cout << "Ввести с клавиатуры строку, состоящую из букв, цифр, запятых, точек, знаков '+' и '-': ";
    cin.getline(data, sizeof(data));

    writeToTextFile(filename, data); // Запись строки в файл

    readFromFile(filename); // Чтение из файла и вывод целочисленной подстроки

    return 0;
}
