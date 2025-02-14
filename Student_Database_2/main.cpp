#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <fstream>

struct Siswa {
    int id;
    std::string nim;
    std::string nama;
    int umur;
    std::string alamat;
    std::string kelas;
};

// Fungsi untuk menyimpan data ke file
void simpanDataKeFile(const std::vector<Siswa>& data) {
    std::ofstream outFile("data_siswa.txt");
    if (!outFile) {
        std::cerr << "Gagal membuka file untuk menulis data.\n";
        return;
    }

    // Menyimpan data ke dalam file
    for (const auto& siswa : data) {
        outFile << siswa.id << "\n"
                << siswa.nim << "\n"
                << siswa.nama << "\n"
                << siswa.umur << "\n"
                << siswa.alamat << "\n"
                << siswa.kelas << "\n";
    }

    outFile.close();
    std::cout << "Data telah disimpan ke file.\n";
}

// Fungsi untuk membaca data dari file
void bacaDataDariFile(std::vector<Siswa>& data) {
    std::ifstream inFile("data_siswa.txt");
    if (!inFile) {
        std::cerr << "Gagal membuka file untuk membaca data.\n";
        return;
    }

    Siswa siswa;
    while (inFile >> siswa.id) {
        inFile.ignore();  // untuk membersihkan newline setelah ID
        std::getline(inFile, siswa.nim);
        std::getline(inFile, siswa.nama);
        inFile >> siswa.umur;
        inFile.ignore();  // untuk membersihkan newline setelah umur
        std::getline(inFile, siswa.alamat);
        std::getline(inFile, siswa.kelas);

        data.push_back(siswa);
    }

    inFile.close();
    std::cout << "Data telah dibaca dari file.\n";
}

void tampilkanData(const std::vector<Siswa>& data) {
    if (data.empty()) {
        std::cerr << "Data siswa belum ada." << std::endl;
        return;
    }

    std::cout << std::left << std::setw(5) << "ID"
              << std::setw(15) << "NIM"
              << std::setw(20) << "Nama"
              << std::setw(10) << "Umur"
              << std::setw(25) << "Alamat"
              << std::setw(10) << "Kelas" << std::endl;
    std::cout << std::string(85, '-') << std::endl;

    for (const auto& siswa : data) {
        std::cout << std::setw(5) << siswa.id
                  << std::setw(15) << siswa.nim
                  << std::setw(20) << siswa.nama
                  << std::setw(10) << siswa.umur
                  << std::setw(25) << siswa.alamat
                  << std::setw(10) << siswa.kelas << std::endl;
    }
    std::cout << std::string(85, '-') << std::endl;
}

void inputData(std::vector<Siswa>& data) {
    Siswa siswa;
    siswa.id = data.size() + 1;  // ID otomatis bertambah setiap input
    std::cout << "Input data siswa ke-" << siswa.id << ":\n";
    std::cout << "NIM      : ";
    std::cin >> siswa.nim;
    std::cin.ignore();
    std::cout << "Nama     : ";
    std::getline(std::cin, siswa.nama);
    std::cout << "Umur     : ";
    std::cin >> siswa.umur;
    std::cin.ignore();
    std::cout << "Alamat   : ";
    std::getline(std::cin, siswa.alamat);
    std::cout << "Kelas    : ";
    std::getline(std::cin, siswa.kelas);
    data.push_back(siswa);
}

void editData(std::vector<Siswa>& data) {
    int id;
    std::cout << "Masukkan ID siswa yang akan diedit: ";
    std::cin >> id;

    bool ditemukan = false;
    for (auto& siswa : data) {
        if (siswa.id == id) {
            std::cout << "Data ditemukan. Edit data siswa:\n";
            std::cout << "NIM      : ";
            std::cin >> siswa.nim;
            std::cin.ignore();
            std::cout << "Nama     : ";
            std::getline(std::cin, siswa.nama);
            std::cout << "Umur     : ";
            std::cin >> siswa.umur;
            std::cin.ignore();
            std::cout << "Alamat   : ";
            std::getline(std::cin, siswa.alamat);
            std::cout << "Kelas    : ";
            std::getline(std::cin, siswa.kelas);
            ditemukan = true;
            break;
        }
    }
    if (!ditemukan) {
        std::cout << "Siswa dengan ID " << id << " tidak ditemukan.\n";
    }
}

void hapusData(std::vector<Siswa>& data) {
    int id;
    std::cout << "Masukkan ID siswa yang akan dihapus: ";
    std::cin >> id;

    // Loop untuk mencari dan menghapus siswa dengan ID tertentu
    auto it = data.begin();
    bool ditemukan = false;
    while (it != data.end()) {
        if (it->id == id) {
            it = data.erase(it);  // Hapus elemen dan dapatkan iterator ke elemen berikutnya
            std::cout << "Data siswa dengan ID " << id << " telah dihapus.\n";
            ditemukan = true;
        } else {
            ++it;  // Pindah ke elemen berikutnya jika tidak ada yang dihapus
        }
    }

    if (!ditemukan) {
        std::cout << "Siswa dengan ID " << id << " tidak ditemukan.\n";
    }
}

void cariSiswa(const std::vector<Siswa>& data) {
    std::string namaCari;
    std::cout << "Masukkan nama siswa yang ingin dicari: ";
    std::cin.ignore();
    std::getline(std::cin, namaCari);

    bool ditemukan = false;
    for (const auto& siswa : data) {
        if (siswa.nama == namaCari) {
            std::cout << "Data siswa ditemukan:\n";
            std::cout << std::setw(5) << siswa.id
                      << std::setw(15) << siswa.nim
                      << std::setw(20) << siswa.nama
                      << std::setw(10) << siswa.umur
                      << std::setw(25) << siswa.alamat
                      << std::setw(10) << siswa.kelas << std::endl;
            ditemukan = true;
            break;
        }
    }
    if (!ditemukan) {
        std::cout << "Siswa dengan nama " << namaCari << " tidak ditemukan.\n";
    }
}

int main() {
    std::vector<Siswa> data;
    int pilihan;
    int kembali;

    // Membaca data dari file saat program dimulai
    bacaDataDariFile(data);

    do {
        std::cout << std::string(35, '#') << std::endl;
        std::cout << "1. Tampilkan data siswa\n";
        std::cout << "2. Input data siswa\n";
        std::cout << "3. Edit data siswa\n";
        std::cout << "4. Hapus data siswa\n";
        std::cout << "5. Cari siswa berdasarkan nama\n";
        std::cout << "9. Exit\n";
        std::cout << "Pilih Nomor : ";
        std::cin >> pilihan;

        switch (pilihan) {
            case 1:
                tampilkanData(data);
                break;
            case 2:
                inputData(data);
                break;
            case 3:
                editData(data);
                break;
            case 4:
                hapusData(data);
                break;
            case 5:
                cariSiswa(data);
                break;
            case 9:
                // Simpan data ke file sebelum keluar
                simpanDataKeFile(data);
                std::cout << "Terima kasih, program selesai.\n";
                break;
            default:
                std::cerr << "Pilihan tidak valid, coba lagi.\n";
        }
        if (pilihan != 9) {
            std::cout << "Tekan 9 untuk kembali ke menu utama : ";
            std::cin >> kembali;
        }
    } while (pilihan != 9);

    return 0;
}