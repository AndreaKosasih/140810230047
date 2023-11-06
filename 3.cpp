#include <iostream>
#include <cmath>
using namespace std;

const int MAX_DATA = 100;

// Fungsi untuk menghitung rata-rata
double hitungRataRata(int data[], int n) {
    double total = 0.0;
    for (int i = 0; i < n; i++) {
        total += data[i];
    }
    return total / n;
}

// Fungsi untuk menghitung standar deviasi
double hitungStandarDeviasi(int data[], int n) {
    double rataRata = hitungRataRata(data, n);
    double totalSelisihKuadrat = 0.0;

    for (int i = 0; i < n; i++) {
        double selisih = data[i] - rataRata;
        totalSelisihKuadrat += selisih * selisih;
    }

    double standarDeviasi = sqrt(totalSelisihKuadrat / n);
    return standarDeviasi;
}

int main() {
    int n;
    int data[MAX_DATA];

    cout << "Masukkan jumlah data: "; cin >> n;

    cout << "Masukkan data:\n";
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    
    double stdDev = hitungStandarDeviasi(data, n);
    cout << "Standar Deviasi: " << stdDev << endl;
    return 0;
}
