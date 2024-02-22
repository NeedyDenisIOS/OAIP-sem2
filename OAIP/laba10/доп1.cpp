#include <iostream>
#include <fstream>
using namespace std;

void dop(int size, int* arr, int tmp)
{

	ofstream file("data.txt", ios_base::app);
	for (int i = 0; i <= size; i++) {
		arr[tmp] = i;
		if (tmp == size - 1) {
			for (int j = 0; j < size; j++)
			{
				cout << arr[j];
				file << arr[j];
			}
			cout << " ";
			file << " ";
		}
		else
			dop(size, arr, tmp + 1);
	}
}


int main() {
	setlocale(LC_ALL, "rus");
			int A;
			cout << "A = ";
			cin >> A;
			int* arr = new int[A];
			if (A == 1)
			{
				cout << 0 << " ";
				cout << 1 << '\n';

			}
			else
				for (int i = 1; i <= A; i++)
				{
					arr[0] = i;
					dop(A, arr, 1);
				}
			
		}

