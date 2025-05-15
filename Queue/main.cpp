#include <iostream>
using namespace std;

// include library Queue
#include <queue>

int main() {
    queue<string> cars;

    // menambahkan elemen pada queue
    cars.push("toyota");
    cars.push("xenia");
    cars.push("mazda");
    cars.push("lexus");

    // akses queue dipaling depan
    cout << cars.front() << endl;

    // akses queue dipaling belakang
    cout << cars.back() << endl;

    // melihat size queue
    cout << cars.size() << endl;

    // merubah elemen depan
    cars.front() = "lambo";
    cout << cars.front() << endl;

    // merubah elemen paling belakang
    cars.back() = "corrolla";
    cout << cars.back() << endl;

    // menghapus elemen
    cars.pop();
    cout << cars.front() << endl;

    // memeriksa apakah queue kosong
    cout << cars.empty() << endl;
}