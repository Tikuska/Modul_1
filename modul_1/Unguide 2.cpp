#include <iostream>
#include <string>
using namespace std;

// Struct untuk merepresentasikan spearpart mobil
struct Spearpart {
    string nama;
    string jenis;
    double harga;
};

// Class untuk merepresentasikan mobil
class Mobil {
public:
    string merek;
    string model;
    int tahun;
    Spearpart mesin;
    Spearpart roda;

    // Metode untuk menampilkan informasi mobil beserta spearpartnya
    void tampilkanInfo() {
        cout <<"===================================================================\n";
        cout <<"NAMA :          Tegar Serli Arunzika \n";
        cout <<"Nim  :              2311102041 \n";
        cout <<"kelas:                IF-11-B \n";
        cout<<"===================================================================\n";
        cout << "Mobil " << merek << " " << model << " tahun " << tahun << endl;
        cout << "Mesin: " << mesin.nama << ", Jenis: " << mesin.jenis << ", Harga: $" << mesin.harga << endl;
        cout << "Roda: " << roda.nama << ", Jenis: " << roda.jenis << ", Harga: $" << roda.harga << endl;
    }
};

int main() {
    // Membuat objek dari class Mobil dan mengisi atribut-atributnya
    Mobil mobil;
    mobil.merek = "Nissan";
    mobil.model = "R35";
    mobil.tahun = 2020;
    mobil.mesin.nama = "RB26";
    mobil.mesin.jenis = "V6";
    mobil.mesin.harga = 5500.0;
    mobil.roda.nama = "Alloy Wheels";
    mobil.roda.jenis = "TE-37 18-inch";
    mobil.roda.harga = 800.0;

    // Menampilkan informasi mobil dan spearpartnya
    mobil.tampilkanInfo();

    return 0;
}
