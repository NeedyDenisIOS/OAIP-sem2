#include <iostream>
#include<fstream>

const int n = 1000;

using namespace std;

int main()
{
	ifstream fin("File1.txt");
	ofstream fout("File2.txt");

	char a[n];
	int k;
	int d, max, c, imax;

	while (fin.getline(a, n))
	{
		k = 0;

		for (int i = 0; i < strlen(a); i++)
		{
			if (a[i] == ' ')
				k++;
		}

		if (k + 1 > 2)
		{
			for (int j = 0; j < strlen(a); j++)

				fout << a[j];
			fout << endl;

			c = 0;
			imax = 0;
			max = 0;

			for (int ind = 0; ind < strlen(a);)
			{
				d = 0;

				for (; a[ind] != ' ' && ind < strlen(a); ind++)
				{
					if (a[ind] == 'a' || a[ind] == 'o' || a[ind] == 'u' || a[ind] == 'i' || a[ind] == 'e' || a[ind] == 'y' || a[ind] == 'A' || a[ind] == 'O' || a[ind] == 'U' || a[ind] == 'I' || a[ind] == 'E' || a[ind] == 'Y')
						d++;
				}

				c++;

				if (d > max)
				{
					max = d;
					imax = c;
				}
				ind++;

			}

			fout << imax << endl;
		}
	}

	fin.close();
	fout.close();

	system("pause");

	return 0;
}