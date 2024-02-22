#include <iostream>
#include <fstream>

using namespace std;

void file(char str[100], char new_str[100], int& kol1, int& kol2, int& kol3)
{
	int i = 0;

	ofstream write("File.txt");
	write << str << endl;
	write.close();

	ifstream read("File.txt");
	read.seekg(0, ios_base::end);

	int sz;
	sz = read.tellg();

	read.seekg(0);
	read.getline(new_str, sz);

	char a;

	for (i = 0; i <= sz; i++)
	{
		read.seekg(i);
		read.get(a);

		if (a == '(' || a == ')')

			kol1++;

		if (a == '{' || a == '}')

			kol2++;

		if (a == '[' || a == ']')

			kol3++;
	}

	read.close();
}

int main()
{
	setlocale(LC_ALL, "Russian");

	char str[40], new_str[40];
	int kol1 = 0, kol2 = 0, kol3 = 0;

	cout << "Введите строку, состоящую из цифр и скобок: \n";

	gets_s(str);
	file(str, new_str, kol1, kol2, kol3);


	cout << "Прочитанная строка: " << new_str << endl;
	cout << "Количество скобок вида () - " << kol1 << endl;
	cout << "Количество скобок вида {} - " << kol2 << endl;
	cout << "Количество скобок вида [] - " << kol3 << endl;
}
