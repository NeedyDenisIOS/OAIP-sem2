#include <iostream>
#include <fstream>
#include <cctype> 
#include <string>
using namespace std;

void copyLinesStartingWithDigits(const string& inputFile, const string& outputFile) {
    ifstream fin(inputFile); 
    ofstream fout(outputFile); 

    if (!fin || !fout) {
        cerr << "Error opening files." << endl;
        return;
    }

    string line;
    while (getline(fin, line)) {
        if (isdigit(line[0])) {
            fout << line << endl;
        }
    }

    cout << "Линии успешно скопированы из " << inputFile << " в " << outputFile << endl;

    fin.close();
    fout.close();
}

int main() {
    setlocale(LC_ALL, "Russian");
    string inputFile = "F1.txt";
    string outputFile = "F2.txt";

    copyLinesStartingWithDigits(inputFile, outputFile);

    return 0;
}
