////*****************************************************************//Сортировка Хоара
#include <iostream>
#include <locale>

int getHoarBorder(int A[], int sm, int em)
{
	int i = sm - 1, j = em + 1;
	int brd = A[sm], buf;
	while (i < j)
	{
		while (A[--j] < brd);
		while (A[++i] > brd);
		if (i < j)
		{
			buf = A[j];
			A[j] = A[i];
			A[i] = buf;
		};
	}
	return j;
}
int* sortHoar(int A[], int sm, int em)
{
	if (sm < em)
	{
		int hb = getHoarBorder(A, sm, em);
		sortHoar(A, sm, hb);
		sortHoar(A, hb + 1, em);
	}
	return A;
};


int main() {
	srand((unsigned)time(NULL));
	using namespace std;
	setlocale(LC_CTYPE, "Russian");
	const int maxSize = 100;
	int A[maxSize], i, max, B[maxSize], j = 0, i_max = 0;
	cout << "Исходный массив A = {";
	for (i = 0; i <= (maxSize - 1); i++)
	{
		A[i] = rand() % 50;
		cout << " " << A[i];
		if (i < maxSize - 1)
			cout << ';';
	}
	cout << "}" << endl << endl;
	max = A[0];
	for (i = 1; i <= (maxSize - 1); i++)
	{
		if (A[i] > max) {
			max = A[i];
			i_max = i;
		}
	}
	cout << "Максимальный элемент массива А: " << max << endl << endl;
	cout << "Исходный массив В = {";
	for (i = i_max + 1; i < maxSize; i += 2, j++) {
		B[j] = A[i];
		cout << " " << B[j];
		if (i < i_max - 2)
			cout << ';';
	}
	cout << "}" << endl << endl;
	sortHoar(B, 0, j);
	cout << "Отсортированный массив В = {";
	for (i = 0; i < j; i++) {
		cout << " " << B[i];
		if (i < j)
			cout << ';';
	}
	cout << "}" << endl << endl;
}
