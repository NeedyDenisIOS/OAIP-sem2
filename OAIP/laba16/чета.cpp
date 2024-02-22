#include <iostream>
#include <locale>
#include <ctime>

using namespace std;

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
	const int maxSize = 50000;
	int A[maxSize], B[maxSize], i;
	clock_t t1, t2;
	for (int n = 10000; n <= maxSize; n += 10000) {
		for (i = 0; i < n; i++) {
			A[i] = rand() % 1000;
			B[i] = A[i];
		}
		cout << "n = " << n << endl;
		cout << "Сортировка 'Пузырек'. ";
		t1 = clock();
		bubbleSort(A, maxSize);
		t2 = clock();
		cout << "Прошло " << t2 - t1 << " тактов времени" << endl;
		cout << "n = " << n << endl;
		cout << "Сортировка Хоара. ";
		t1 = clock();
		sortHoar(B, 1, maxSize);
		t2 = clock();
		cout << "Прошло " << t2 - t1 << " тактов времени" << endl;
	}
}
