#include<iostream>	
#include <string>
#include<Windows.h>
#include <fstream>
using namespace std;

#define size 4

enum Ds
{
	MO = 1, Tu, We, Th, Fr, Sa, Su
}ride;

struct book
{
	int numb;
	string punkt;
	int day = ride;
	int timeIn;
	int timeOUT;

};

book arr[size];
int cursize = 0;
int oper;
const char FOUND[] = "1234567890";

void input();
void remove();
void output();
void search();
int check_time1(int& time);
int check_time2(int& time);
void ofile();
void ifile();

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Что вы хотите сделать?\n";
	cout << "1 - Ввод данных в структуру\n";
	cout << "2 - Удаление данных из структуры\n";
	cout << "3 - Вывод данных на экран\n";
	cout << "4 - Поиск по пункту назначения\n";
	cout << "5 - Для записи в файл\n";
	cout << "6 - Для чтения из файла\n";
	cout << "7 - Для завершения работы\n";
	cin >> oper;
	do {
		switch (oper)
		{
		case 1:  input(); break;
		case 2:  remove(); break;
		case 3:  output(); break;
		case 4:  search(); break;
		case 5:  ofile(); break;
		case 6:  ifile(); break;
		}
	} while (oper != 7);
	system("pause");
}

int check_time1(int& time)
{
	cout << "Введите время отправления в формате ЧЧММ" << endl;
	cin >> time;
	if (time > 9999)
	{
		cout << "Введены некорректные данные" << endl;
		check_time1(time);
	}
	if ((time / 100) > 23)
	{
		cout << "Введены некорректные данные" << endl;
		check_time1(time);
	}

	if ((time % 100) > 59)
	{
		cout << "Введены некорректные данные" << endl;
		check_time1(time);

	}

	return time;

}

int check_time2(int& time)
{
	cout << "Введите время прибытия в формате ЧЧММ" << endl;
	cin >> time;


	if (time > 9999)
	{
		cout << "Введены некорректные данные" << endl;
		check_time2(time);
	}
	if ((time / 100) > 23)
	{
		cout << "Введены некорректные данные" << endl;
		check_time2(time);
	}

	if ((time % 100) > 59)
	{
		cout << "Введены некорректные данные" << endl;
		check_time2(time);

	}

	return time;

}

