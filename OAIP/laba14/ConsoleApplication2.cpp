//2. Использовать в проекте функцию универсального 
//хеширования.

#include "Header.h"
#include <iostream>
#include "ctime"
#include "vector"
#include "algorithm"

using namespace std;

//vector<int> primes = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,  };

struct AAA
{
	int key;
	char* mas;
	AAA(int k, char* z)
	{
		key = k;  mas = z;
	} AAA() {}
};
//-------------------------------
int key(void* d)
{
	AAA* f = (AAA*)d;   return f->key;
}
//-------------------------------
void AAA_print(void* d)
{
	cout << " ключ " << ((AAA*)d)->key << " - " << ((AAA*)d)->mas << endl;
}
//-------------------------------


bool isSimple(int num) {

	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}





int main()
{
	setlocale(LC_ALL, "rus");
	AAA a1(1, (char*)"one"), a2(2, (char*)"two"), a3(4, (char*)"three"), a4(2, (char*)"fo");
	int siz = 7, siz2, choice, k;
	cout << "Введите размер хеш-таблицы 1" << endl; 	cin >> siz;

	while (!isSimple(siz))
	{
		cout << "Введите размер хеш-таблицы 1" << endl; 	cin >> siz;
	}

	cout << "Введите размер хеш-таблицы 2" << endl; 	cin >> siz2;


	Object H = create(siz, key);
	Object G = create(siz2, key);

	vector<int> keys1;
	vector<int> keys2;

	for (;;)
	{
		cout << "1 - вывод хеш-таблицы" << endl;
		cout << "2 - добавление элемента" << endl;
		cout << "3 - удаление элемента" << endl;
		cout << "4 - поиск элемента" << endl;
		cout << "5 - вывод хеш-таблицы 2" << endl;
		cout << "6 - добавление элемента 2" << endl;
		cout << "7 - удаление элемента 2" << endl;
		cout << "8 - поиск элемента 2" << endl;
		cout << "9 - сравнение скорости поиска" << endl;
		cout << "0 - выход" << endl;
		cout << "сделайте выбор" << endl;   cin >> choice;
		switch (choice)
		{
		case 0:  exit(0);
		case 1: { setMode(0);
			H.scan(AAA_print);
		}  break;
		case 2: {
			setMode(0);
			AAA* a = new AAA;
			char* str = new char[40];
			cout << "введите ключ" << endl;	cin >> k;
			a->key = k;
			if (count(keys1.begin(), keys1.end(), k) < 1)
			{
				cout << "введите строку" << endl;
				cin.ignore();
				cin.getline(str, 40);
				a->mas = str;
				if (H.N == H.size)
					cout << "Таблица заполнена" << endl;
				else
					H.insert(a);
				keys1.push_back(k);
			}
			else
			{
				cout << "same key exists" << endl;
			}

		} break;
		case 3: {
			setMode(0);
			cout << "введите ключ для удаления" << endl;
			cin >> k;

			for (int i = 0; i < keys1.size(); i++)
			{
				if (keys1[i] == k)
				{
					keys1.erase(keys1.begin() + i);
				}
			}

			H.deleteByKey(k);
		}  break;
		case 4: {
			setMode(0);
			cout << "введите ключ для поиска" << endl;
			cin >> k;

			unsigned int start_time = clock();

			if (count(keys1.begin(), keys1.end(), k) == 0)
				cout << "Элемент не найден" << endl;
			else
				AAA_print(H.search(k));

			unsigned int end_time = clock(); // конечное время
			unsigned int search_time = end_time - start_time;

			cout << "search time " << search_time << " ms" << endl;
		}  break;
		case 5:setMode(1); G.scan(AAA_print);  break;
		case 6: {
			setMode(1);
			setMode(0);
			AAA* a = new AAA;
			char* str = new char[40];
			cout << "введите ключ" << endl;	cin >> k;
			a->key = k;
			if (count(keys2.begin(), keys2.end(), k) < 1)
			{
				cout << "введите строку" << endl;
				cin.ignore();
				cin.getline(str, 40);
				a->mas = str;
				if (G.N == G.size)
					cout << "Таблица заполнена" << endl;
				else
					G.insert(a);
				keys2.push_back(k);
			}
			else
			{
				cout << "same key exists" << endl;
			}

		} break;
		case 7: {
			setMode(1);
			cout << "введите ключ для удаления" << endl;
			cin >> k;

			for (int i = 0; i < keys2.size(); i++)
			{
				if (keys2[i] == k)
				{
					keys2.erase(keys2.begin() + i);
				}
			}


			G.deleteByKey(k);
		}  break;
		case 8: {
			setMode(1);
			cout << "введите ключ для поиска" << endl;
			cin >> k;
			unsigned int start_time = clock();
			if (count(keys2.begin(), keys2.end(), k) == 0)
				cout << "Элемент не найден" << endl;
			else
				AAA_print(G.searchUnivers(k));
			unsigned int end_time = clock(); // конечное время
			unsigned int search_time = end_time - start_time; // 

			cout << "search time " << search_time << " ms" << endl;
		}  break;
		case 9: {
			cout << "введите ключ для поиска" << endl;
			cin >> k;
			setMode(1);

			unsigned int start_time_u = clock();
			if (G.search(k) == NULL)
				cout << "Элемент не найден" << endl;
			else
				AAA_print(G.searchUnivers(k));
			unsigned int end_time_u = clock(); // конечное время
			unsigned int search_time_u = end_time_u - start_time_u; // 

			unsigned int start_time = clock();

			if (H.search(k) == NULL)
				cout << "Элемент не найден" << endl;
			else
				AAA_print(H.search(k));

			unsigned int end_time = clock(); // конечное время
			unsigned int search_time = end_time - start_time;


			if (search_time > search_time_u)
			{
				cout << "module hash fater" << endl;
				cout << "defference " << search_time - search_time_u << endl;
			}
			else
			{
				cout << "unersal hash fater" << endl;
				cout << "defference " << search_time_u - search_time << " ms" << endl;
			}
		}break;
		case 10: {
			char* str = new char[20];
			cout << "введите строку" << endl; cin >> str;

			for (int i = 0; i < siz - 2; i++)
			{
				AAA* a = new AAA;
				a->key = i;
				a->mas = str;
				if (H.N == H.size)
					cout << "Таблица заполнена" << endl;
				else
					H.insert(a);
				G.insert(a);
			}
		}break;
		}
	}
	return 0;
}

