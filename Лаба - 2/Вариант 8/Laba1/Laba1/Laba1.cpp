#include <iostream>
#include <fstream>

using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void rearrangeFile(const string& filename) {

    ifstream inputFile(filename);
    if (!inputFile) {
        cerr << "Не удалось открыть файл " << filename << " для чтения" << endl;
        return;
    }

    int numArray[1000]; 
    int numCount = 0; 

    int num;
    while (inputFile >> num) {
        numArray[numCount++] = num;
    }

    int start = 0;
    int end = numCount - 1;
    while (start < end) {
        swap(numArray[start], numArray[end]);
        start++;
        end--;
    }

    inputFile.close();

    ofstream outputFile(filename);
    if (!outputFile) {
        cerr << "Не удалось открыть файл " << filename << " для записи" << endl;
        return;
    }

    for (int i = 0; i < numCount; ++i) {
        outputFile << numArray[i] << " ";
    }

    outputFile.close();

    cout << "Перестановка чисел в файле успешно выполнена." << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    const string filename = "numbers.txt"; 

    rearrangeFile(filename); 

    return 0;
}
