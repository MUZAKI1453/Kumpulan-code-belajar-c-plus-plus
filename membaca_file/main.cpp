#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {

    // membuka file untuk membaca file
    ifstream inputFile("C:\\Users\\PC\\Documents\\data_suhu.txt");

    if (!inputFile) {
        cerr << "file gagal dibuka ! " << endl;
        return 1;
    }

    // blok untuk membaca file baris per baris
    string line;
    while (getline(inputFile, line)) {
        cout << line << endl;
    }

    // menutup kembali file
    inputFile.close();
    return 0;
}
