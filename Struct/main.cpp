#include <iostream>
using namespace std;

struct Buku {
    string judul;
    string pengarang;
    float harga;
};

int main() {
    // membuat objek struct buku
    Buku buku1;

    // mengisi nilai anggota dari buku1
    buku1.judul = "Pemogramman c++";
    buku1.pengarang = "Arif";
    buku1.harga = 50000;

    // menampilkan informasi buku 1
    cout << "Judul : " << buku1.judul << endl;
    cout << "Pengarang : " << buku1.pengarang << endl;
    cout << "Harga : Rp." << buku1.harga << endl;
    return 0;
}
