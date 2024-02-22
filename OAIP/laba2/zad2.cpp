#define _CRT_SECURE_NO_WARNINGS  fopen

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <string>
#include <stdlib.h>
using namespace std;

void addTheDataFileB(int size, int* a);

int main()
{
	setlocale(LC_ALL, "rus");
	int l = 7;
	int* a = new int[l];
	FILE* FILEA;

	int number,numI = 0;
	bool isRepeat = false;

	if ((FILEA = fopen("f.txt", "r")) != NULL)
	{
		for (int i = 0, j = 0; i < l; i++)
		{
			isRepeat = true;

			fscanf(FILEA, "%d", &number);

			for (int j = 0; j <= numI; j++)
			{
				if (a[j] == number)
				{
					isRepeat = true;
					break;
				}
				else
				{
					isRepeat = false;
				}
			}

			if (!isRepeat)
			{
				a[numI++] = number;
				cout << a[numI - 1] << "\t";
			}
		}
		cout  << endl;

		addTheDataFileB(numI, a);

		fclose(FILEA);

	}

}

void addTheDataFileB(int size, int* a)
{
	FILE* FILEB;
	if ((FILEB = fopen("g.txt", "w")) != NULL)
	{
		for (int i = 0; i < size; i++)
		{
			fprintf(FILEB, "%d\t", a[i]);
		}
	}
}