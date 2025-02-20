#include <iostream>
#include <vector>
using namespace std;

int main() {
    // deklarasi vector yang akan menyimpan data suhu
    vector<int> suhu;

    // menambahkan elemen ke vector menggunakan push_back()
    suhu.push_back(22.5);
    suhu.push_back(23.12);
    suhu.push_back(23.23);

    // menampilkan elemen - elemen vector
    cout << "data suhu yang disimpan dalam vector : " << endl;
    for (size_t i = 0; i < suhu.size(); i++) {
        cout << suhu[i] << endl;
    }

    // menambahkan elemen baru ke vector
    suhu.push_back(21.34);

    // menampilkan setelah penambahan
    cout << "menampilkan suhu setelah penambahan elemen : " << endl;
    for (size_t i = 0; i < suhu.size(); i++) {
        cout << suhu[i] << endl;
    }
    return 0;
}
