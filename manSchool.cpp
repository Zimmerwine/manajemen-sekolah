#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Variabel global
int jumlahSiswa = 0;
int jumlahGuru = 0;

// Struct
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
    int npdn;
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

// Fungsi input data siswa
void inputSiswa() {
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

// Fungsi tampil data siswa
void tampilSiswa() {
    if (jumlahSiswa == 0) {
        cout << "Data Siswa Belum Diinput\nSilahkan Input Data Terlebih Dahulu\n";
    } else {
        cout << "\nData Siswa:\n";
        for (int i = 0; i < jumlahSiswa; i++) {
            cout << "Nama: " << sekolah.siswa[i].nama << " | No Absen: " << sekolah.siswa[i].noAbsen
                 << " | NIS: " << sekolah.siswa[i].nis << " | NISN: " << sekolah.siswa[i].nisn
                 << " | Kelas: " << sekolah.siswa[i].kelas << " | Alamat: " << sekolah.siswa[i].alamat << endl;
        }
    }
}

// Fungsi input data guru
void inputGuru() {
    cout << "Masukkan jumlah guru: ";
    cin >> jumlahGuru;
    cin.ignore();
    for (int i = 0; i < jumlahGuru; i++) {
        cout << "\nData Guru ke-" << i + 1 << ":\n";
        cout << "Nama: ";
        getline(cin, sekolah.guru[i].nama);
        cout << "NPDN: ";
        cin >> sekolah.guru[i].npdn;
        cin.ignore();
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

// Fungsi tampil data guru
void tampilGuru() {
    if (jumlahGuru == 0) {
        cout << "Data Guru Belum Diinput\nSilahkan Input Data Terlebih Dahulu\n";
    } else {
        cout << "\nData Guru:\n";
        for (int i = 0; i < jumlahGuru; i++) {
            cout << "Nama: " << sekolah.guru[i].nama << " | NPDN: " << sekolah.guru[i].npdn
                 << " | Alamat: " << sekolah.guru[i].alamat << " | Lama Mengajar: " << sekolah.guru[i].lamaMengajar << " tahun\n";
            cout << "Mata Pelajaran: ";
            for (int j = 0; j < 3; j++) {
                cout << sekolah.guru[i].mapel[j] << (j < 2 ? ", " : "");
            }
            cout << endl;
        }
    }
}

// Fungsi pencarian siswa (sentinel search)
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

// Fungsi pencarian guru (linear search)
void cariGuruLinear(int jumlahGuru, int npdn) {
    bool ditemukan = false;
    for (int i = 0; i < jumlahGuru; i++) {
        if (sekolah.guru[i].npdn == npdn) {
            cout << "\nData Guru ditemukan: " << sekolah.guru[i].npdn << " dengan nama " << sekolah.guru[i].nama << endl;
            ditemukan = true;
            break;
        }
    }
    if (!ditemukan)
        cout << "\nData Guru tidak ditemukan!" << endl;
}

// Fungsi untuk sorting data siswa
void bubbleSortSiswa() {
    for (int i = 0; i < jumlahSiswa - 1; i++) {
        for (int j = 0; j < jumlahSiswa - i - 1; j++) {
            if (sekolah.siswa[j].nis > sekolah.siswa[j + 1].nis) {
                swap(sekolah.siswa[j], sekolah.siswa[j + 1]);
            }
        }
    }
    cout << "\nData siswa telah diurutkan berdasarkan NIS (ascending).\n";
    system("pause");
}

// Menu input
void menuInput() {
    int menuInput;
    do {
        system("cls");
        cout << "+" << setw(50) << setfill('=') << "+" << endl;
        cout << "|" << setw(32) << setfill(' ') << "MENU INPUT DATA" << setw(18) << "|" << endl;
        cout << "+" << setw(50) << setfill('=') << "+" << endl;
        cout << "|Pilihan Menu : " << setw(35) << setfill(' ') << "|" << endl;
        cout << "|1. Data Siswa  " << setw(35) << setfill(' ') << "|" << endl;
        cout << "|2. Data Guru   " << setw(35) << setfill(' ') << "|" << endl;
        cout << "+" << setw(50) << setfill('=') << "+" << endl;
        cout << "Masukkan Pilihan Menu : ";cin>>menuInput;
        switch (menuInput) {
            case 1: inputSiswa(); break;
            case 2: inputGuru(); break;
            default: cout << "Input yang anda masukkan salah\n"; system("pause"); break;
        }
    } while (menuInput != 1 && menuInput != 2);
}

// Menu output
void menuOutput() {
    int menuOutput;
    do {
        system("cls");
        cout << "+" << setw(50) << setfill('=') << "+" << endl;
        cout << "|" << setw(33) << setfill(' ') << "MENU OUTPUT DATA" << setw(17) << "|" << endl;
        cout << "+" << setw(50) << setfill('=') << "+" << endl;
        cout << "|1. Data Siswa  |\n|2. Data Guru   |\n";
        cout << "+" << setw(50) << setfill('=') << "+" << endl;
        cout << "Masukkan Pilihan Menu : ";
        cin >> menuOutput;

        switch (menuOutput) {
            case 1: bubbleSortSiswa(); tampilSiswa(); break;
            case 2: tampilGuru(); break;
            default: cout << "Input yang anda masukkan salah\n"; system("pause"); break;
        }
    } while (menuOutput != 1 && menuOutput != 2);
}

// Menu cari siswa
void menuCariSiswa() {
    int inputnis;
    system("cls");
    cout << "+" << setw(50) << setfill('=') << "+" << endl;
    cout << "|" << setw(33) << setfill(' ') << "MENU PENCARIAN DATA SISWA" << setw(17) << "|" << endl;
    cout << "+" << setw(50) << setfill('=') << "+" << endl;
    cout << "Masukkan NIS Siswa : ";
    cin >> inputnis;
    cariSiswaSentinel(jumlahSiswa, inputnis);
}

// Menu cari guru
void menuCariGuru() {
    int inputnpdn;
    system("cls");
    cout << "+" << setw(50) << setfill('=') << "+" << endl;
    cout << "|" << setw(33) << setfill(' ') << "MENU PENCARIAN DATA GURU " << setw(17) << "|" << endl;
    cout << "+" << setw(50) << setfill('=') << "+" << endl;
    cout << "Masukkan NPDN Guru : ";
    cin >> inputnpdn;
    cariGuruLinear(jumlahGuru, inputnpdn);
}

// Menu cari data
void menuCari() {
    int menuCari;
    do {
        system("cls");
        cout << "+" << setw(50) << setfill('=') << "+" << endl;
        cout << "|" << setw(33) << setfill(' ') << "MENU PENCARIAN DATA" << setw(17) << "|" << endl;
        cout << "+" << setw(50) << setfill('=') << "+" << endl;
        cout << "|1. Data Siswa  |\n|2. Data Guru   |\n";
        cout << "+" << setw(50) << setfill('=') << "+" << endl;
        cout << "Masukkan Pilihan Menu : ";
        cin >> menuCari;

        switch (menuCari) {
            case 1: menuCariSiswa(); break;
            case 2: menuCariGuru(); break;
            default: cout << "Input yang anda masukkan salah\n"; system("pause"); break;
        }
    } while (menuCari != 1 && menuCari != 2);
}

// Menu utama
void mainMenu() {
    int menu;
    do {
        system("cls");
        cout << "+" << setw(50) << setfill('=') << "+" << endl;
        cout << "|" << setw(32) << setfill(' ') << "MANAJEMEN SEKOLAH" << setw(18) << "|" << endl;
        cout << "+" << setw(50) << setfill('=') << "+" << endl;
        cout << "|Pilihan Menu : " << setw(35) << setfill(' ') << "|" << endl;
        cout << "|1. Input Data  " << setw(35) << setfill(' ') << "|" << endl;
        cout << "|2. Output Data " << setw(35) << setfill(' ') << "|" << endl;
        cout << "|3. Cari Data   " << setw(35) << setfill(' ') << "|" << endl;
        cout << "+" << setw(50) << setfill('=') << "+" << endl;
        cout << "Masukkan Pilihan Menu : ";
        cin >> menu;

        switch (menu) {
            case 1: menuInput(); break;
            case 2: menuOutput(); break;
            case 3: menuCari(); break;
            default: cout << "Input yang anda masukkan salah\n"; system("pause"); break;
        }
    } while (menu != 1 && menu != 2 && menu != 3);
}

// Fungsi main
int main() {
    string kembali;
    do {
        mainMenu();
        do {
            cout << "Kembali Ke Menu?(y/n) : ";
            getline(cin >> ws, kembali);
            if (kembali != "n" && kembali != "N" && kembali != "y" && kembali != "Y") {
                cout << "Input yang anda masukkan salah\n";
                system("pause");
            }
        } while (kembali != "n" && kembali != "N" && kembali != "y" && kembali != "Y");
    } while (kembali == "y" || kembali == "Y");

    return 0;
}
