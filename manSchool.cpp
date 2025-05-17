#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;



// Struct
struct Datasiswa {
    string nama;
    string noAbsen;
    string nis;
    string nisn;
    string kelas;
    string alamat;
};

struct Dataguru {
    string nama;
    string npdn;
    string alamat;
    string lamaMengajar;
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

void writeDataSiswa(fstream &file,Datasiswa &data){
    file.open("fileSiswa.txt",ios::in|ios::out|ios::app);
    file<<data.nama<<endl;
    file<<data.nisn<<endl;
    file<<data.nis<<endl;
    file<<data.noAbsen<<endl;
    file<<data.kelas<<endl;
    file<<data.alamat<<endl;
    file.close();
}

void writeJumlahSiswa(fstream &file, int &jumlahSiswa){
    file.open("fileVariabel.txt",ios::in|ios::out);
    file<<jumlahSiswa<<endl;
    file.close();
}

int readJumlahSiswa(fstream &file){
    int counter = 0;
    file.open("fileVariabel.txt",ios::in|ios::out|ios::app);
    file>>counter;
    file.close();
    return counter;
}

// Fungsi input data siswa
void inputSiswa(fstream &fileSiswa, fstream &fileVariabel, int &jumlahSiswa) {
    int input;
    cout << "Masukkan jumlah siswa: ";
    cin >> input;
    cin.ignore();
    Datasiswa* ptrSiswa = sekolah.siswa; 
    for (int i = jumlahSiswa; i < jumlahSiswa+input; i++) {
        cout << "\nData Siswa ke-" << i + 1 << ":\n";
        cout << "Nama: ";
        getline(cin, ptrSiswa[i].nama);
        cout << "NISN: ";
        getline(cin,ptrSiswa[i].nisn);
        cout << "NIS: ";
        getline(cin,ptrSiswa[i].nis);
        cout << "No Absen: ";
        getline(cin,ptrSiswa[i].noAbsen);
        cout << "Kelas: ";
        getline(cin, ptrSiswa[i].kelas);
        cout << "Alamat: ";
        getline(cin, ptrSiswa[i].alamat);
        writeDataSiswa(fileSiswa,ptrSiswa[i]);
    }
    jumlahSiswa+=input;
    writeJumlahSiswa(fileVariabel, jumlahSiswa);
}


Datasiswa readData(fstream &file, Datasiswa buffer){
    getline(file,buffer.nama);
    getline(file,buffer.nisn);
    getline(file,buffer.nis);
    getline(file,buffer.noAbsen);
    getline(file,buffer.kelas);
    getline(file,buffer.alamat);
    return buffer;
}

// Fungsi tampil data siswa
void tampilSiswaRekursif(fstream &fileSiswa, Datasiswa* siswa, int index, int &jumlahSiswa) {
    if (index >= jumlahSiswa) return;
    if (fileSiswa.eof()) return;
        siswa[index] = readData(fileSiswa,siswa[index]);
        cout << "Nama: " << siswa[index].nama << " | No Absen: " << siswa[index].noAbsen
         << " | NIS: " << siswa[index].nis << " | NISN: " << siswa[index].nisn
         << " | Kelas: " << siswa[index].kelas << " | Alamat: " << siswa[index].alamat << endl;
    tampilSiswaRekursif(fileSiswa,siswa, index + 1, jumlahSiswa);
}

void tampilSiswa(fstream &fileSiswa,int &jumlahSiswa) {
    if (jumlahSiswa == 0) {
        cout << "Data Siswa Belum Diinput\nSilahkan Input Data Terlebih Dahulu\n";
    } else {
        cout << "\nData Siswa:\n";
        fileSiswa.open("fileSiswa.txt",ios::in);
        tampilSiswaRekursif(fileSiswa,sekolah.siswa, 0, jumlahSiswa);
        fileSiswa.close();
    }
}


// Fungsi input data guru
void inputGuru(int &jumlahGuru) {
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
void tampilGuru(int &jumlahGuru) {
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
void cariSiswaSentinel(int jumlahSiswa, string nis) {
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
void cariGuruLinear(int jumlahGuru, string npdn) {
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
void bubbleSortSiswa(int &jumlahSiswa) {
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
void menuInput(fstream &fileSiswa, fstream &fileVariabel, int &jumlahSiswa, int &jumlahGuru) {
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
            case 1: inputSiswa(fileSiswa,fileVariabel, jumlahSiswa); break;
            case 2: inputGuru(jumlahGuru); break;
            default: cout << "Input yang anda masukkan salah\n"; system("pause"); break;
        }
    } while (menuInput != 1 && menuInput != 2);
}

// Menu output
void menuOutput(fstream &fileSiswa, int &jumlahSiswa, int &jumlahGuru) {
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
            case 1: 
            // bubbleSortSiswa();
            tampilSiswa(fileSiswa,jumlahSiswa); break;
            case 2: tampilGuru(jumlahGuru); break;
            default: cout << "Input yang anda masukkan salah\n"; system("pause"); break;
        }
    } while (menuOutput != 1 && menuOutput != 2);
}

// Menu cari siswa
void menuCariSiswa(int &jumlahSiswa) {
    string inputnis;
    system("cls");
    cout << "+" << setw(50) << setfill('=') << "+" << endl;
    cout << "|" << setw(33) << setfill(' ') << "MENU PENCARIAN DATA SISWA" << setw(17) << "|" << endl;
    cout << "+" << setw(50) << setfill('=') << "+" << endl;
    cout << "Masukkan NIS Siswa : ";
    cin >> inputnis;
    cariSiswaSentinel(jumlahSiswa, inputnis);
}

// Menu cari guru
void menuCariGuru(int &jumlahGuru) {
    string inputnpdn;
    system("cls");
    cout << "+" << setw(50) << setfill('=') << "+" << endl;
    cout << "|" << setw(33) << setfill(' ') << "MENU PENCARIAN DATA GURU " << setw(17) << "|" << endl;
    cout << "+" << setw(50) << setfill('=') << "+" << endl;
    cout << "Masukkan NPDN Guru : ";
    cin >> inputnpdn;
    cariGuruLinear(jumlahGuru, inputnpdn);
}

// Menu cari data
void menuCari(int &jumlahSiswa,int &jumlahGuru) {
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
            case 1: menuCariSiswa(jumlahSiswa); break;
            case 2: menuCariGuru(jumlahGuru); break;
            default: cout << "Input yang anda masukkan salah\n"; system("pause"); break;
        }
    } while (menuCari != 1 && menuCari != 2);
}

// Menu utama
void mainMenu(fstream &fileSiswa, fstream &fileVariabel, int &jumlahSiswa, int &jumlahGuru) {
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
            case 1: menuInput(fileSiswa,fileVariabel,jumlahSiswa,jumlahGuru); break;
            case 2: menuOutput(fileSiswa,jumlahSiswa,jumlahGuru); break;
            case 3: menuCari(jumlahSiswa,jumlahGuru); break;
            default: cout << "Input yang anda masukkan salah\n"; system("pause"); break;
        }
    } while (menu != 1 && menu != 2 && menu != 3);
}

// Fungsi main
int main() {
    string kembali;
    fstream fileSiswa;
    fstream fileVariabel;
    int jumlahSiswa = readJumlahSiswa(fileVariabel);
    cout<<jumlahSiswa<<endl;
    system("pause");
    int jumlahGuru = 0;
    do {
        mainMenu(fileSiswa,fileVariabel,jumlahSiswa,jumlahGuru);
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
