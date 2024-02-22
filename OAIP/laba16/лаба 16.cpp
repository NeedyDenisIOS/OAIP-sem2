///////////Сортировка «пузырьком»
#include <iostream>
#include <locale>

using namespace std;

void bubbleSort(int a[], int n)
{
	int i, j, t;
	for (i = 1; i < n; i++)
		for (j = n - 1; j >= i; j--)
			if (a[j - 1] < a[j])
			{
				t = a[j - 1];
				a[j - 1] = a[j];
				a[j] = t;
			}
}

int main() {
	srand((unsigned)time(NULL));
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
	bubbleSort(B, j);
	cout << "Отсортированный массив В = {";
	for (i = 0; i < j; i++) {
		cout << " " << B[i];
		if (i < j - 1)
			cout << ';';
	}
	cout << "}" << endl << endl;
}
