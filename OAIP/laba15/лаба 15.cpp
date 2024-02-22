#include <iostream>
#include <string>
#include <vector>

using namespace std;

class HashTable {
public:
    HashTable(int size) : size_(size), table_(size) {}

    void insert(int key, const vector<string>& value)
    {
        int hash = getHash(key);
        for (auto& kv : table_[hash]) {
            if (kv.first == key) {
                kv.second = value;
                return;
            }
        }
        table_[hash].emplace_back(key, value);
    }

    void remove(int key) {
        int hash = getHash(key);
        for (auto it = table_[hash].begin(); it != table_[hash].end(); ++it) {
            if (it->first == key) {
                table_[hash].erase(it);
                return;
            }
        }
    }

    vector<string> find(int key) const {
        int hash = getHash(key);
        for (auto& kv : table_[hash]) {
            if (kv.first == key) {
                return kv.second;
            }
        }
        return {};
    }

    void printTable() const {
        for (int i = 0; i < size_; ++i) {
            cout << i << ": ";
            for (auto& kv : table_[i]) {
                cout << "{" << kv.first << ":";
                for (auto& name : kv.second) {
                    cout << " " << name;
                }
                cout << "}";
            }
            cout << endl;
        }
    }

private:
    int getHash(int key) const {
        int hash = 0;
        string s = to_string(key);
        for (char c : s) {
            hash ^= c;
        }
        return hash % size_;
    }

    int size_;
    vector<vector<pair<int, vector<string>>>> table_;
};

int main()
{
    system("chcp 1251");
    int size;
    clock_t start, end;
    double searching_time;
    cout << "Введите размер таблицы: ";
    cin >> size;
    HashTable ht(size);

    while (true)
    {
        cout << endl;
        cout << "1. Вывести таблицу" << endl;
        cout << "2. Добавить элемент" << endl;
        cout << "3. Удалить элемент" << endl;
        cout << "4. Найти элемент" << endl;
        cout << "5. Выход" << endl;
        cout << "Выберите действие: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            ht.printTable();
            break;
        case 2: {
            int key;
            cout << "Введите номер группы: ";
            cin >> key;
            auto val = ht.find(key);
            if (!val.empty())
            {
                cout << "повтор ключа" << endl;
                break;
            }
            cout << "Введите количество студентов: ";
            vector<string> value;
            string name;
            while (cin >> name)
            {
                value.push_back(name);
                if (cin.get() == '\n')
                {
                    break;
                }
            }
            ht.insert(key, value);
            break;
        }
        case 3: {
            int key;
            cout << "Введите номер группы: ";
            cin >> key;
            auto value = ht.find(key);
            if (value.empty())
            {
                cout << "Нет такого элемента" << endl;
                break;
            }

            else
            {
                ht.remove(key);
            }
            break;
        }
        case 4:
        {
            int key;
            cout << "Введите номер группы: ";
            cin >> key;
            start = clock();
            auto value = ht.find(key);
            if (!value.empty()) {
                cout << "количество студентов: ";
                for (auto& name : value) {
                    cout << name << " ";
                }
                cout << endl;
            }
            else
            {
                cout << "Элемент не найден" << endl;
            }
            end = clock();
            searching_time = (double)(end - start) / CLOCKS_PER_SEC;
            cout << "время поиска: " << searching_time << endl;
            break;
        }
        case 5:
            return 0;
        default:
            cout << "Неверный выбор" << endl;
        }
    }

    return 0;
}
