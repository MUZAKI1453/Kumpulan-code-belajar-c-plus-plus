#include <iostream>
using namespace std;

// include library stack
#include <stack>

int main() {
    // deklarasi variabel dari stack, tidak bisa menambahkan elemen saat deklarasi
    stack<string> cars;

    // menambahkan elemen
    cars.push("bmw");
    cars.push("ferrari");
    cars.push("audi");
    cars.push("toyota");

    // stack hanya bisa diakses dari yg paling atas / yg paling terakir ditambah
    cout << cars.top() << endl;

    // menghapus stack
    cars.pop();
    cout << cars.top() << endl;

    // mengubah elemen
    cars.top() = "tesla";
    cout << cars.top() << endl;

    // mendapatkan ukuran dari stack
    cout << cars.size() << endl;

    // memeriksa apakah stack itu kosong
    cout <<cars.empty() << endl;
}