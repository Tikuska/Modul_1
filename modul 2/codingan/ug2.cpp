#include <iostream>
using namespace std; int main() {
    int x, y, z;
    cout << "Masukkan ukuran array tiga dimensi (x y z): "; 
    cin >> x >> y >> z;
    
    int arr[x][y][z];
    cout << "Masukkan elemen-elemen array:\n"; 
    for (int i = 0; i < x; i++) 
    {
        for (int j = 0; j < y; j++) { for (int k = 0; k < z; k++) {
            cout << "Array[" << i << "][" << j << "][" << k << "]:";
            cin >> arr[i][j][k];
            }
        }
    }
    cout << "\nData array:\n"; 
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) { 
            for (int k = 0; k < z; k++) {
                cout << "Array[" << i << "][" << j << "][" << k << "]: "
                << arr[i][j][k] << endl;
                }
            }
        }
        cout << endl; return 0;
}
