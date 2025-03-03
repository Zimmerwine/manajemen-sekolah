#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Datasiswa {
    string nama;
    int noAbsen;
    int nis;
    int nisn;
    string kelas;
    string alamat;
};

struct Dataguru {
    string nama;
    string npdn;
    string alamat;
    int lamaMengajar;
    string mapel[5];
};

struct Kelas {
    string namaKelas;
    int jumlahSiswa;
    Dataguru waliKelas;
    Datasiswa siswa[50];
};

struct Sekolah {
    Dataguru guru[10];
    Datasiswa siswa[100];
    Kelas kelas[5];
};

Sekolah sekolah;

void inputSiswa(int &jumlahSiswa) {
    cout << "Masukkan jumlah siswa: ";
    cin >> jumlahSiswa;
    cin.ignore();
    for (int i = 0; i < jumlahSiswa; i++) {
        cout << "\nData Siswa ke-" << i + 1 << ":\n";
        cout << "Nama: ";
        getline(cin, sekolah.siswa[i].nama);
        cout << "No Absen: ";
        cin >> sekolah.siswa[i].noAbsen;
        cout << "NIS: ";
        cin >> sekolah.siswa[i].nis;
        cout << "NISN: ";
        cin >> sekolah.siswa[i].nisn;
        cin.ignore();
        cout << "Kelas: ";
        getline(cin, sekolah.siswa[i].kelas);
        cout << "Alamat: ";
        getline(cin, sekolah.siswa[i].alamat);
    }
}

void tampilSiswa(int jumlahSiswa) {
    cout << "\nData Siswa:\n";
    for (int i = 0; i < jumlahSiswa; i++) {
        cout << "Nama: " << sekolah.siswa[i].nama << " | No Absen: " << sekolah.siswa[i].noAbsen
             << " | NIS: " << sekolah.siswa[i].nis << " | NISN: " << sekolah.siswa[i].nisn
             << " | Kelas: " << sekolah.siswa[i].kelas << " | Alamat: " << sekolah.siswa[i].alamat << endl;
    }
}

void inputGuru(int &jumlahGuru) {
    cout << "Masukkan jumlah guru: ";
    cin >> jumlahGuru;
    cin.ignore();
    for (int i = 0; i < jumlahGuru; i++) {
        cout << "\nData Guru ke-" << i + 1 << ":\n";
        cout << "Nama: ";
        getline(cin, sekolah.guru[i].nama);
        cout << "NPDN: ";
        getline(cin, sekolah.guru[i].npdn);
        cout << "Alamat: ";
        getline(cin, sekolah.guru[i].alamat);
        cout << "Lama Mengajar (tahun): ";
        cin >> sekolah.guru[i].lamaMengajar;
        cin.ignore();
        for (int j = 0; j < 3; j++) {
            cout << "Mata Pelajaran " << j + 1 << ": ";
            getline(cin, sekolah.guru[i].mapel[j]);
        }
    }
}

void tampilGuru(int jumlahGuru) {
    cout << "\nData Guru:\n";
    for (int i = 0; i < jumlahGuru; i++) {
        cout << "Nama: " << sekolah.guru[i].nama << " | NPDN: " << sekolah.guru[i].npdn
             << " | Alamat: " << sekolah.guru[i].alamat << " | Lama Mengajar: " << sekolah.guru[i].lamaMengajar << " tahun" << endl;
        cout << "Mata Pelajaran: ";
        for (int j = 0; j < 3; j++) {
            cout << sekolah.guru[i].mapel[j] << (j < 2 ? ", " : "");
        }
        cout << endl;
    }
}

void cariSiswaSentinel(int jumlahSiswa, int nis) {
    sekolah.siswa[jumlahSiswa].nis = nis; 
    int i = 0;
    while (sekolah.siswa[i].nis != nis) {
        i++;
    }
    if (i < jumlahSiswa)
        cout << "\nData Siswa ditemukan: " << sekolah.siswa[i].nama << " dari kelas " << sekolah.siswa[i].kelas << endl;
    else
        cout << "\nData Siswa tidak ditemukan!" << endl;
}

void cariSiswaLinear(int jumlahSiswa, int nis) {
    bool ditemukan = false;
    for (int i = 0; i < jumlahSiswa; i++) {
        if (sekolah.siswa[i].nis == nis) {
            cout << "\nData Siswa ditemukan: " << sekolah.siswa[i].nama << " dari kelas " << sekolah.siswa[i].kelas << endl;
            ditemukan = true;
            break;
        }
    }
    if (!ditemukan)
        cout << "\nData Siswa tidak ditemukan!" << endl;
}

int main() {
    int jumlahSiswa, jumlahGuru;
    inputSiswa(jumlahSiswa);
    tampilSiswa(jumlahSiswa);
    
    inputGuru(jumlahGuru);
    tampilGuru(jumlahGuru);
    
    int nis;
    cout << "\nMasukkan NIS untuk pencarian (Sentinel): ";
    cin >> nis;
    cariSiswaSentinel(jumlahSiswa, nis);
    
    cout << "\nMasukkan NIS untuk pencarian (Linear): ";
    cin >> nis;
    cariSiswaLinear(jumlahSiswa, nis);
    
    return 0;
}
