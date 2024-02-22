//Дан указатель p1 на корень непустого дерева. Написать функцию, в которой для каждого из уровней данного дерева, 
//начиная с нулевого, вывести сумму значений вершин, находящихся на этом уровне. Считать, что глубина дерева не превосходит 10.(дочерних узлов не может быть больше 10 уровней)

#include<iostream>
#include <Windows.h>

using namespace std;
struct Tree
{
	int key;
	char text[100];
	Tree* Left, * Right;
};
Tree* makeTree(Tree* Root);
Tree* list(int i, char* s);      
Tree* insertElem(Tree* Root, int key, char* s);  
Tree* search(Tree* n, int key);   
Tree* delet(Tree* Root, int key); 
void view(Tree* t, int level);   
void delAll(Tree* t);
void search2(Tree* n,int key);
bool f(Tree* t, int level);
int p1(Tree* Root, int level); 
Tree* Root = NULL; 	
int sum[10]; 

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int key, choice;
	Tree* rc; char s[10];
	bool exit = false;
	while (exit != true)
	{
		cout << "1-создание дерева\n2-добавление элемента\n3-поиск по ключу\n4-удаление элемента\n5-вывод дерева\n6-очистка дерева\n7-мое задание\n8-выход\n";
		cin >> choice;
		switch (choice)
		{
		case 1: {Root = makeTree(Root); break; }
		case 2: {
			cout << "введите ключ" << endl;
			cin >> key;
			cout << endl;
			cout << "введите слово" << endl;
			cin >> s;
			insertElem(Root, key, s); break;
		}
		case 3: {
			cout << "введите ключ" << endl;
			cin >> key;
			rc = search(Root, key);
			cout << "Слово, которое то, что было найдено, является ";
			puts(rc->text); break;
		}
		case 4: {
			cout << "Введите ключ для удаления" << endl;
			cin >> key;
			Root = delet(Root, key); break;
		}
		case 5: {
			if (Root->key >= 0)
			{
				cout << "Дерево повернуто на 90 град. влево" << endl;
				view(Root, 0);
			}
			else cout << "Дерево пусто!" << endl; break;
		}
		case 6: {
			delAll(Root); break;
		}
		case 7: {
			for (int i = 0; i < 10; i++) {
				sum[i] = 0;
			}
			int max_level = p1(Root, 0);
			for (int level = 0; level <= max_level; level++)
			{
				cout << level << " " << sum[level] << endl;
			}
			break;
		}
		case 8: {exit = true; break; }
		}

	}
}
Tree* makeTree(Tree* Root)   
{
	int key; char s[10];
	cout << "Конец входа-отрицательное число\n\n";
	if (Root == NULL)	
	{
		cout << "Введите ключ: "; cin >> key;
		cout << "Введите слово: "; cin >> s; 
		Root = list(key, s);	
	}
	while (1)               
	{
		cout << "\nВведите ключ: ";  cin >> key;
		if (key < 0) break;        
		cout << "Введите слово: ";  cin >> s;
		insertElem(Root, key, s);
	}
	return Root;
}

Tree* list(int i, char* s)     
{
	Tree* t = new Tree[sizeof(Tree)];
	t->key = i;
	for (i = 0; i < 10; i++)
		*((t->text) + i) = *(s + i);
	t->Left = t->Right = NULL;
	return t;
}

Tree* insertElem(Tree* t, int key, char* s)  
{
	Tree* Prev = t;	     
	int find = 0;       
	while (t && !find)
	{
		Prev = t;
		if (f(t, key))
		{
			return 0;
		}  
		else
			if (key < t->key) t = t->Left;
			else t = t->Right;
	}
	if (!find)              
	{
		t = list(key, s);           
		if (key < Prev->key)  
			Prev->Left = t;    
		else
			Prev->Right = t;  
	}
	return t;
}


Tree* delet(Tree* Root, int key)  
{	
	Tree* Del, * Prev_Del, * R, * Prev_R;
	Del = Root;
	Prev_Del = NULL;
	while (Del != NULL && Del->key != key)
	{
		Prev_Del = Del;
		if (Del->key > key)
			Del = Del->Left;
		else
			Del = Del->Right;
	}
	if (Del == NULL)             
	{
		puts("\nЭтот ключ не найден");
		return Root;
	}
	if (Del->Right == NULL) 
		R = Del->Left;
	else
		if (Del->Left == NULL)
			R = Del->Right;
		else
		{
			Prev_R = Del; 
			R = Del->Left;
			while (R->Right != NULL)
			{
				Prev_R = R;
				R = R->Right;
			}
			if (Prev_R == Del) 
				R->Right = Del->Right;
			else
			{
				R->Right = Del->Right;
				Prev_R->Right = R->Left;
				R->Left = Prev_R;
			}
		}
	if (Del == Root) Root = R;	
	else
		
		if (Del->key < Prev_Del->key)
			Prev_Del->Left = R; 
		else
			Prev_Del->Right = R;	
	int tmp = Del->key;
	cout << "\nУдалите элемент с помощью ключа  " << tmp << endl;
	delete Del;
	return Root;
}

Tree* search(Tree* n, int key)  
{
	Tree* rc = n;
	if (rc != NULL)
	{
		if (key < (key, n->key))
			rc = search(n->Left, key);
		else
			if (key > (key, n->key))
				rc = search(n->Right, key);
	}
	else
		cout << "такого элемента не существует\n";
	return rc;
}

void view(Tree* t, int level) 
{
	if (t)
	{
		view(t->Right, level + 1);	
		for (int i = 0; i < level; i++)
			cout << "   ";
		int tm = t->key;
		cout << tm << ' ';
		puts(t->text);
		view(t->Left, level + 1);	
	}
}

void delAll(Tree* t) 
{
	if (t != NULL)
	{
		delAll(t->Left);
		delAll(t->Right);
		delete t;
	}
}

int p1(Tree* t, int level) 
{
	if (t)
	{
		int max_level_right = 0, max_level_left = 0;
		max_level_right = p1(t->Right, level + 1);	
		max_level_left = p1(t->Left, level + 1);	
		sum[level] += t->key;
		if (max_level_left >= max_level_right) {
			return max_level_left;
		}
		else {
			return max_level_right;
		}
	}
	else {
		return (level - 1);
	}
}

bool f(Tree* t, int level)
{
	if (t)
	{
		f(t->Right, level);
		if (t->key == level)
		{
			cout << "Такой ключ уже есть! " << endl;
			return 1;
		}
		f(t->Left, level);
	}
	else return 0;
}