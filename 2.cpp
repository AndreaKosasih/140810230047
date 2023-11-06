#include <iostream>
using namespace std;

const int MAX_ROWS = 3;
const int MAX_COLS = 3;

// Fungsi untuk menginput matriks
void inputMatriks(int mat[MAX_ROWS][MAX_COLS], int &rows, int &cols) {
    std::cout << "Masukkan jumlah baris: ";
    cin >> rows;
    std::cout << "Masukkan jumlah kolom: ";
    cin >> cols;

    std::cout << "Masukkan elemen-elemen matriks:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> mat[i][j];
        }
    }
}

// Fungsi untuk mencetak matriks
void cetakMatriks(int mat[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << mat[i][j] << " ";
        }
        std::cout << endl;
    }
}

// Fungsi untuk menambahkan dua matriks
void tambahMatriks(int matriks1[MAX_ROWS][MAX_COLS], int matriks2[MAX_ROWS][MAX_COLS], int hasil[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            hasil[i][j] = matriks1[i][j] + matriks2[i][j];
        }
    }
}

// Fungsi untuk mengalikan dua matriks
void perkalianMatriks(int matriks1[MAX_ROWS][MAX_COLS], int matriks2[MAX_ROWS][MAX_COLS], int hasil[MAX_ROWS][MAX_COLS], int rows1, int cols1, int rows2, int cols2) {
    if (cols1 != rows2) {
        std::cout << "Perkalian matriks tidak dapat dilakukan karena jumlah kolom matriks pertama tidak sama dengan jumlah baris matriks kedua." << endl;
        return;
    }

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            hasil[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                hasil[i][j] += matriks1[i][k] * matriks2[k][j];
            }
        }
    }
}

// Fungsi untuk mentransposisi matriks
void transposeMatriks(int matriks[MAX_ROWS][MAX_COLS], int transposisi[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposisi[j][i] = matriks[i][j];
        }
    }
}

// Fungsi untuk mencari jumlah dari setiap baris dan kolom matriks
void cariJumlahBaris(int mat[MAX_ROWS][MAX_COLS], int rows, int cols, int hasilBaris[MAX_ROWS]) {
    for (int i = 0; i < rows; i++) {
        hasilBaris[i] = 0;
        for (int j = 0; j < cols; j++) {
            hasilBaris[i] += mat[i][j];
        }
    }
}

void cariJumlahKolom(int mat[MAX_ROWS][MAX_COLS], int rows, int cols, int hasilKolom[MAX_COLS]) {
    for (int j = 0; j < cols; j++) {
        hasilKolom[j] = 0;
        for (int i = 0; i < rows; i++) {
            hasilKolom[j] += mat[i][j];
        }
    }
}

// Fungsi untuk mencetak larik
void cetakLarik(int larik[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << larik[i] << " ";
    }
    std::cout << endl;
}

void menu() {
    std::cout << "1. Penjumlahan" << endl;
    std::cout << "2. Perkalian" << endl;
    std::cout << "3. Transpose" << endl;
    std::cout << "4. Jumlah baris dan kolom" << endl;
    std::cout << "5. Selesai" << endl << endl;
}

int main() {
    int matriks1[MAX_ROWS][MAX_COLS];
    int matriks2[MAX_ROWS][MAX_COLS];
    int hasil[MAX_ROWS][MAX_COLS];
    int transposisi1[MAX_COLS][MAX_COLS];
    int transposisi2[MAX_COLS][MAX_COLS];
    int jumlahBaris1[MAX_ROWS];
    int jumlahKolom1[MAX_COLS];
    int jumlahBaris2[MAX_ROWS];
    int jumlahKolom2[MAX_COLS];
    int jBaris1, jKolom1, jBaris2, jKolom2;

    std::cout << "Matriks pertama:" << endl;
    inputMatriks(matriks1, jBaris1, jKolom1);
    cetakMatriks(matriks1, jBaris1, jKolom1);

    std::cout << "Matriks kedua:" << endl;
    inputMatriks(matriks2, jBaris2, jKolom2);
    cetakMatriks(matriks2, jBaris1, jKolom1);

    bool oke = true; 
    do {
        menu();
        int opsi;
        cin >> opsi;
        switch (opsi) {
            case 1:
                if (jBaris1 == jBaris2 && jKolom1 == jKolom2) {
                    tambahMatriks(matriks1, matriks2, hasil, jBaris1, jKolom1);
                    std::cout << "Hasil penjumlahan matriks:" << endl;
                    cetakMatriks(hasil, jBaris1, jKolom1);
                } else {
                    std::cout << "Penjumlahan matriks tidak dapat dilakukan karena matriks tidak memiliki dimensi yang sama." << endl;
                }
                break;

            case 2:
                if (jKolom1 == jBaris2) {
                    perkalianMatriks(matriks1, matriks2, hasil, jBaris1, jKolom1, jBaris2, jKolom2);
                    std::cout << "Hasil perkalian matriks:" << endl;
                    cetakMatriks(hasil, jBaris1, jKolom2);
                } else {
                    std::cout << "Perkalian matriks tidak dapat dilakukan karena jumlah kolom matriks pertama tidak sama dengan jumlah baris matriks kedua." << endl;
                }
                break;

            case 3:
                std::cout << "Transpose matriks 1:" << endl;
                transposeMatriks(matriks1, transposisi1, jBaris1, jKolom1);
                cetakMatriks(transposisi1, jKolom1, jBaris1);
                std::cout << endl;

                std::cout << "Transpose matriks 2:" << endl;
                transposeMatriks(matriks2, transposisi2, jBaris2, jKolom2);
                cetakMatriks(transposisi2, jKolom2, jBaris2);
                break;

            case 4:
                std::cout << "MATRIKS 1" << endl;
                cariJumlahBaris(matriks1, jBaris1, jKolom1, jumlahBaris1);
                std::cout << "Jumlah dari setiap baris:" << endl;
                cetakLarik(jumlahBaris1, jBaris1);

                cariJumlahKolom(matriks1, jBaris1, jKolom1, jumlahKolom1);
                std::cout << "Jumlah dari setiap kolom:" << endl;
                cetakLarik(jumlahKolom1, jKolom1);

                std::cout << "MATRIKS 2" << endl;
                cariJumlahBaris(matriks2, jBaris2, jKolom2, jumlahBaris2);
                std::cout << "Jumlah dari setiap baris:" << endl;
                cetakLarik(jumlahBaris2, jBaris2);

                cariJumlahKolom(matriks2, jBaris2, jKolom2, jumlahKolom2);
                std::cout << "Jumlah dari setiap kolom:" << endl;
                cetakLarik(jumlahKolom2, jKolom2);
                break;

            case 5:
                oke = false; 
                break;

            default:
                std::cout << "Input tidak valid. Silakan coba lagi." << endl;
                break;
        }
    } while (oke);

    std::cout << "Program selesai" << endl;
    return 0;
}
