#include <iostream>
using namespace std;

int main() {
    int array[] = {7, 8, 1, 3, 2, 4}; // ini merupakan array yang akan diurutkan

    // membuat variabel penghitung panjang dari array
    int n = sizeof(array) / sizeof(array[0]);

    // ini algoritma bubble sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
            }
        }
    }

    // menampilkan array yang sudah diurutkan
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }

    cout << endl;
    return 0;
}
