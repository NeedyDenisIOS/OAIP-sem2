#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>
#include <algorithm>

using namespace std;

std::vector<int> keys;

struct Hash_table
{
public:
    int size = 10;
    int count = NULL;
    int* data = new int[size];

    Hash_table(int size) :size(size)
    {
        data = new int[size];
        fill(data, data + size, 0);
    }
    Hash_table() {}

    int prime_number(int size)
    {
        if (size <= 3) { return 0; }
        else return prime_number_exp(size, size / 2);
    }

    int prime_number_exp(int a, int b)
    {
        if (b == 1) { return 1; }
        if (a % b != 0) { return prime_number_exp(a, --b); }
        else return 0;
    }

    int Next_hash(int key, int size, int p)
    {
        int index = 5 * ((rand() % size + 1 / key) - double((0.6180339887499 * double(rand() % size + 1))));
        if (index < 0 || index > size) { return Next_hash(rand() % size + 1, size, rand() % size + 1); }
        while (data[index % size] != NULL)
        {
            cout << "коллизия" << endl;
            index = rand() % size;
        }
        return index;
    }

    void Add(int& value)
    {
        if (count == size) { cout << "Таблица полная((( " << endl; return; }
        else
        {
            int key = 0;
            cout << "Введите ключ: "; cin >> key;
            keys.push_back(key);
            if (std::count(keys.begin(), keys.end(), key) > 1) { cout << "такой ключ уже есть!" << endl; return; }
            int index = Next_hash(key, size, 2);
            cout << "Зашифрованная строка:" << '\t' << index << endl;
            index = index % size;
            data[index] = value;
            ++count;
        }
    }

    void Output()
    {
        if (count == 0) { cout << "Таблица пуста! " << endl; return; }
        for (int i = 0; i < size; ++i)
        {
            if (data[i] > -1000)
            {
                cout << "\nКлюч:\t" << i << '\t';
                cout << "значение:\t" << data[i] << endl;
            }
        }
    }

    void Search(int key)
    {
        if (count == 0) { cout << "Таблица пуста! " << endl; return; }
        for (int i = 0; i < size; ++i)
        {
            if (data[i] != NULL)
            {
                if (i == key)
                {
                    cout << "Ключ:\t" << i << '\t';
                    cout << "значение:\t" << data[i] << endl;
                    return;
                }
            }

        }
        cout << "Элемент не найден" << endl;

    }

    void Remove(int key)
    {
        if (count == 0) { cout << "Таблица пуста! " << endl; return; }
        for (int i = 0; i < size; ++i)
        {
            if (data[i] != NULL)
            {
                if (i == key)
                {
                    data[i] = NULL;
                    --count;
                    cout << "Элемент удален" << endl;
                    return;
                }
            }
        }
        cout << "Элемент не найден" << endl;
    }
};

void main()
{
    system("chcp 1251");
    clock_t start, end;
    double searching_time;
    int choice = 0;
    int amount = 0;
    int value;
    int key = 0;
    int a = 0;
    Hash_table* hash1 = new Hash_table();
    for (;;)
    {
        cout << "1 - создание хэш-таблицы\n";
        cout << "2 - добавление элемента\n";
        cout << "3 - вывод\n";
        cout << "4 - Поиск\n";
        cout << "5 - Удаление элемента\n";
        cout << "ваш выбор?\n";
        cin >> choice;
        cout << "\n";
        switch (choice)
        {
        case 1:
            cout << "Введите размер хэш-таблицы: " << endl;
            cin >> amount;
            a = hash1->prime_number(amount);
            while (a != 1)
            {
                cout << "это не простое число!!!" << endl;
                cin >> amount;
                a = hash1->prime_number(amount);
            }
            hash1 = new Hash_table(amount);
            break;
        case 2:
            cout << "\nВведите строку: ";
            cin.ignore();
            cin >> value;
            hash1->Add(value);
            break;
        case 3:
            cout << "\nВывод:\n ";
            hash1->Output();
            break;
        case 4:
            cout << "\nВведите ключ: ";
            cin >> key;
            start = clock();
            hash1->Search(key);
            end = clock();
            searching_time = (double)(end - start) / CLOCKS_PER_SEC;
            cout << "время поиска: " << searching_time << endl;
            break;

        case 5:
            cout << "\nВведите ключ: ";
            cin >> key;
            hash1->Remove(key);
            break;
        case 8:  exit(0);
        }
    }
}