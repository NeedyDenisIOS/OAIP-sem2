#include "Header.h"

void AddEl(string elem, STACK* stack)
{
	STACK* NewEl = new STACK;
	NewEl->data = elem;
	NewEl->next = stack->head;
	stack->head = NewEl;
}

string TakeFromStack(STACK* stack)
{
	if (stack->head == NULL)
	{
		cout << "Стек пуст";
		return "- 1";
	}
	else {
		STACK* intermEl = new STACK;
		string elData = stack->head->data;
		stack->head = stack->head->next;
		delete intermEl;
		return elData;
	}
}

void PrintStack(STACK* stack)
{
	STACK* sthead = stack->head;
	string elData;
	if (sthead == NULL)
		cout << "Стек пуст";
	while (sthead != NULL)
	{
		elData = sthead->data;
		cout << elData << " ";
		sthead = sthead->next;
	}
	cout << "\n";
}

void ToFile(STACK* stack)
{
	ofstream getf;
	getf.open("File13.txt");
	if (getf.is_open())
	{
		STACK* StackHead = stack->head;
		while (StackHead != NULL)
		{
			getf << StackHead->data << " ";
			StackHead = StackHead->next;
		}
		cout << "\n";
	}
	getf.close();
	cout << "Информация записана в файл!\n\n";
}

void FromFile(STACK* stack)
{
	char line[200];
	ifstream outf("File13.txt");
	if (outf.is_open())
	{
		while (!outf.eof())
		{
			outf.getline(line, 200);
			if (strlen(line))
				AddEl(line, stack);
		}
	}
	outf.close();
	cout << "\nИнформация выведена из файла!\n\n";
}

int Same(STACK* stack)
{
	STACK* e, * k;
	e = stack->head;
	int count = 0;
	string a, b;
	cout << "Повторяющиеся элементы: ";
	while (e != NULL) {
		a = e->data;
		k = e->next;
		while (k != NULL) {
			b = k->data;
			if (a == b) {
				cout << a << " ";
				count++;
				break;
			}
			k = k->next;
		}
		e = e->next;
	}
	cout << endl;
	cout << "Число повторяющихся элементов: " << count << endl;
	return 0;
}

void clear(STACK* stack)
{
	if (stack->head == NULL)
		cout << "Стек пуст";
	while (stack->head != NULL)
	{
		STACK* f = stack->head;
		stack->head = stack->head->next;
		delete f;
	}
	cout << "\n";
}
