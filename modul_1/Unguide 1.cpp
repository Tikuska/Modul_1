#include <iostream>
using namespace std;

// Fungsi untuk menghitung luas persegi
double hitungLuasPersegi(double sisi) {
    return sisi * sisi;
}

// Fungsi untuk menghitung keliling lingkaran
double hitungKelilingLingkaran(double jariJari) {
    const double PI = 3.14159;
    return 2 * PI * jariJari;
}

int main() {
    double sisiPersegi = 5.0;
    double jariJariLingkaran = 3.0;

    cout << "Luas persegi dengan sisi " << sisiPersegi << " adalah " << hitungLuasPersegi(sisiPersegi) << endl;
    cout << "Keliling lingkaran dengan jari-jari " << jariJariLingkaran << " adalah " << hitungKelilingLingkaran(jariJariLingkaran) << endl;

    return 0;
}