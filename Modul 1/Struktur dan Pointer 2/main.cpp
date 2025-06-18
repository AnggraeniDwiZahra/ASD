#include <iostream>
#include <string>

using namespace std;

int main()
{
    struct {
        string platNomorKendaraan;
        string jenisKendaraan;
        string namaPemilik;
        string alamat;
        string kota;
    } kendaraan;

    kendaraan.platNomorKendaraan = "DA123MK";
    kendaraan.jenisKendaraan = "RUSH";
    kendaraan.namaPemilik = "Andika Hartanto";
    kendaraan.alamat = "jl. Kayu Tangi 1";
    kendaraan.kota = "Banjarmasin";

    cout << "Plat Nomor Kendaraan : " << kendaraan.platNomorKendaraan << endl;
    cout << "Jenis Kendaraan : " << kendaraan.jenisKendaraan << endl;
    cout << "Nama Kendaraan : " << kendaraan.namaPemilik << endl;
    cout << "Alamat : " << kendaraan.alamat << endl;
    cout << "Kota : " << kendaraan.kota << endl;

    return 0;
}
