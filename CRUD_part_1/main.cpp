#include <iostream>
#include <vector>
using namespace std;

char pilih;
int back;
int counNum;
string bookname;
string authorname;
string fullbook;
string hapus;
vector<string> bookarray;

int pilihan();
int addBook();
int showBooks();
int removeBook();
int clearDatabase();
int count();

int main() {
    pilihan();
    return 0;
}

int pilihan() {
    do {
        cout << "Selamat Datang diDatabase" << endl;
        cout << "=========================" << endl;
        cout << endl;

        cout << "a. menambahkan buku" << endl;
        cout << "b. menghapus buku" << endl;
        cout << "c. menghapus database" << endl;
        cout << "d. menghitung jumlah buku" << endl;
        cout << "e. lihat data buku" << endl;
        cout << "f. keluar" << endl;
        cout << "pilih : " << endl;
        cin >> pilih;

        switch (pilih) {
            case 'a' :
                addBook();
                break;
            case 'b' :
                removeBook();
                break;
            case 'c' :
                clearDatabase();
                break;
            case 'd' :
                count();
                break;
            case 'e' :
                showBooks();
                break;
            case 'f' :
                cout << "Terima Kasih !" << endl;
                return 0;
                break;
        }
    } while(pilih != 'f');
    return 0;
}

int addBook() {
    cout << "masukan nama buku : " << endl;
    cin >> bookname;
    cin.ignore();
    cout << "masukan nama penulis : " << endl;
    cin >> authorname;
    fullbook = bookname + " " + authorname;
    bookarray.push_back(fullbook);
    cout << "buku berhasil ditambahkan !" << endl;
    cout << "ketik 9 untuk kembali : " << endl;
    cin >> back;

    if (back == 9) {
        return pilihan();
    } else {
        return pilihan();
    }
}

int showBooks() {
    cout << "data nama buku" << endl;
    if (bookarray.empty()) {
        cout << "data buku kosong dalam database !" << endl;
    } else {
        for (int i = 0; i < bookarray.size(); i++) {
            cout << i << ". " << bookarray[i] << endl;
        }
    }
    cout << endl;

    cout << "ketik 9 untuk kembali : " << endl;
    cin >> back;

    if (back == 9) {
        return pilihan();
    } else {
        return pilihan();
    }
}

int removeBook()
{
    cout << "masukan nomor buku yang akan dihapus : " << endl;
    cin >> hapus;
    for (int i = 0; i < bookarray.size(); i++) {
        if (bookarray[i].find(hapus) != string::npos) {
            bookarray.erase(bookarray.begin() + i);
            break;
        }
    }
    cout << endl;

    cout << "ketik 9 untuk kembali : " << endl;
    cin >> back;

    if (back == 9) {
        return pilihan();
    } else {
        return pilihan();
    }
}

int clearDatabase() {
    bookarray.clear();
    cout << "database terhapus" << endl;
    cout << endl;

    cout << "ketik 9 untuk kembali : " << endl;
    cin >> back;

    if (back == 9) {
        return pilihan();
    } else {
        return pilihan();
    }
}


int count() {
    counNum = bookarray.size();
    cout << "jumlah buku : " << counNum << endl;
    cout << endl;

    cout << "ketik 9 untuk kembali : " << endl;
    cin >> back;

    if (back == 9) {
        return pilihan();
    } else {
        return pilihan();
    }
}