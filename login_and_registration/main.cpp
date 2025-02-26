#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct User {
    string username;
    string password;
};

vector<User> users;

void registerUser();
void loginUser();

int main() {
    int pilihan;

    do {
        cout << "\n============ Menu ============" << endl;
        cout << "1. Registrasi " << endl;
        cout << "2. Login " << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice : ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                cout << "Terima Kasih !" << endl;
                return 0;
            default:
                cout << "Pilihan tidak ada silahkan pilih lagi." << endl;
        }
    } while (pilihan != 3);
    return 0;
}



void registerUser() {
    string username, password;
    bool userExists = false;

    cout << "\n============ Registrasi ============" << endl;
    cout << "masukan username: ";
    cin >> username;

    // mengecek apakah username sudah ada ?
    for (const auto& user : users) {
        if (user.username == username) {
            userExists = true;
            break;
        }
    }

    if (userExists) {
        cout << "USername sudah terdaftar !" << endl;
    } else {
        cout << "masukan password: ";
        cin >> password;

        // menyimpan user baru ke dalam vector
        users.push_back({username, password});
        cout << "Registrasi berhasil !" << endl;
    }
}

void loginUser() {
    string username, password;
    bool found = false;

    cout << "\n============ Registrasi ============" << endl;
    cout << "masukan username: ";
    cin >> username;
    cout << "\nmasukan password: ";
    cin >> password;

    // mengecek apakah username dan password cocok
    for (const auto& user : users) {
        if (user.username == username && user.password == password) {
            found = true;
            break;
        }
    }

    if (found) {
        cout << "login berhasil !" << endl;
    } else {
        cout << "username atau password salah !" << endl;
    }
}