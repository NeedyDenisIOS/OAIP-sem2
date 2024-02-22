#include "Header.h"


int main()
{
	system("chcp 1251");
	int choice, position;
	string newEl;

	STACK* stack = new STACK;
	stack->head = NULL;

	while (true)
	{
		cout << "1 - добавить элемент в стек\n";
		cout << "2 - извлечь элемент из стека\n";
		cout << "3 - вывод стека на экран\n";
		cout << "4 - Разработать функцию подсчета количества повторяющихся элементов стека.\n";
		cout << "5 - запись в файл\n";
		cout << "6 - вывод из файла\n";
		cout << "7 - очистка стека\n";
		cout << "0 - выход\n";
		cin >> choice;

		switch (choice)
		{
		case 1: {
			cout << "\n";
			cout << "Значение > "; cin >> newEl;
			AddEl(newEl, stack);
			cout << "\n";
			break;
		}

		case 2: {
			cout << TakeFromStack(stack) << endl;
			break;
		}

		case 3: {
			PrintStack(stack);
			break;
		}

		case 4: {
			Same(stack);
			break;
		}

		case 5: {
			ToFile(stack);
			break;
		}

		case 6: {
			FromFile(stack);
			break;
		}

		case 7: {
			clear(stack);
			cout << "\n\nСтек очищен!\n\n";
			break;
		}

		case 0: {
			exit(0);
			break;
		}
		}
	}
}

