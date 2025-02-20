#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {

    // membuka file untuk menulis (akan menimpa file yang ada)
    // mode append agar tidak menimpa data yang ada
    ofstream outputFile("C:\\Users\\PC\\Documents\\data_suhu.txt", ios::app);

    if (!outputFile) {
        cerr << "File gagal dibuka untuk menulis ! " << endl;
        return 1;
    }

    // menulis data ke file
    outputFile << endl;
    outputFile << "21 30.5" << endl;
    outputFile << "22 28.9" << endl;

    // menutup kembali file setelah ditulis
    outputFile.close();

    cout << "Data berhasil ditulis ke file" << endl;
    return 0;
}
