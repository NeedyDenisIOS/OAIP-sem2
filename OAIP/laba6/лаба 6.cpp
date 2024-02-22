#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Item {
	int number;
	Item* next;
};

bool check(string v)
{
	for (int i = 0; i < v.length(); i++)
		if (isdigit(v[i]) == true)
			return true;
	return false;
}

void console(Item*& p);
void adding(Item*&, int n);
int del(Item*&, int n);
void search(Item*&, int n);
void write_in_file(Item*&);
void read_from_file(Item*&);
void sum(Item*&);

int main()
{
	setlocale(LC_ALL, "rus");
	Item* p = 0;
	int molom, n;
	bool exit = false;
	while (exit != true)
	{
		cout << "Менюшка" << endl;
		cout << "1-Добавление элемента\n2-Консоль\n3-Удаление элемента\n4-Поиск элемента\n5-запись в файл\n6-Чтение из файла\n7-Сумма отрицательных двухзначных элементов\n8-Выход\n";
		cin >> molom;

		switch (molom)
		{
		case 1:
		{
			string d;
			cout << "Добавьте элемент:" << endl;
			cin >> d;
			check(d);
			n = stoi(d);
			adding(p, n); break;
		}
		case 2: {
			console(p); break;
		}
		case 3: {
			cout << "Удалите элемент" << endl;
			cin >> n;
			del(p, n);
			console(p); break;
		}
		case 4: {
			cout << "Поиск" << endl;
			cin >> n;
			search(p, n);
			break;
		}
		case 5: {
			write_in_file(p);
			console(p); break;
		}
		case 6: {
			read_from_file(p); break;
		}
		case 7: {
			sum(p); break;
		}
		case 8: {
			exit = true; break;
		}
		}
	}

	system("pause");
	return 0;
}
void console(Item*& p) 
{
	Item* head = p;
	if (p == NULL)
	{
		cout << "Список пуст" << endl;
	}
	else {
		while (p != NULL) 
		{
			cout << "*" << p->number << endl;
			p = p->next;
		}
		cout << "NULL" << endl;
	}
	p = head;
}
void adding(Item*& p, int n) 
{
	Item* newP = new Item;
	if (newP != NULL)
	{
		newP->number = n;
		newP->next = p;
		p = newP;
	}
	else
		cout << "Не добавлен" << endl;
}


int del(Item*& p, int n) 
{
	Item* previous, * current, * temp;
	if (n == p->number)
	{
		temp = p;
		p = p->next;
		delete temp;
		return n;
	}
	else {
		previous = p;
		current = p->next;
		while (current != NULL && current->number != n)
		{
			previous = current;
			current = current->next;
		}
		if (current != NULL)
		{
			temp = current;
			previous->next = current->next;
			delete (temp);
		}
	}
}
void search(Item*& p, int n) {
	Item* head = p;
	int k = 0;
	while (p != NULL) {
		if (n == p->number)
			k++;
		p = p->next;
	}
	p = head;
	if (k != 0)
	{
		cout << "Find the element " << n << "which meets " << k << "times" << endl;
	}
	else {
		cout << "Этот элемент не соответствует" << endl;
	}
}




void write_in_file(Item*& p) 
{
	Item* x = p;
	ofstream fout("file.txt");
	while (x) {

		fout << x->number << endl;
		x = x->next;
	}
	fout.close();
}
void read_from_file(Item*& p) 
{

	Item* prev = p;

	while (p != NULL)
	{
		p = p->next;


		free(prev);
		prev = p;
	}
	char line[200];
	ifstream outf("file.txt");
	if (outf.is_open())
	{
		while (!outf.eof())
		{
			outf.getline(line, 200);
			if (strlen(line))
				adding(p, atoi(line));
		}
	}
	outf.close();
	cout << "\nИнформация выведена из файла!\n\n";
}
void sum(Item*& p) 
{
	int sum = 0;
	if (p == NULL)
	{
		cout << "Список пуст" << endl;
	}
	else {
		while (p != NULL)
		{
			if (p->number < 0 && p->number<-9 && p->number>-100)
				sum = sum + (p->number);
			p = p->next;
		}
		cout << "Сумма чисел<0: " << sum << endl;
	}
}