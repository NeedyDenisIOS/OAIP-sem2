#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

// Определение структуры pawnshop для хранения информации о товарах
struct pawnshop {
    string data;
    string product;
    double asses;
    double sum;
    string term;
    int period;
};

// Вектор для хранения товаров
vector<pawnshop> items;

// Функция для добавления товара в вектор
void AddProduct() {
    pawnshop newItem;
    cout << "Введите ваше Имя: ";
    cin >> newItem.data;
    cout << "Название товара: ";
    cin >> newItem.product;
    cout << "Оценочная стоимость товара: ";
    cin >> newItem.asses;
    cout << "Сумма, выданная под залог: ";
    cin >> newItem.sum;
    cout << "Дата сдачи: ";
    cin >> newItem.term;
    cout << "Срок хранения: ";
    cin >> newItem.period;
    items.push_back(newItem);
}

// Функция для вывода всех товаров из вектора
void Display() {
    cout << "База хранимых товаров и недвижимости:" << endl;
    for (const auto& pawnshop : items) {
        cout << "Имя: " << pawnshop.data << endl;
        cout << "Название товара: " << pawnshop.product << endl;
        cout << "Оценочная стоимость товара: " << pawnshop.asses << endl;
        cout << "Сумма, выданная под залог: " << pawnshop.sum << endl;
        cout << "Дата сдачи: " << pawnshop.term << endl;
        cout << "Срок хранения: " << pawnshop.period << endl;
        cout << "------------------------" << endl;
    }
}

// Функция для удаления товара из вектора по его имени
void deleteItem(const string& itemName) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (it->product == itemName) { // Исправлено на сравнение с именем товара
            items.erase(it);
            cout << "Успешно удалено" << endl;
            return;
        }
    }
    cout << "Не найдено" << endl;
}

// Функция для сохранения данных в файл
void saveToFile(const string& filename) {
    ofstream outFile(filename);
    if (outFile.is_open()) {
        for (const auto& pawnshop : items) {
            outFile << pawnshop.data << "," << pawnshop.product << "," << pawnshop.asses << "," << pawnshop.sum << "," << pawnshop.term << "," << pawnshop.period << "\n";
        }
        outFile.close();
        cout << "Данные успешно сохранены в файл" << endl;
    }
    else {
        cout << "Невозможно открыть файл" << endl;
    }
}

// Функция для чтения данных из файла
void readFromFile(const string& filename) {
    ifstream inFile(filename);
    if (inFile.is_open()) {
        items.clear(); // Очистить вектор перед чтением из файла
        string line;
        while (getline(inFile, line)) {
            pawnshop newItem;
            stringstream ss(line);
            getline(ss, newItem.data, ',');
            getline(ss, newItem.product, ',');
            ss >> newItem.asses;
            ss.ignore();
            ss >> newItem.sum;
            ss.ignore();
            getline(ss, newItem.term, ',');
            ss >> newItem.period;
            items.push_back(newItem);
        }
        inFile.close();
        cout << "Данные успешно загружены из файла" << endl;
    }
    else {
        cout << "Невозможно открыть файл" << endl;
    }
}

int main() {
    setlocale(LC_CTYPE, "Russian");

    int choice;

    do {
        cout << "\nМеню:\n";
        cout << "1. Добавить товар\n";
        cout << "2. Показать товары\n";
        cout << "3. Удалить товар\n";
        cout << "4. Сохранить данные в файл\n";
        cout << "5. Прочитать данные из файла\n";
        cout << "6. Выход\n";
        cout << "Введите ваш выбор: ";

        cin >> choice;

        switch (choice) {
        case 1:
            AddProduct();
            break;
        case 2:
            Display();
            break;
        case 3: {
            string itemName;
            cout << "Введите название товара для удаления: ";
            cin >> itemName;
            deleteItem(itemName);
            break;
        }
        case 4:
            saveToFile("pawnshop_data.txt");
            break;
        case 5:
            readFromFile("pawnshop_data.txt");
            break;
        case 6:
            cout << "Завершение программы.\n";
            break;
        default:
            cout << "Неверный выбор. Пожалуйста, введите число от 1 до 6.\n";
        }
    } while (choice != 6);

    return 0;
}
