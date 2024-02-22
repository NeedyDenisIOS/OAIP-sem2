#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    char mass[1000];
    FILE* fileA;
    fopen_s(&fileA, "FileA.txt", "w");
    fprintf(fileA, "13 78 56 -54 68 78 90 3 13 78 90 -90 13 90 13 78 90");
    fclose(fileA);

    FILE* fileB;
    fopen_s(&fileB, "FileB.txt", "w");
    fopen_s(&fileA, "FileA.txt", "r");
    fgets(mass, sizeof(mass), fileA);

    string mass2;
    int j = 0;
    int index = NULL;

    int* massiv = new int[1000];
    string number;

    for (int i = 0; i < strlen(mass); i++)
    {
        if (mass[i] != ' ')
        {
            number += mass[i];
        }
        else
        {
            massiv[j] = stoi(number);
            j++;
            number.clear();
        }
    }
    sort(massiv, massiv + j);
    for (int i = 0; i < j; i++)
    {
        for (int h = i + 1; h < j - 1; h++)
        {
            if (massiv[i] == massiv[h] && index != massiv[i])
            {
                index = massiv[i];
                mass2 += to_string(massiv[i]);
                mass2 += ' ';
            }
        }
    }
    fwrite(mass2.c_str(), mass2.size(), 1, fileB);
}