#include <iostream>
using namespace std;

// menambahkan library list
#include <list>

int main() {

    // membuat variabel dengan list
    //list<string> cars;

    // membuat list, namun sudah ada datanya
    list<string> cars = {"bmw", "ford", "mercy", "mustang"};

    // looping list
    for (string car : cars) {
        cout << car << endl;
    }

    cout << endl;

    // cara mengkases list
    // 1. menggunkan .front / mengakses elemen list depan
    cout << "mengakses cars bagian depan" << endl;
    cout << cars.front() << endl;

    cout << endl;


    // 2.menggunakan .back / mengakses elemen list paling belakang
    cout << "mengakses cars bagian belakang" << endl;
    cout << cars.back() << endl;

    cout << endl;

    // mengganti elemen list
    // 1. bagian depan
    cout << "mengganti elemen list paling depan" << endl;
    cars.front() = "corolla";
    cout << cars.front() << endl;

    cout << endl;

    // 2. bagian paling belakan
    cout << "mengganti elemen list paling belakang" << endl;
    cars.back() = "ferrari";
    cout << cars.back() << endl;

    cout << endl;

    // menambahkan elemen dibagian depan
    cars.push_front("audi");
    cout << cars.front() << endl;

    // menambahkan elemen dibagian paling belakang
    cars.push_back("lamborghini");
    cout << cars.back() << endl;

    // melihat ukuran list
    cout << endl;
    cout << cars.size() << endl;

    // menghapus elemen diawal
    cars.pop_front();
    cout << cars.front() << endl;

    //menghapus elemen diakhir
    cars.pop_back();
    cout << cars.back() << endl;

    // memeriksa apakah list kosong
    cout << cars.empty() << endl;

    return 0;
}