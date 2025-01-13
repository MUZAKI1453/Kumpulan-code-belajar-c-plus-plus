#include <algorithm>
#include <iostream>
using namespace std;

void menampilkanArray(int arr[], int size) {
    cout << "\nini  adalah nilai dari index array sebelum diurutkan : ";
    for(int i = 0; i < size; i++) {
        cout << arr[i] << ", ";
    }
}

void menampilkan_array_kecilKeTerbesar(int arr[], int size) {
    // fungsi sort digunakan untuk mengurutkan nilai dari terkecil ke terbesar
    sort(arr, arr + size);

    /* menampilkan array yang telah diurutkan dengan fungsi sort()
       namun harus menggunakan loop */
    cout << "\nini  adalah nilai dari index array setelah diurutkan : ";
    for(int i = 0; i < size; i++) {
        cout << arr[i] << ", ";
    }
}

void elemen_tebesar2(int arr[], int size) {
    int terbesar = INT_MIN, terbesarKedua = INT_MIN;

    for (int i = 0; i < size; i++) {
        if (arr[i] > terbesar) {
            terbesarKedua = terbesar;
            terbesar = arr[i];
        } else if (arr[i] > terbesarKedua && arr[i] < terbesar) {
            terbesarKedua = arr[i];
        }
    }
    cout << "\nelemen terbesar ke-2 : " << terbesarKedua << std::endl;
}

int main() {
    int jumlah_elemen_array;

    /* ini deklarasi array dengan jumlah index berdasarkan
     * input user dari variabel jumlah_elemen_array */
    int data_array[jumlah_elemen_array];

    cout << "masukan jumlah elemen array : ";
    cin >> jumlah_elemen_array;

    // meminta user untuk memasukan nilai - nilai ke dalam index array
    cout << "Masukkan " << jumlah_elemen_array << " elemen array:\n";

    // menggunakan looping untuk memasukan nilai -nilai ke dalam index array
    for(int i = 0; i < jumlah_elemen_array; i++) {
        cout << "index ke -" << i + 1 << ": ";
        cin >> data_array[i];
    }

    /* ini merupakan implementasi passing parameter
       untuk mengirimkan array dan indexnya ke fungsi */
    menampilkanArray(data_array, jumlah_elemen_array);

    /* ini merupakan implementasi fungsi sort() pengurutan
       nilai index dari array dari  terkecil ke terbesar */
    menampilkan_array_kecilKeTerbesar(data_array, jumlah_elemen_array);

    // fungsi mencari elemen tebesar ke-2
    elemen_tebesar2(data_array, jumlah_elemen_array);

    return 0;
}
