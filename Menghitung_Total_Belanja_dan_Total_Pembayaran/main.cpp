#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

struct Barang {
    string nama;
    int jumlah_beli;
    int harga_satuan;
    int jumlah_harga;
};

vector<Barang> barang_list;  // Menyimpan data barang secara global
string nama_pembeli;
int total_bayar = 0;
bool dataTerisi = false;  // Flag untuk mengecek apakah data sudah diinput

void menu();
void input_data();
void tampilkan_data();

int main() {
    menu();
    return 0;
}

void menu() {
    int pilihan;

    do {
        cout << "\n======================================================================\n";
        cout << "|                            SISTEM KASIR                            |\n";
        cout << "======================================================================\n";

        cout << "Menu Sistem Kasir :\n";
        cout << "1. Input Data\n";
        cout << "2. Tampilkan Data\n";
        cout << "3. Keluar\n";
        cout << "Pilih menu : ";
        cin >> pilihan;
        cin.ignore();  // Mengabaikan newline yang tertinggal setelah input angka

        switch (pilihan) {
            case 1:
                input_data();  // Memasukkan data barang
                break;
            case 2:
                tampilkan_data();  // Menampilkan data barang
                break;
            case 3:
                cout << "Terima kasih! Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid, silakan pilih kembali.\n";
                break;
        }
    } while (pilihan != 3);
}

void input_data() {
    int jumlah_barang;

    // Input Nama Pembeli
    cout << "Nama Pembeli : ";
    getline(cin, nama_pembeli);

    // Input Jumlah Barang yang Dibeli
    cout << "Jumlah Barang yang Dibeli : ";
    cin >> jumlah_barang;
    cin.ignore();  // Mengabaikan newline setelah input jumlah_barang

    // Input Data Barang
    for (int i = 0; i < jumlah_barang; i++) {
        Barang barang;

        cout << "\nMasukkan Nama Barang ke-" << (i + 1) << ": ";
        getline(cin, barang.nama);
        cout << "Masukkan Jumlah Beli     : ";
        cin >> barang.jumlah_beli;
        cout << "Masukkan Harga Satuan    : ";
        cin >> barang.harga_satuan;
        cin.ignore();  // Mengabaikan newline setelah input harga

        // Menghitung Jumlah Harga dan Menambahkannya ke Total Bayar
        barang.jumlah_harga = barang.jumlah_beli * barang.harga_satuan;
        total_bayar += barang.jumlah_harga;

        // Menyimpan data barang ke dalam vector
        barang_list.push_back(barang);
    }

    // Menandai bahwa data sudah diinput
    dataTerisi = true;
}

void tampilkan_data() {
    if (!dataTerisi) {
        cout << "Data masih kosong! Silakan input data terlebih dahulu.\n";
        return;  // Kembali ke menu tanpa memanggil menu lagi
    } else {
        // Menampilkan Data Barang
        cout << "\n====================================================================\n";
        cout << "| NO |   NAMA BARANG   | JUMLAH BELI | HARGA SATUAN | JUMLAH HARGA |\n";
        cout << "====================================================================\n";

        for (int i = 0; i < barang_list.size(); i++) {
            cout << "| " << setw(2) << (i + 1) << " | "
                 << setw(15) << barang_list[i].nama
                 << " | " << setw(11) << barang_list[i].jumlah_beli
                 << " | " << setw(11) << barang_list[i].harga_satuan
                 << " | " << setw(12) << barang_list[i].jumlah_harga
                 << " |\n";
        }

        // Menampilkan Total Pembayaran
        cout << "====================================================================\n";
        cout << "|                     TOTAL                         | " << setw(12) << total_bayar << " |\n";
        cout << "====================================================================\n";

        // Menampilkan ucapan terima kasih
        cout << "Terima kasih telah berbelanja, " << nama_pembeli << "!\n";
    }
}
