
#include "List.h"
#include <iostream>
using namespace std;

struct HotelClients
{
	string passport;
	string fio;
	string dateIn;
	string dateOut;
	string num;
	string typeNum;
	HotelClients* next;
};

void print(void* b)       //Функция используется при выводе 
{
	HotelClients* a = (HotelClients*)b;
	cout << a->passport << " " << a->fio << " " << a->dateIn << " " << a->dateOut << " " << a->num << " " << a->typeNum << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	HotelClients a1 = { "167", "Гомель", "пн-чт", "17:25", "14:45"};
	HotelClients a2 = { "343", "Мозырь", "вт-сб", "13:56", "16:36"};
	HotelClients a3 = { "876", "Солигорск", "ср-вс", "09:09", "13:01" };
	Object L1 = Create();
	L1.Insert(&a3);
	L1.Insert(&a2);
	L1.Insert(&a1);
	bool rc;
	int c, n;
	do {
		cout << "Выберите, что сделать:" << endl;
		cout << "1 - вывести список и кол-во элементов;" << endl;
		cout << "2 - найти элемент;" << endl;
		cout << "3 - удалить элемент;" << endl;
		cout << "4 - удаление списка;" << endl;
		cout << "0 - выход." << endl;
		cin >> c;
		switch (c)
		{
		case 1:
			L1.PrintList(print);
			break;
		case 2: {
			cout << "Сделайте выбор:" << endl;
			cout << "1 элемент:" << endl;
			cout << "2 элемент:" << endl;
			cout << "3 элемент:" << endl;
			cin >> n;
			switch (n) {
			case 1: {
				Element* e = L1.Search(&a1);
				HotelClients* aa = (HotelClients*)e->Data;
				cout << "Пункт назначения №1: " << aa->fio << endl; }
				  break;
			case 2: {
				Element* e = L1.Search(&a2);
				HotelClients* aa = (HotelClients*)e->Data;
				cout << "Пункт назначения №2: " << aa->fio << endl; }
				  break;
			case 3: {
				Element* e = L1.Search(&a3);
				HotelClients* aa = (HotelClients*)e->Data;
				cout << "Пункт назначения №3: " << aa->fio << endl; }break;
			}break;
		}
		case 3: {

			cout << "Сделайте выбор:" << endl;
			cout << "1 элемент:" << endl;
			cout << "2 элемент:" << endl;
			cout << "3 элемент:" << endl;
			int o;
			cin >> o;
			switch (o) {
			case 1: rc = L1.Delete(&a1);
				if (rc == true) cout << "Удален элемент №1." << endl;
				break;
			case 2:rc = L1.Delete(&a2);
				if (rc == true) cout << "Удален элемент №2." << endl;
				break;
			case 3: rc = L1.Delete(&a3);
				if (rc == true) cout << "Удален элемент №3." << endl;
				break;
			}break;
			cout << "Список:" << endl;
			L1.PrintList(print);
			return 0;
		}
		case 4:
			rc = L1.Delete(&a1);
			rc = L1.Delete(&a2);
			rc = L1.Delete(&a3);
			break;
		}
	} while (c != 0);
}
