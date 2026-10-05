#include <iostream>
#include <string>

using namespace std;

class Mahasiswa {
private:
    string nama;
    string nim;
    float nilaiTugas;
    float nilaiUTP;
    float nilaiUAP;

public:
    Mahasiswa(string nama = "", string nim = "", float tugas = 0, float utp = 0, float uap = 0) {
        this->nama = nama;
        this->nim = nim;
        this->nilaiTugas = tugas;
        this->nilaiUTP = utp;
        this->nilaiUAP = uap;
    }

    float hitungNilaiAkhir(float bobotTugas, float bobotUTP, float bobotUAP) {
        return (nilaiTugas * bobotTugas) + (nilaiUTP * bobotUTP) + (nilaiUAP * bobotUAP);
    }

    void updateNilaiTugas(float nilaiBaru) {
        if (nilaiBaru >= 0 && nilaiBaru <= 100) {
            this->nilaiTugas = nilaiBaru;
            cout << "[BERHASIL]: Nilai tugas " << nama << " berhasil diperbarui!\n";
        } else {
            cout << "[GAGAL]: Nilai harus berada dalam rentang 0 - 100!\n";
        }
    }

    void tampilkanProfil() {
        cout << "NIM: " << nim << " | Nama: " << nama
             << " | Tugas: " << nilaiTugas
             << " | UTP: " << nilaiUTP
             << " | UAP: " << nilaiUAP << endl;
    }

    string getNim() { return nim; }
    string getNama() { return nama; }
};

void cetakWatermark() {
    cout << "========================================" << endl;
    cout << "                KELOMPOK 45             " << endl;
    cout << "========================================" << endl;
}

string tampilkanHeader() {
    cout << "\n========================================" << endl;
    cout << "    SISTEM AKADEMIK KELULUSAN MAHASISWA " << endl;
    cout << "========================================" << endl;
    return "2025/2026";
}

void tampilkanStatus(string pesan) {
    cout << "\n>>> " << pesan << " <<<\n";
}

int main() {
    cetakWatermark();

    string tahunAjaran = tampilkanHeader();
    cout << "Tahun Akademik: " << tahunAjaran << endl;

    const int JUMLAH_MAHASISWA = 3;
    Mahasiswa daftarMahasiswa[JUMLAH_MAHASISWA] = {
        Mahasiswa("Budi Santoso", "211201230001", 80, 75, 85),
        Mahasiswa("Siti Rahma", "211201230002", 90, 85, 95),
        Mahasiswa("Ahmad Rizky", "211201230003", 50, 60, 55)
    };

    int pilihan;
    char lanjut = 'y';

    while (lanjut == 'y' || lanjut == 'Y') {
        cout << "\n--- DAFTAR MAHASISWA PRAKTIKUM ---" << endl;
        for (int i = 0; i < JUMLAH_MAHASISWA; i++) {
            cout << i + 1 << ". ";
            daftarMahasiswa[i].tampilkanProfil();
        }

        cout << "\nMENU UTAMA:\n";
        cout << "1. Cek Kelulusan Mahasiswa\n";
        cout << "2. Update Nilai Tugas Mahasiswa\n";
        cout << "Pilih Menu (1/2): ";
        cin >> pilihan;

        if (pilihan == 1) {
            int idx;
            cout << "Pilih nomor mahasiswa (1-" << JUMLAH_MAHASISWA << "): ";
            cin >> idx;

            if (idx >= 1 && idx <= JUMLAH_MAHASISWA) {
                int target = idx - 1;

                float nilaiAkhir = daftarMahasiswa[target].hitungNilaiAkhir(0.20, 0.30, 0.50);

                cout << "\n--- HASIL EVALUASI ---" << endl;
                cout << "Nama Mahasiswa : " << daftarMahasiswa[target].getNama() << endl;
                cout << "NIM            : " << daftarMahasiswa[target].getNim() << endl;
                cout << "Nilai Akhir    : " << nilaiAkhir << endl;

                if (nilaiAkhir >= 70.0) {
                    tampilkanStatus("STATUS: DINYATAKAN LULUS PRAKTIKUM");
                } else {
                    tampilkanStatus("STATUS: TIDAK LULUS (WAJIB REMIDI)");
                }
            } else {
                tampilkanStatus("Nomor mahasiswa tidak valid!");
            }
        }
        else if (pilihan == 2) {
            int idx;
            float nilaiBaru;
            cout << "Pilih nomor mahasiswa yang ingin diupdate (1-" << JUMLAH_MAHASISWA << "): ";
            cin >> idx;

            if (idx >= 1 && idx <= JUMLAH_MAHASISWA) {
                cout << "Masukkan Nilai Tugas Baru: ";
                cin >> nilaiBaru;
                daftarMahasiswa[idx - 1].updateNilaiTugas(nilaiBaru);
            } else {
                tampilkanStatus("Nomor mahasiswa tidak valid!");
            }
        }
        else {
            tampilkanStatus("Pilihan menu tidak valid!");
        }

        cout << "\nKembali ke menu utama? (y/n): ";
        cin >> lanjut;
    }

    tampilkanStatus("Sesi akademik selesai. Terima kasih!");
    return 0;
}
