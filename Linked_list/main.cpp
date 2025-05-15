#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Tambah di belakang
void tambahBelakang(Node*& head, int nilai) {
    Node* baru = new Node{nilai, nullptr};
    if (head == nullptr) {
        head = baru;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = baru;
    }
}

// Tambah di depan
void tambahDepan(Node*& head, int nilai) {
    Node* baru = new Node{nilai, head};
    head = baru;
}

// Tambah di posisi tertentu
void tambahDiPosisi(Node*& head, int nilai, int posisi) {
    Node* baru = new Node{nilai, nullptr};

    if (posisi == 0 || head == nullptr) {
        baru->next = head;
        head = baru;
        return;
    }

    Node* temp = head;
    int index = 0;

    while (temp != nullptr && index < posisi - 1) {
        temp = temp->next;
        index++;
    }

    if (temp == nullptr) {
        cout << "❌ Posisi melebihi panjang linked list. Node tidak ditambahkan." << endl;
        delete baru;
        return;
    }

    baru->next = temp->next;
    temp->next = baru;
}

// Tampilkan isi linked list
void tampilkan(Node* head) {
    if (head == nullptr) {
        cout << "⚠️  Linked list kosong." << endl;
        return;
    }

    cout << "Isi Linked List: ";
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Hapus node dengan nilai tertentu
void hapusNode(Node*& head, int nilai) {
    if (head == nullptr) return;

    if (head->data == nilai) {
        Node* hapus = head;
        head = head->next;
        delete hapus;
        cout << "✔️  Node dengan nilai " << nilai << " berhasil dihapus." << endl;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != nilai) {
        temp = temp->next;
    }

    if (temp->next != nullptr) {
        Node* hapus = temp->next;
        temp->next = hapus->next;
        delete hapus;
        cout << "✔️  Node dengan nilai " << nilai << " berhasil dihapus." << endl;
    } else {
        cout << "❌ Node dengan nilai " << nilai << " tidak ditemukan." << endl;
    }
}

// Cari nilai dalam linked list
void cari(Node* head, int nilai) {
    int posisi = 0;
    while (head != nullptr) {
        if (head->data == nilai) {
            cout << "✔️  Nilai " << nilai << " ditemukan di posisi ke-" << posisi << "." << endl;
            return;
        }
        head = head->next;
        posisi++;
    }
    cout << "❌ Nilai " << nilai << " tidak ditemukan." << endl;
}

// Hapus semua node
void hapusSemua(Node*& head) {
    while (head != nullptr) {
        Node* hapus = head;
        head = head->next;
        delete hapus;
    }
}

int main() {
    Node* head = nullptr;

    // Contoh penggunaan
    tambahBelakang(head, 10);
    tambahBelakang(head, 20);
    tambahBelakang(head, 30);
    tampilkan(head);

    tambahDepan(head, 5);
    tampilkan(head);

    tambahDiPosisi(head, 99, 2); // posisi ke-2
    tampilkan(head);

    tambahDiPosisi(head, 100, 0); // posisi ke-0 (depan)
    tampilkan(head);

    tambahDiPosisi(head, 88, 10); // melebihi panjang
    tampilkan(head);

    cari(head, 20);
    cari(head, 77);

    hapusNode(head, 20);
    tampilkan(head);

    hapusNode(head, 77); // tidak ada
    tampilkan(head);

    hapusSemua(head);
    tampilkan(head);

    return 0;
}
