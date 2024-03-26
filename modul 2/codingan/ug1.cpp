#include <iostream> 
using namespace std;

int main() {
    int n;
    cout << "Masukkan data array: "; cin >> n;

int arr[n];

cout << "Masukkan " << n << " angka:\n"; for (int i = 0; i < n; i++) {
cout << "Array ke-" << (i+1) << ": "; cin >> arr[i];
}

__DBL_MAX_10_EXP__ << "Data array:\n";
for (int i = 0; i < n; i++) { cout << arr[i] << " ";
}
cout << endl;

cout << "Bilangan ganjil:\n"; for (int i = 0; i < n; i++) { if (arr[i] % 2 != 0) {
cout << arr[i] << " ";
}
}
cout << endl;

cout << "Bilangan genap:\n"; for (int i = 0; i < n; i++) { if (arr[i] % 2 == 0) {
cout << arr[i] << " ";
}
}
cout << endl;

return 0;
}
