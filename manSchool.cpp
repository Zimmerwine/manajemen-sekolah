#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
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
    string mapel;
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
    file<<data.nama << ",";
    file<<data.nisn << ",";
    file<<data.nis << ",";
    file<<data.noAbsen << ",";
    file<<data.kelas << ",";
    file<<data.alamat << endl;
}

// Fungsi input data siswa
void inputSiswa(fstream &fileSiswa, int &jumlahSiswa) {
    int input;
    cout << "Masukkan jumlah siswa: ";
    cin >> input;
    cin.ignore();
    Datasiswa* ptrSiswa = sekolah.siswa; 
    fileSiswa.open("fileSiswa.txt",ios::out|ios::app);
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
    fileSiswa.close();
}

int getJumlahSiswa(fstream &file){
    string line;
    int counter = 0;
    file.open("fileSiswa.txt",ios::in);
    while (getline(file,line))
    {
    counter++;
    }
    file.close();
    return counter;
}

Datasiswa readDataSiswa(fstream &file, Datasiswa buffer){
    string line;
    while (getline(file,line))
    {
        stringstream ss(line);
        getline(ss,buffer.nama,','); //ganti jadi output file biasa
        getline(ss,buffer.nisn,',');
        getline(ss,buffer.nis,',');
        getline(ss,buffer.noAbsen,',');
        getline(ss,buffer.kelas,',');
        getline(ss,buffer.alamat,',');
     return buffer;
    }
}

// Fungsi tampil data siswa
void tampilSiswaRekursif(fstream &fileSiswa, Datasiswa* siswa, int index, int &jumlahSiswa) {
    if (index >= jumlahSiswa) return;
    if (fileSiswa.eof()) return;
        siswa[index] = readDataSiswa(fileSiswa,siswa[index]);
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
        tampilSiswaRekursif(fileSiswa,sekolah.siswa, 0, jumlahSiswa);
    }
}

Dataguru readDataGuru(fstream &file){
        string line;
        Dataguru buffer;
        while (getline(file,line))
        {
        stringstream ss(line);
        getline(ss,buffer.nama,',');
        getline(ss,buffer.npdn,',');
        getline(ss,buffer.alamat,',');
        getline(ss,buffer.lamaMengajar,',');
        getline(ss,buffer.mapel,',');
        return buffer;
    }
}

void writeDataGuru(fstream &file, Dataguru &data){
    file<<data.nama<<",";
    file<<data.npdn<<",";
    file<<data.alamat<<",";
    file<<data.lamaMengajar<<",";
    file<<data.mapel<<endl;
}

// Fungsi input data guru
void inputGuru(fstream &fileGuru,int &jumlahGuru) {
    int input;
    cout << "Masukkan jumlah guru: ";
    cin >> input;
    cin.ignore();
    fileGuru.open("fileGuru.txt",ios::out|ios::app);
    for (int i = jumlahGuru; i < jumlahGuru+input; i++) {
        cout << "\nData Guru ke-" << i + 1 << ":\n";
        cout << "Nama: ";
        getline(cin, sekolah.guru[i].nama);
        cout << "NPDN: ";
        getline(cin>>ws,sekolah.guru[i].npdn);
        cout << "Alamat: ";
        getline(cin, sekolah.guru[i].alamat);
        cout << "Lama Mengajar (tahun): ";
        getline(cin>>ws,sekolah.guru[i].lamaMengajar);
        cout << "Mata Pelajaran : ";
        getline(cin, sekolah.guru[i].mapel);
        writeDataGuru(fileGuru,sekolah.guru[i]);
    }
    fileGuru.close();
}

int getJumlahGuru(fstream &file){
    string line;
    int counter = 0;
    file.open("fileGuru.txt",ios::in);
    while (getline(file,line))
    {
    counter++;
    }
    file.close();
    return counter;
}
// Fungsi tampil data guru
void tampilGuru(fstream &fileGuru, int &jumlahGuru) {
    Dataguru output;
    if (jumlahGuru == 0) {
        cout << "Data Guru Belum Diinput\nSilahkan Input Data Terlebih Dahulu\n";
    } else {
        cout << "\nData Guru:\n";
        for (int i = 0; i < jumlahGuru; i++)
        {
            output = readDataGuru(fileGuru);
            cout<<"Nama : "<<output.nama
                <<" Npdn : "<<output.npdn
                <<" Alamat : "<<output.alamat
                <<" Lama Mengajar : "<<output.lamaMengajar<<" Tahun"
                <<" Mata Pelajaran : "<<output.mapel<<endl;
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
void menuInput(fstream &fileSiswa,fstream &fileGuru,int &jumlahSiswa, int &jumlahGuru) {
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
        if (menuInput != 1 && menuInput != 2)
        {
          cout<<"Invalid Input"<<endl;
          system("pause");
        }
        switch (menuInput) {
            case 1: inputSiswa(fileSiswa, jumlahSiswa); break;
            case 2: inputGuru(fileGuru,jumlahGuru); break;
        }
    } while (menuInput != 1 && menuInput != 2);
}

// Menu output
void menuOutput(fstream &fileSiswa,fstream &fileGuru,int &jumlahSiswa, int &jumlahGuru) {
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
        if (menuOutput != 1 && menuOutput != 2 )
        {
            cout<<"Invalid Input"<<endl;
            system("pause");
        }
        switch (menuOutput) {
            case 1: 
            // bubbleSortSiswa();
            fileSiswa.open("fileSiswa.txt",ios::in);
            tampilSiswa(fileSiswa,jumlahSiswa);
            fileSiswa.close();
            break;
            case 2: 
            fileGuru.open("fileGuru.txt",ios::in);
            tampilGuru(fileGuru,jumlahGuru);
            fileGuru.close();
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
void mainMenu(fstream &fileSiswa,fstream &fileGuru,int &jumlahSiswa, int &jumlahGuru) {
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
        cout << "|4. Keluar   " << setw(35) << setfill(' ') << "|" << endl;
        cout << "+" << setw(50) << setfill('=') << "+" << endl;
        cout << "Masukkan Pilihan Menu : ";
        cin >> menu;
        switch (menu) {
            case 1: menuInput(fileSiswa,fileGuru, jumlahSiswa, jumlahGuru); break;
            case 2: menuOutput(fileSiswa,fileGuru, jumlahSiswa, jumlahGuru); break;
            // case 3: menuCari(); break;
            case 4: cout << "Keluar dari program" << endl; exit(0);
            default: cout << "Input yang anda masukkan salah\n"; system("pause"); break;
        }
    } while (menu != 1 && menu != 2 && menu != 3);
}

// Fungsi main
int main() {
    string kembali;
    fstream fileSiswa;
    fstream fileGuru;
    do {
        int jumlahSiswa = getJumlahSiswa(fileSiswa);
        int jumlahGuru = getJumlahGuru(fileGuru);
        mainMenu(fileSiswa,fileGuru, jumlahSiswa, jumlahGuru);
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
