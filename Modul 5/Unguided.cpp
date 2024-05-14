#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Mahasiswa {
    string nim;
    int nilai;
    Mahasiswa* next;
};

class HashTable {
private:
    vector<Mahasiswa*> table;
    int size;

public:
    HashTable(int size) : size(size), table(size, nullptr) {}

    int hashFunction(string key) {
        int hash = 0;
        for (char c : key) {
            hash += c;
        }
        return hash % size;
    }

    void insert(string nim, int nilai) {
        Mahasiswa* newMahasiswa = new Mahasiswa();
        newMahasiswa->nim = nim;
        newMahasiswa->nilai = nilai;
        newMahasiswa->next = nullptr;

        int index = hashFunction(nim);
        if (table[index] == nullptr) {
            table[index] = newMahasiswa;
        } else {
            Mahasiswa* current = table[index];
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newMahasiswa;
        }
    }

    Mahasiswa* search(string nim) {
        int index = hashFunction(nim);
        Mahasiswa* current = table[index];
        while (current != nullptr) {
            if (current->nim == nim) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    void remove(string nim) {
        int index = hashFunction(nim);
        Mahasiswa* current = table[index];
        Mahasiswa* previous = nullptr;

        while (current != nullptr && current->nim != nim) {
            previous = current;
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Data tidak ditemukan." << endl;
            return;
        }

        if (previous == nullptr) {
            table[index] = current->next;
        } else {
            previous->next = current->next;
        }

        delete current; // Menghapus memori dari node yang dihapus
    }

    void print() {
        for (int i = 0; i < size; i++) {
            Mahasiswa* current = table[i];
            if (current != nullptr) {
                cout << "Index: " << i << endl;
                while (current != nullptr) {
                    cout << "NIM: " << current->nim << ", Nilai: " << current->nilai << endl;
                    current = current->next;
                }
            }
        }
    }

    void searchByRange(int min, int max) {
        for (int i = 0; i < size; i++) {
            Mahasiswa* current = table[i];
            while (current != nullptr) {
                if (current->nilai >= min && current->nilai <= max) {
                    cout << "NIM: " << current->nim << ", Nilai: " << current->nilai << endl;
                }
                current = current->next;
            }
        }
    }

    ~HashTable() {
        for (int i = 0; i < size; i++) {
            Mahasiswa* current = table[i];
            while (current != nullptr) {
                Mahasiswa* toDelete = current;
                current = current->next;
                delete toDelete;
            }
        }
    }
};

int main() {
    HashTable hashTable(10);

    char pilihan;
    string nim;
    int nilai;

    do {
        cout << "=== Program Hash Table ===" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Cari Data Berdasarkan NIM" << endl;
        cout << "4. Cari Data Berdasarkan Rentang Nilai" << endl;
        cout << "5. Tampilkan Data" << endl;
        cout << "6. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case '1':
                cout << "Masukkan NIM: ";
                cin >> nim;
                cout << "Masukkan Nilai: ";
                cin >> nilai;
                hashTable.insert(nim, nilai);
                break;
            case '2':
                cout << "Masukkan NIM yang ingin dihapus: ";
                cin >> nim;
                hashTable.remove(nim);
                break;
            case '3':
                cout << "Masukkan NIM yang ingin dicari: ";
                cin >> nim;
                Mahasiswa* result;
                result = hashTable.search(nim);
                if (result != nullptr) {
                    cout << "NIM: " << result->nim << ", Nilai: " << result->nilai << endl;
                } else {
                    cout << "Data tidak ditemukan." << endl;
                }
                break;
            case '4':
                cout << "Masukkan rentang nilai (min - max): ";
                int min, max;
                cin >> min >> max;
                hashTable.searchByRange(min, max);
                break;
            case '5':
                hashTable.print();
                break;
            case '6':
                cout << "Keluar dari sistem." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
                break;
        }
    } while (pilihan != '6');

    return 0;
}
