def get_batas_lulus():
    return 75 # Mengembalikan nilai tetap

#
def tentukan_predikat(nilai):
  
    if nilai >= 90:
        return "Predikat A"
    elif nilai >= 75:
        return "Predikat B"
    elif nilai >= 60:
        return "Predikat C"
    else:
        return "Predikat D"

class SistemAkademik:
    def tampilkan_header(self):
        print("=== Sistem Nilai Mahasiswa Kelompok 45 ===")

    def cek_jadwal_praktikum(self, jumlah_praktikum):
    
        if jumlah_praktikum >= 4:
            print("Mahasiswa sangat sibuk dengan praktikum")
        elif jumlah_praktikum >= 2:
            print("Mahasiswa punya beberapa jadwal praktikum")
        else:
            print("Mahasiswa punya sedikit jadwal praktikum")

if __name__ == "__main__":
    akademik = SistemAkademik()
    akademik.tampilkan_header()
    nilai_Mahasiswa = 82
    jumlah_praktikum = 3
    batas_lulus = get_batas_lulus()

    print(f"Nilai Mahasiswa   : {nilai_Mahasiswa}")
    
    if nilai_Mahasiswa >= batas_lulus:
        print("Status Kelulusan : Lulus")
    else:
        print("Status Kelulusan : Tidak Lulus")
        
    hasil_predikat = tentukan_predikat(nilai_Mahasiswa)
    print(f"Hasil Predikat   : {hasil_predikat}")
    
    print("Status Jadwal    : ", end="")
    akademik.cek_jadwal_praktikum(jumlah_praktikum)