void input()
{
	if (cursize < size)
	{
		int numb;
		string svalue;
		do
		{
			cout << "Введите номер поезда: " << endl;
			cin >> svalue;
		} while (svalue.find_first_not_of(FOUND) != string::npos);
		numb = stoi(svalue);


		arr[cursize].numb = numb;

		cout << "Введите пункт назначения: " << endl;
		cin.ignore();
		getline(cin, arr[cursize].punkt);
		cout << "Введите дни следования((1 - Понедельник-Среда, 2 - Вторник-Четверг, 3 - Среда-Пятница, 4 - Четверг-Пятница, 5 - Пятница-Воскресенье, 6 - Суббота-Воскресенье, 7 - Воскресенье)): " << endl;

		cin >> arr[cursize].day;

		int date1 = 0, date2 = 0;
		date1 = check_time1(date1);
		date2 = check_time2(date2);

		arr[cursize].timeOUT = date1;
		arr[cursize].timeIn = date2;


		cursize++;
		cout << "-------------------------------------------" << endl;
	}
	else
		cout << "Введено максимальное кол-во строк!\n";
	cout << "Cледующее действие?" << endl;
	cin >> oper;
}
void output()
{
	for (int n = 0; n < cursize; n++)
	{
		int h1, h2, m1, m2;
		h1 = arr[n].timeOUT / 100;
		m1 = arr[n].timeOUT % 100;
		h2 = arr[n].timeIn / 100;
		m2 = arr[n].timeIn % 100;


		cout << "Номер поезда: " << arr[n].numb;
		cout << endl;
		cout << "Пункт назначения : " << arr[n].punkt;
		cout << endl;
		cout << "Дни следования: ";
		switch (arr[n].day)
		{
		case MO: cout << " Понедельник-Среда" << endl;
			break;
		case Tu: cout << "Вторник-Четверг" << endl;
			break;
		case We: cout << "Среда-Пятница" << endl;
			break;
		case Th: cout << "Четверг-Пятница" << endl;
			break;
		case Fr: cout << " Пятница-Воскресенье" << endl;
			break;
		case Sa: cout << "Суббота-Воскресенье" << endl;
			break;
		case Su: cout << "Воскресенье" << endl;
			break;
		}
		cout << "Время отправления: " << h1 << ":" << m1 << endl;
		cout << "Время прибытия: " << h2 << ":" << m2 << endl;
		cout << "-------------------------------------------" << endl;
	}
	if (cursize == 0)
		cout << "Недостаточно информации для вывода!" << endl;
	cout << "Cледующее действие?" << endl;
	cin >> oper;
}
void remove()
{
	if (cursize > 0)
	{
		int d;
		cout << "Номер записи, которую нужно удалить: "; cin >> d;
		for (int de1 = (d - 1); de1 < cursize; de1++)
			arr[de1] = arr[de1 + 1];
		cursize--;
		cout << "Запись удалена" << endl;
	}
	else
		cout << "Недостаточно информации!" << endl;
	cout << "-------------------------------------------" << endl;
	cout << "Cледующее действие?" << endl;
	cin >> oper;
}
void search()
{
	string t, punkt;
	if (cursize > 0)
	{
		cout << "Введите пункт назначения: " << endl;
		cin.ignore();
		getline(cin, t);

		for (int k = 0; k < cursize; k++)
		{
			int h1, h2, m1, m2;
			h1 = arr[k].timeOUT / 100;
			m1 = arr[k].timeOUT % 100;
			h2 = arr[k].timeIn / 100;
			m2 = arr[k].timeIn % 100;
			punkt = arr[k].punkt;
			if (punkt == t)
			{
				cout << "Номер поезда: " << arr[k].numb;
				cout << endl;
				cout << "Дни следования: ";
				switch (arr[k].day)
				{
				case MO: cout << " Понедельник-Среда" << endl;
					break;
				case Tu: cout << "Вторник-Четверг" << endl;
					break;
				case We: cout << "Среда-Пятница" << endl;
					break;
				case Th: cout << "Четверг-Пятница" << endl;
					break;
				case Fr: cout << " Пятница-Воскресенье" << endl;
					break;
				case Sa: cout << "Суббота-Воскресенье" << endl;
					break;
				case Su: cout << "Воскресенье" << endl;
					break;

				}
				cout << "Время отправления: " << h1 << ":" << m1 << endl;
				cout << "Время прибытия: " << h2 << ":" << m2 << endl;

				cout << "-------------------------------------------" << endl;
			}
		}
	}
	else
		cout << "Недостаточно информации!" << endl;
	cout << "Cледующее действие?" << endl;
	cin >> oper;
}

void ofile()
{
	ofstream file1("information.txt");

	for (int i = 0; i < cursize; i++)
	{
		file1 << arr[i].numb << endl;
		file1 << arr[i].punkt << endl;
		switch (arr[i].day)
		{
		case MO: file1 << " Понедельник-Среда" << endl;
			break;
		case Tu: file1 << "Вторник-Четверг" << endl;
			break;
		case We: file1 << "Среда-Пятница" << endl;
			break;
		case Th: file1 << "Четверг-Пятница" << endl;
			break;
		case Fr: file1 << " Пятница-Воскресенье" << endl;
			break;
		case Sa: file1 << "Суббота-Воскресенье" << endl;
			break;
		case Su: file1 << "Воскресенье" << endl;
			break;

		}
		file1 << arr[i].timeIn << endl;
		file1 << arr[i].timeOUT << endl;

		file1 << "\n\n";

	}

	cout << "Данные записаны в файл" << endl;

	cout << "\n\n";
	file1.close();

	cout << "Cледующее действие?" << endl;
	cin >> oper;
}


void ifile()
{
	string strInf;
	ifstream file1("information.txt");
	while (file1)
	{
		getline(file1, strInf);
		cout << strInf << '\n';
	}

	cout << "\n\n";
	file1.close();

	cout << "Cледующее действие?" << endl;
	cin >> oper;
}