#include <iostream>
#include <map>
#include <string>
using namespace std;

// Struct untuk merepresentasikan informasi motor
struct Motor {
    string merek;
    string model;
    int tahun;
};

int main() {
    // Membuat map dengan key string (nama teman) dan value Motor (informasi motor)
    map<string, Motor> temanMotor;

    // Menambahkan data teman-teman dan informasi motor mereka ke dalam map
    temanMotor["Tegar"] = {"Honda", "Vario", 2019};
    temanMotor["Faiq"] = {"Yamaha", "Aerox", 2016};
    temanMotor["Burhan"] = {"Kawasaki", "zx-25RR", 2023};

    // Menampilkan informasi motor teman-teman
    for (const auto& pair : temanMotor) {
        cout << pair.first << " memiliki motor " << pair.second.merek << " " << pair.second.model << " tahun " << pair.second.tahun << endl;
    }

    return 0;
}