#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> menggabungkan(vector<int> array1, vector<int> array2) {
    vector<int> gabungan = array1;
    gabungan.insert(gabungan.end(), array2.begin(), array2.end());

    cout << "\nini menggabungkan 2 array : ";
    // Menampilkan hasil
    for (int i = 0; i < gabungan.size(); ++i) {
        cout << gabungan[i] << " ";
    }
    return gabungan;
}

vector<int> menampilkan_array_kecilKeTerbesar(vector<int> &gabungan) {
    ranges::sort(gabungan.begin(), gabungan.end());

    cout << "\nini  adalah nilai dari index array setelah diurutkan : ";
    for(int i : gabungan) {
        cout << i << ", ";
    }
}

int main (){
    vector<int> array1 = {3, 1, 4};
    vector<int> array2 = {6, 2, 5};

    vector<int> gabungan = menggabungkan(array1, array2);

    menampilkan_array_kecilKeTerbesar(gabungan);
    return 0;
}