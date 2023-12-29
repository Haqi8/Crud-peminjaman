#include <iostream>
#include <cstring>

using namespace std;

struct AlatKemah {
    char nama[100];
    int hargaPerHari;
};

struct Pelanggan {
    char nama[50];
    char nomorTelepon[15];
    AlatKemah *alatPinjaman;
    int durasiPinjam;
    int hargaLama;
};

void tampilkanHeaderAlatKemah() {
    cout << "\nNo\tNama Alat Kemah\t\tHarga Per Hari\n";
    cout << "===\t===============================\t===============\n";
}

void tampilkanAlatKemah(AlatKemah *alat, int index) {
    cout << index + 1 << "\t" << alat->nama << "\t\t\t" << alat->hargaPerHari << endl;
}

void pinjamAlatKemah(Pelanggan *pelanggan, AlatKemah *alat, int jumlahAlat) {
    cout << "\nMasukkan nama pelanggan: ";
    cin.ignore();
    cin.getline(pelanggan->nama, sizeof(pelanggan->nama));

    cout << "Masukkan nomor telepon pelanggan: ";
    cin >> pelanggan->nomorTelepon;

    cout << "Masukkan durasi penyewaan (dalam hari): ";
    cin >> pelanggan->durasiPinjam;

    tampilkanHeaderAlatKemah();

    for (int i = 0; i < jumlahAlat; ++i) {
        tampilkanAlatKemah(&alat[i], i);
    }

    int nomorAlat;
    cout << "\nPilih nomor alat kemah yang ingin dipinjam: ";
    cin >> nomorAlat;

    if (nomorAlat > 0 && nomorAlat <= jumlahAlat) {
        pelanggan->alatPinjaman = &alat[nomorAlat - 1];
        pelanggan->hargaLama = pelanggan->durasiPinjam * pelanggan->alatPinjaman->hargaPerHari;
        cout << "Alat kemah berhasil dipinjam.\n\n\n";
    } else {
        cout << "Nomor alat kemah tidak valid.\n";
    }
}

void tampilkanInformasi(Pelanggan *pelanggan) {
    int totalBiaya = pelanggan->durasiPinjam * pelanggan->alatPinjaman->hargaPerHari;

    cout << "\n\n=====================";
    cout << "\nInformasi Peminjaman:\n";
    cout << "=====================\n";
    cout << "Nama Pelanggan: " << pelanggan->nama << endl;
    cout << "Nomor Telepon: " << pelanggan->nomorTelepon << endl;
    cout << "Alat Kemah yang Dipinjam: " << pelanggan->alatPinjaman->nama << endl;
    cout << "Durasi Pinjam: " << pelanggan->durasiPinjam << " hari\n";
    cout << "Harga Lama Penyewaan: " << pelanggan->hargaLama << " Rupiah\n";
    cout << "Harga Per Hari: " << pelanggan->alatPinjaman->hargaPerHari << " Rupiah\n";
    cout << "Total Biaya: " << totalBiaya << " Rupiah\n";
}

int main() {
    const int jumlahAlat = 3;

    AlatKemah alat[jumlahAlat] = {
        {"Tenda", 5000},
        {"Sleeping Bag", 7000},
        {"Kompor Portable", 6000}
    };

    Pelanggan pelanggan;

    pinjamAlatKemah(&pelanggan, alat, jumlahAlat);

    tampilkanHeaderAlatKemah();
    for (int i = 0; i < jumlahAlat; ++i) {
        tampilkanAlatKemah(&alat[i], i);
    }

    tampilkanInformasi(&pelanggan);

    return 0;
}
