# 1. Variabel, Tipe Data, dan Array
judul = "Absen bang Absen" 
maksimal_orang = 30             
peserta_awal = ["Andi", "Budi"] 

# Function: Non-return type, Berparameter
def sapa(nama):
    print("welkam back,", nama)

# Function: Return type, Tanpa parameter
def info_aplikasi():
    return judul

class DaftarHadir:
    def __init__(self):
        self.data = [] # Array
    
    # Method: Non-return type, Berparameter
    def tambah_peserta(self, nama):
        self.data.append(nama)
        print(f"{nama} berhasil ditambahkan.")

    # Method: Non-return type, Tanpa parameter
    def kosongkan_data(self):
        self.data.clear()
        print("Data telah dikosongkan.")

    # Method: Return type, Berparameter
    def cek_peserta(self, nama):
        return nama in self.data # Mengembalikan Boolean (True/False)

    # Method: Return type, Tanpa parameter
    def jumlah_peserta(self):
        return len(self.data)    # Mengembalikan Integer

# Memanggil Function
sapa("asprak")
print("Nama Program:", info_aplikasi())
print("-" * 20)

# Memanggil Method
absen = DaftarHadir()
absen.tambah_peserta("Ragil")
absen.tambah_peserta("Hanan")

print("Jumlah Hadir:", absen.jumlah_peserta(), "orang")
print("Apakah Ragil hadir?", absen.cek_peserta("Ragil"))

