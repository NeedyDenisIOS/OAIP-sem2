#include <iostream>
#include <fstream>
#include <string>
#include <locale>
#include <windows.h>

int main() {
    setlocale (LC_ALL,".1251");
    SetConsoleCP(1251);
    FILE* fileF1, * fileF2;
    char str[50];
    errno_t err;

    // ------
    fopen_s(&fileF1, "F1.txt", "w");
    if (fileF1 == NULL) {
        printf("Ошибка открытия файла F1\n");
        return EXIT_FAILURE;
    }

    // -------
    for (int i = 0; i < 6; ++i) {
        printf("Введите строку %d: ", i + 1);
        gets_s(str);
        fputs(str, fileF1);
        fputs("\n", fileF1);
    }

    // -------
    fclose(fileF1);

    // -----------
    err = fopen_s(&fileF1, "F1.txt", "r");
    if (err != NULL) {
        printf("Ошибка открытия файла F1 для чтения\n");
        return EXIT_FAILURE;
    }

    // ---------
    fopen_s(&fileF2, "F2.txt", "w");
    if (fileF2 == NULL) {
        printf("Ошибка открытия файла F2\n");
        fclose(fileF1);
        return EXIT_FAILURE;
    }

    printf("Считаны строки и скопированы в F2:\n");

    //---------
    while (fgets(str, sizeof(str), fileF1) != NULL) {
        if (str[0] == 'А') {
            printf("%s", str);
            fputs(str, fileF2);
        }
    }

    // ---------
    fclose(fileF1);
    fclose(fileF2);

    return 0;
}
